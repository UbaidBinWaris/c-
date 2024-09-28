#include<iostream>
using namespace std;

class student
{
public:
    string name;
    int id;

    student()
    {
        name = "null";
        id = 0;
    }
    student(string n, int i)
    {
        name = n;
        id = i;
    }
    void set_data()
    {
        cout << "Enter student name : ";
        cin >> name;
        cout << "Enter student id : ";
        cin >> id;
    }
    void display()
    {
        cout << "Student Name    : " << name << endl;
        cout << "Student ID      : " << id << endl;
        cout << "----------------------------------------" << endl;
    }
};

class node
{
public:
    student s;
    node* left;
    node* right;

    node()
    {
        left = nullptr;
        right = nullptr;
        s.id = 0;
        s.name = "";
    }
};

class BST
{
private:
    node* in(node* temp, student s)
    {
        if (temp == nullptr)
        {
            node* newnode = new node;
            newnode->s = s;
            return newnode;
        }
        else if (temp->s.id > s.id)
        {
            temp->left = in(temp->left, s);
        }
        else if (temp->s.id < s.id)
        {
            temp->right = in(temp->right, s);
        }
        return temp;
    }

    void dis(node* temp)
    {
        if (temp != nullptr)
        {
            dis(temp->left);
            temp->s.display();
            dis(temp->right);
        }
    }

public:
    node* root;

    BST()
    {
        root = nullptr;
    }

    void insert()
    {
        student s;
        s.set_data();
        root = in(root, s);
    }

    void insert(string n, int i)
    {
        student s(n, i);
        root = in(root, s);
    }

    void display()
    {
        cout << "\n\t\tStudent Details" << endl << endl;
        node* temp = root;
        dis(temp);
    }
};

int main()
{
    BST b;
    b.insert();
    b.insert();
    b.insert();
    b.insert();

    b.display();
}
