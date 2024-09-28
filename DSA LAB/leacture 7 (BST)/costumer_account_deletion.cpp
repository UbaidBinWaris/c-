#include<iostream>
using namespace std;

class employee {
public:
    string name;
    int id;

    employee() {
        name = "null";
        id = 0;
    }
    employee(string n, int i) {
        name = n;
        id = i;
    }
    void set_data() {
        cout << "Enter Employee name: ";
        cin >> name;
        cout << "Enter its id: ";
        cin >> id;
    }
    void display() {
        cout << "Name\t: " << name << endl;
        cout << "id\t: " << id << endl;
        cout << "----------------------------------------" << endl;
    }
};

class node {
public:
    employee e;
    node* left;
    node* right;

    node() {
        left = nullptr;
        right = nullptr;
        e.id = 0;
        e.name = "";
    }
};

class BST {
private:
    node* in(node* temp, employee e) {
        if (temp == nullptr) {
            node* newnode = new node;
            newnode->e = e;
            return newnode;
        } else if (temp->e.id > e.id) {
            temp->left = in(temp->left, e);
        } else if (temp->e.id < e.id) {
            temp->right = in(temp->right, e);
        }
        return temp;
    }

    void dis(node* temp) {
        if (temp != nullptr) {
            dis(temp->left);
            temp->e.display();
            dis(temp->right);
        }
    }

    node* minValueNode(node* temp) {
        node* current = temp;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    node* deleteNode(node* temp, int id) {
        if (temp == nullptr)
            return temp;

        if (id < temp->e.id)
            temp->left = deleteNode(temp->left, id);
        else if (id > temp->e.id)
            temp->right = deleteNode(temp->right, id);
        else {
            if (temp->left == nullptr) {
                node* tempRight = temp->right;
                delete temp;
                return tempRight;
            } else if (temp->right == nullptr) {
                node* tempLeft = temp->left;
                delete temp;
                return tempLeft;
            }

            node* tempMin = minValueNode(temp->right);
            temp->e = tempMin->e;
            temp->right = deleteNode(temp->right, tempMin->e.id);
        }
        return temp;
    }

public:
    node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        employee e;
        e.set_data();
        root = in(root, e);
    }

    void insert(string n, int i) {
        employee e(n, i);
        root = in(root, e);
    }

    void display() {
        cout << "\n\t\tEmployee database" << endl << endl;
        node* temp = root;
        dis(temp);
    }

    void deleteAccount(int id) {
        root = deleteNode(root, id);
    }
};

int main() {
    BST b;
    b.insert("Ali", 123);
    b.insert("Afaq", 664);
    b.insert("Haider", 524);
    b.insert("Ubaid", 333);
    b.insert("Jibran", 243);

    cout << "Initial database:" << endl;
    b.display();

    cout << "\nDeleting account with id 333" << endl;
    b.deleteAccount(333);
    b.display();

    cout << "\nDeleting account with id 123" << endl;
    b.deleteAccount(123);
    b.display();

    cout << "\nDeleting account with id 524" << endl;
    b.deleteAccount(524);
    b.display();
    
    return 0;
}
