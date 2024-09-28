#include<iostream>
using namespace std;

class Node {
public:

	Node* left;
	Node* right;
	int d;

	Node()
	{
		d = 'x';
		left = NULL;
		right = NULL;

	}
};
class BST
{
public:
	Node* root;

	BST()
	{
		root = NULL;
	}
	void insert(int ch)
	{
		Node* newnode = new Node;
		newnode->d = ch;
		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
		{
			root = newnode;
			return;
		}

		Node* temp = root;
		Node* parent = NULL;

		while (temp != NULL)
		{
			parent = temp;
			if (temp->d > ch)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}

		if (parent->d > ch)
		{
			parent->left = newnode;
		}
		else
		{
			parent->right = newnode;
		}
	}

	void serach(int key)
	{
		if (root == nullptr)
		{
			return;
		}
		Node* temp = root;
		while (temp != nullptr)
		{
			if (temp->d == key)
			{
				cout << "Key found" << endl;
				return;
			}
			else if (temp->d > key)
			{
				temp = temp->left;
			}
			else if (temp->d < key)
			{
				temp = temp->right;
			}
		}
		cout << "Key naot found" << endl;
		return;
	}

	void del(int key)
	{
		if (root == NULL)
		{
			cout << "could not delete" << endl;
			return;
		}
		

		Node* temp = root;
		Node* parent = root;

		if (root->d == key)
		{
			temp = root->left;
			while (temp->right != NULL)
			{
				parent = temp;
				temp = temp->right;
			}
			swap(temp->d, root->d);
			parent->right = NULL;
			return;

		}

		while (temp != NULL)
		{
			if (temp->d == key)
			{
				delee(parent, temp, key);
				return;
			}
			parent = temp;
			if (temp->d > key)
			{
				temp = temp->left;
			}
			else if (temp->d < key)
			{
				temp = temp->right;
			}
		}
	}
	void delee(Node* parent, Node* temp, int key)
	{
		if (parent == temp && parent == root)
		{
			delete root;
			delete temp;
			delete parent;
			return;
		}
		if (temp->left == NULL && temp->right == NULL)
		{
			if (parent->right == temp)
			{
				parent->right = NULL;
			}
			else
			{
				parent->left = NULL;
			}
			delete temp;
			return;
		}
		if (temp->right == nullptr)
		{
			temp = temp->left;
			return;
		}
		if (temp->right == NULL)
		{
			temp = temp->left;
			return;
		}

		Node* another = temp->right;
		Node* replace = temp->left;
		parent = temp;
		while (replace->right != NULL)
		{
			parent = replace;
			replace = replace->right;
		}
		swap(temp->d, replace->d);

		parent->right = NULL;
	}

};

void inorder_display(Node* temp)
{
	if (temp != NULL)
	{
		inorder_display(temp->left);
		cout << temp->d << " , ";
		inorder_display(temp->right);

	}
}

int main()
{
	BST b;
	b.insert(100);
	b.insert(50);
	b.insert(200);
	b.insert(25);
	b.insert(75);
	b.insert(150);
	b.insert(250);
	b.insert(10);
	b.insert(30);
	b.insert(60);
	b.insert(80);
	b.insert(120);
	b.insert(170);
	b.insert(220);
	b.insert(260);

	//b.serach(10);
	//b.serach(20);
	//b.serach(30);
	//b.serach(40);


	inorder_display(b.root);

	b.del(50);
	cout << "\n";
	inorder_display(b.root);

	return 0;
}