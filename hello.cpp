#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Function to delete a node in BST
Node* deleteNode(Node* root, int key) {
    // Base case: if the tree is empty
    if (root == nullptr)
        return root;

    // Recursively find the node to be deleted in the left or right subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Utility function to print the inorder traversal of a BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    std::cout << "Inorder traversal before deletion: ";
    inorder(root);
    std::cout << std::endl;

    int key = 50;
    root = deleteNode(root, key);

    std::cout << "Inorder traversal after deletion of " << key << ": ";
    inorder(root);
    std::cout << std::endl;

    return 0;
}
