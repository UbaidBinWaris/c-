#include<iostream>
using namespace std;
class employee
{
public:
	string name;
	int id;

	employee()
	{
		name = "null";
		id = 0;
	}
	employee(string n, int i)
	{
		name = n;
		id = i;
	}
	void set_data()
	{
		cout << "Enter Employee name : ";
		cin >> name;
		cout << "Enter its id : ";
		cin >> id;
	}
	void display()
	{
		cout << "Name	: " << name << endl;
		cout << "id	: " << id << endl;
		cout << "----------------------------------------" << endl;
	}
};
class node
{
public:
	employee e;
	node* left;
	node* right;

	node()
	{
		left = nullptr;
		right = nullptr;
		e.id = 0;
		e.name = "";
	}
};
class BST
{
private:
	node* in(node* temp, employee e)
	{
		if (temp == nullptr)
		{
			node* newnode = new node;
			newnode->e = e;
			return newnode;
		}
		else if (temp->e.id > e.id)
		{
			temp->left = in(temp->left, e);
		}
		else if (temp->e.id < e.id)
		{
			temp->right = in(temp->right, e);
		}
		return temp;
	}
	void dis(node* temp)
	{
		if (temp != nullptr)
		{
			dis(temp->left);
			temp->e.display();
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
		employee e;
		e.set_data();
		root = in(root, e);
	}
	void insert(string n , int i)
	{
		employee e(n, i);
		root = in(root, e);
	}
	void display()
	{
		cout << "\n\t\tEmployee database" << endl << endl;
		node* temp = root;
		dis(temp);
	}
};

int main()
{
	BST b;
	b.insert("Ali",123);
	b.insert("Afaq",664);
	b.insert("Haider",524);
	b.insert("Ubaid",333);
	b.insert("Jibran",243);

	b.display();
}