#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string patientID;
    string name;
    int age;
    string disease;

    Patient() {
        patientID = "null";
        name = "null";
        age = 0;
        disease = "null";
    }

    Patient(string id, string n, int a, string d) {
        patientID = id;
        name = n;
        age = a;
        disease = d;
    }

    void set_data() {
        cout << "Enter patient ID: ";
        cin >> patientID;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter disease: ";
        cin.ignore();
        getline(cin, disease);
    }

    void display() {
        cout << "Patient ID   : " << patientID << endl;
        cout << "Name         : " << name << endl;
        cout << "Age          : " << age << endl;
        cout << "Disease      : " << disease << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    Patient patient;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* insert(Node* temp, Patient patient) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->patient = patient;
            return newnode;
        }
        else if (patient.patientID < temp->patient.patientID) {
            temp->left = insert(temp->left, patient);
        }
        else if (patient.patientID > temp->patient.patientID) {
            temp->right = insert(temp->right, patient);
        }
        return temp;
    }

    Node* search(Node* temp, string patientID) {
        if (temp == nullptr || temp->patient.patientID == patientID) {
            return temp;
        }
        else if (patientID < temp->patient.patientID) {
            return search(temp->left, patientID);
        }
        else {
            return search(temp->right, patientID);
        }
    }

    void display(Node* temp) {
        if (temp != nullptr) {
            display(temp->left);
            temp->patient.display();
            display(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        Patient patient;
        patient.set_data();
        root = insert(root, patient);
    }

    void insert(string patientID, string name, int age, string disease) {
        Patient patient(patientID, name, age, disease);
        root = insert(root, patient);
    }

    void display() {
        cout << "\n\t\tPatient Records" << endl << endl;
        display(root);
    }

    void found(string patientID) {
        Node* result = search(root, patientID);
        if (result == nullptr) {
            cout << "Patient with ID " << patientID << " not found." << endl;
        } else {
            cout << "\t\tPatient found" << endl;
            result->patient.display();
        }
    }
};

int main() {
    BST medicalRecords;

    medicalRecords.insert("P001", "Baber", 30, "Flu");
    medicalRecords.insert("P002", "Shadab", 45, "Diabetes");
    medicalRecords.insert("P003", "Azam", 25, "Asthma");
    medicalRecords.insert("P004", "Hassan", 60, "Hypertension");
    medicalRecords.insert("P005", "Wasim", 50, "Arthritis");

    medicalRecords.display();

    string patientID;
    cout << "\nEnter patient ID to search: ";
    cin >> patientID;
    medicalRecords.found(patientID);

    return 0;
}
