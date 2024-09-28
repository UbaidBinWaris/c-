#include <iostream>
using namespace std;

class Contact
{
public:
    string name;
    int phone;

    Contact()
    {
        name = "null";
        phone = 0;
    }
    Contact(string n, int p)
    {
        name = n;
        phone = p;
    }
    void set_data()
    {
        cout << "Enter contact name: ";
        cin >> name;
        cout << "Enter 4-digit phone number: ";
        cin >> phone;
        while(phone < 1000 || phone > 9999) {
            cout << "Invalid phone number. Please enter a 4-digit phone number: ";
            cin >> phone;
        }
    }
    void display()
    {
        cout << "Contact Name  : " << name << endl;
        cout << "Phone Number  : " << phone << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node
{
public:
    Contact c;
    Node* left;
    Node* right;

    Node()
    {
        left = nullptr;
        right = nullptr;
        c.phone = 0;
        c.name = "";
    }
};

class BST
{
private:
    Node* in(Node* temp, Contact c)
    {
        if (temp == nullptr)
        {
            Node* newnode = new Node;
            newnode->c = c;
            return newnode;
        }
        else if (temp->c.phone > c.phone)
        {
            temp->left = in(temp->left, c);
        }
        else if (temp->c.phone < c.phone)
        {
            temp->right = in(temp->right, c);
        }
        return temp;
    }

    void dis(Node* temp)
    {
        if (temp != nullptr)
        {
            dis(temp->left);
            temp->c.display();
            dis(temp->right);
        }
    }

public:
    Node* root;

    BST()
    {
        root = nullptr;
    }

    void insert()
    {
        Contact c;
        c.set_data();
        root = in(root, c);
    }

    void insert(string n, int p)
    {
        Contact c(n, p);
        root = in(root, c);
    }

    void display()
    {
        cout << "\n\t\tAddress Book" << endl << endl;
        Node* temp = root;
        dis(temp);
    }
};

int main()
{
    BST b;
    b.insert("computer", 1234);
    b.insert("Bob", 2345);
    b.insert("Charlie", 3456);
    b.insert("Daisy", 4567);
    b.insert("Eve", 5678);

    b.display();
}
