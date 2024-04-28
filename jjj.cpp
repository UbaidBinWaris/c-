#include<iostream>
#include<stack>
using namespace std;

class Student {
public:
    int rollno;
    string name;
    string Class;
    stack<bool> attendance; // Stack to store attendance (true for present, false for absent)
};

class Node {
public:
    Student record;
    Node* next;
    Node* prev;

    Node() {
        next = nullptr;
        prev = nullptr;
    }
};

class List {
public:
    Node* head;

    List() {
        head = nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->record.name << endl;
            cout << "Roll no.: " << temp->record.rollno << endl;
            cout << "Class: " << temp->record.Class << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(Student s) {
        Node* temp = new Node;
        temp->record = s;
        temp->next = nullptr;
        temp->prev = nullptr;
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node* temp1 = head;
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }

    void deleteNode(int rollno) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        if (head->record.rollno == rollno) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->record.rollno == rollno) {
                Node* temp1 = temp->next;
                temp->next = temp1->next;
                if (temp1->next != nullptr) {
                    temp1->next->prev = temp;
                }
                delete temp1;
                cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->record.rollno == rollno) {
            temp->prev->next = nullptr;
            delete temp;
            cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
            return;
        }
        cout << "Roll no. not found" << endl;
    }

    void takeAttendance() {
        cout << "Taking Attendance..." << endl;
        Node* temp = head;
        while (temp != nullptr) {
            bool present;
            cout << "Is " << temp->record.name << " present? (1 for present, 0 for absent): ";
            cin >> present;
            temp->record.attendance.push(present);
            temp = temp->next;
        }
    }

void checkAttendance() {
    cout << "Checking Attendance..." << endl;
    Node* temp = head;
    int count = 0; // Counter for absent students
    while (temp != nullptr) {
        if (!temp->record.attendance.empty() && !temp->record.attendance.top()) {
            count++;
        }
        temp = temp->next;
    }
    if (count > 6) {
        cout << "Short attendance detected! " << count << " students are absent." << endl;
    }
    else {
        cout << "No short attendance detected." << endl;
    }
}
};

void menu() 
{
    cout << "Student Management Record" << endl << endl;
    cout << " 1. Add student" << endl;
    cout << " 2. Delete student" << endl;
    cout << " 3. Display student" << endl;
    cout << " 4. Take attendance" << endl;
    cout << " 5. Check attendance" << endl;
    cout << " 6. Exit" << endl;
}

int main() {
    List l;
    bool run = true;
    char option;

    do {
        menu();
        cout << "Please enter your choice: ";
        cin >> option;

        switch (option) {
        case '1': {
            Student s;
            cout << "Enter name: ";
            cin >> s.name;
            cout << "Enter roll no.: ";
            cin >> s.rollno;
            cout << "Enter class: ";
            cin >> s.Class;
            l.insert(s);
            break;
        }
        case '2': {
            int rollno;
            cout << "Enter roll no.: ";
            cin >> rollno;
            l.deleteNode(rollno);
            break;
        }
        case '3': {
            l.display();
            break;
        }
        case '4': {
            l.takeAttendance();
            break;
        }
        case '5': {
            l.checkAttendance();
            break;
        }
        case '6': {
            run = false;
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (run);

    //return 0;
}
