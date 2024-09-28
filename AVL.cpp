#include<iostream>
using namespace std;
class node
{
public:
	int key;
	int height;
	node* left;
	node* right;

	node()
	{
		height = 0;
		key = 0;
		left = NULL;
		right = NULL;
	}
};
int max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}
class AVL
{
	node* create_node(int k)
	{
		node* newnode = new node;
		newnode->key = k;
		return newnode;
	}
	int get_height(node* temp)
	{
		if (temp == NULL)
			return 0;
		return temp->height;
	}
	int balance(node* temp)
	{
		if (temp == NULL)
			return 0;
		return get_height(temp->left) - get_height(temp->right);
	}
	node* in(node* temp, int k)
	{
		if (temp == NULL)
			return create_node(k);
		if (temp->key > k)
			temp->left = in(temp->left, k);
		else
			temp->right = in(temp->right, k);

		temp->height = max(get_height(temp->left), get_height(temp->right)) + 1;
		int bf = balance(temp);


		if (bf > 1)
		{
			if (k < temp->key)
				return RR_rotate(temp);
			else
			{
				temp->left = LL_rotate(temp->left);
				return RR_rotate(temp);
			}

		}
		else if (bf < -1)
		{
			if (k < temp->key)
				return LL_rotate(temp);
			else
			{
				temp->right = RR_rotate(temp);
				return LL_rotate(temp);
			}
		}
		return temp;
	}
	node* LL_rotate(node* x)
	{
		node* y = x->right;
		node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(get_height(x->right), get_height(x->left)) + 1;
		y->height = max(get_height(y->right), get_height(y->left)) + 1;

		return y;
	}
	node* RR_rotate(node* y)
	{
		node* x = y->left;
		node* T2 = x->right;

		x->right = y;
		y->left = T2;

		x->height = max(get_height(x->right), get_height(x->left)) + 1;
		y->height = max(get_height(y->right), get_height(y->left)) + 1;

		return x;
	}

public:
	node* root;

	AVL()
	{
		root = NULL;
	}

	void insert(int k)
	{
		root = in(root, k);
	}
};
int main()
{
	AVL a;
	a.insert(50);
	a.insert(20);
	a.insert(10);
	a.insert(5);
}