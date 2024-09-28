#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int employeeID;
    string name;
    string department;
    double salary;

    Employee() {
        employeeID = 0;
        name = "null";
        department = "null";
        salary = 0.0;
    }

    Employee(int id, string n, string d, double s) {
        employeeID = id;
        name = n;
        department = d;
        salary = s;
    }

    void set_data() {
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() {
        cout << "Employee ID    : " << employeeID << endl;
        cout << "Name           : " << name << endl;
        cout << "Department     : " << department << endl;
        cout << "Salary         : " << salary << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    Employee employee;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* insert(Node* temp, Employee employee) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->employee = employee;
            return newnode;
        }
        else if (employee.employeeID < temp->employee.employeeID) {
            temp->left = insert(temp->left, employee);
        }
        else if (employee.employeeID > temp->employee.employeeID) {
            temp->right = insert(temp->right, employee);
        }
        return temp;
    }

    Node* search(Node* temp, int employeeID) {
        if (temp == nullptr || temp->employee.employeeID == employeeID) {
            return temp;
        }
        else if (employeeID < temp->employee.employeeID) {
            return search(temp->left, employeeID);
        }
        else {
            return search(temp->right, employeeID);
        }
    }

    void display(Node* temp) {
        if (temp != nullptr) {
            display(temp->left);
            temp->employee.display();
            display(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        Employee employee;
        employee.set_data();
        root = insert(root, employee);
    }

    void insert(int employeeID, string name, string department, double salary) {
        Employee employee(employeeID, name, department, salary);
        root = insert(root, employee);
    }

    void display() {
        cout << "\n\t\tEmployee Directory" << endl << endl;
        display(root);
    }

    void found(int employeeID) {
        Node* result = search(root, employeeID);
        if (result == nullptr) {
            cout << "Employee with ID " << employeeID << " not found." << endl;
        } else {
            cout << "\t\tEmployee found" << endl;
            result->employee.display();
        }
    }
};

int main() {
    BST employee;

    employee.insert(1001, "Waqqar", "HR", 50000);
    employee.insert(1002, "Yonis", "IT", 60000);
    employee.insert(1003, "Ubaid", "Finance", 55000);
    employee.insert(1004, "Moiz", "Marketing", 52000);
    employee.insert(1005, "Zaid", "Sales", 58000);

    employee.display();

    int employeeID;
    cout << "\nEnter employee ID to search: ";
    cin >> employeeID;
    employee.found(employeeID);

    return 0;
}
