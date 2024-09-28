#include <iostream>
using namespace std;

class Contact {
public:
    string name;
    int phone;

    Contact() {
        name = "null";
        phone = 0;
    }

    Contact(string n, int p) {
        name = n;
        phone = p;
    }

    void set_data() {
        cout << "Enter contact name: ";
        cin >> name;
        cout << "Enter 4-digit phone number: ";
        cin >> phone;
        while(phone < 1000 || phone > 9999) {
            cout << "Invalid phone number. Please enter a 4-digit phone number: ";
            cin >> phone;
        }
    }

    void display() {
        cout << "Contact Name  : " << name << endl;
        cout << "Phone Number  : " << phone << endl;
    }
};

class BankAccount {
public:
    int accountNumber;
    double balance;
    Contact contact;

    BankAccount() {
        accountNumber = 0;
        balance = 0.0;
    }

    BankAccount(int accNum, double bal, Contact cont) {
        accountNumber = accNum;
        balance = bal;
        contact = cont;
    }

    void set_data() {
        contact.set_data();
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance       : " << balance << " Rs." << endl;
        contact.display();
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    BankAccount account;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* in(Node* temp, BankAccount account) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->account = account;
            return newnode;
        }
        else if (temp->account.accountNumber > account.accountNumber) {
            temp->left = in(temp->left, account);
        }
        else if (temp->account.accountNumber < account.accountNumber) {
            temp->right = in(temp->right, account);
        }
        return temp;
    }

    void dis(Node* temp) {
        if (temp != nullptr) {
            dis(temp->left);
            temp->account.display();
            dis(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        BankAccount account;
        account.set_data();
        root = in(root, account);
    }

    void insert(int accNum, double bal, Contact cont) {
        BankAccount account(accNum, bal, cont);
        root = in(root, account);
    }

    void display() {
        cout << "\n\t\tBank Account Details" << endl << endl;
        Node* temp = root;
        dis(temp);
    }
};

int main() {
    BST b;
    b.insert(1234, 1000.0, Contact("Basheer", 2345));
    b.insert(2345, 1500.0, Contact("Haider", 3456));
    b.insert(3456, 2000.0, Contact("ALI", 4567));
    b.insert(4567, 2500.0, Contact("Ghulam", 5678));
    b.insert(5678, 3000.0, Contact("Mola", 6789));

    b.display();

    return 0;
}
