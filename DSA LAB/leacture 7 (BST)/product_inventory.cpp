#include<iostream>
using namespace std;
class product
{
public:
	string name;
	int id;

	product()
	{
		name = "null";
		id = 0;
	}
	product(string n, int i)
	{
		name = n;
		id = i;
	}
	void set_data()
	{
		cout << "Enter product name : ";
		cin >> name;
		cout << "Enter its id : ";
		cin >> id;
	}
	void display()
	{
		cout << "Product Name	: " << name << endl;
		cout << "Product id	: " << id << endl;
		cout << "----------------------------------------" << endl;
	}
};
class node
{
public:
	product p;
	node* left;
	node* right;

	node()
	{
		left = nullptr;
		right = nullptr;
		p.id = 0;
		p.name = "";
	}
};
class BST
{
private:
	node* in(node* temp, product p)
	{
		if (temp == nullptr)
		{
			node* newnode = new node;
			newnode->p = p;
			return newnode;
		}
		else if (temp->p.id > p.id)
		{
			temp->left = in(temp->left, p);
		}
		else if (temp->p.id < p.id)
		{
			temp->right = in(temp->right, p);
		}
		return temp;
	}
	void dis(node* temp)
	{
		if (temp != nullptr)
		{
			dis(temp->left);
			temp->p.display();
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
		product p;
		p.set_data();
		root = in(root, p);
	}
	void insert(string n , int i)
	{
		product p(n, i);
		root = in(root, p);
	}
	void display()
	{
		cout << "\n\t\tproduct Datailes" << endl << endl;
		node* temp = root;
		dis(temp);
	}
};

int main()
{
	BST b;
	b.insert("Weat",9000);
	b.insert("Grocary",12000);
	b.insert("Makeup",10000);
	b.insert("Jewlary",18000);
	b.insert("bread",200);

	b.display();
}