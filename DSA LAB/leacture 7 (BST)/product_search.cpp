#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    string code;
    double price;

    Product() {
        name = "null";
        code = "null";
        price = 0.0;
    }

    Product(string n, string c, double p) {
        name = n;
        code = c;
        price = p;
    }

    void set_data() {
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter product code: ";
        cin >> code;
        cout << "Enter product price: ";
        cin >> price;
    }

    void display() {
        cout << "Product Name : " << name << endl;
        cout << "Product Code : " << code << endl;
        cout << "Product Price: " << price << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    Product product;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* insert(Node* temp, Product product) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->product = product;
            return newnode;
        }
        else if (product.code < temp->product.code) {
            temp->left = insert(temp->left, product);
        }
        else if (product.code > temp->product.code) {
            temp->right = insert(temp->right, product);
        }
        return temp;
    }

    Node* search_by_code(Node* temp, string code) {
        if (temp == nullptr || temp->product.code == code) {
            return temp;
        }
        else if (code < temp->product.code) {
            return search_by_code(temp->left, code);
        }
        else {
            return search_by_code(temp->right, code);
        }
    }

    Node* search_by_name(Node* temp, string name) {
        if (temp == nullptr) {
            return temp;
        }
        if (temp->product.name == name) {
            return temp;
        }
        Node* leftSearch = search_by_name(temp->left, name);
        if (leftSearch != nullptr) {
            return leftSearch;
        }
        return search_by_name(temp->right, name);
    }

    void display(Node* temp) {
        if (temp != nullptr) {
            display(temp->left);
            temp->product.display();
            display(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        Product product;
        product.set_data();
        root = insert(root, product);
    }

    void insert(string name, string code, double price) {
        Product product(name, code, price);
        root = insert(root, product);
    }

    void display() {
        cout << "\n\t\tProduct Catalog" << endl << endl;
        display(root);
    }

    void found_by_code(string code) {
        Node* result = search_by_code(root, code);
        if (result == nullptr) {
            cout << "Product with code " << code << " not found." << endl;
        } else {
            cout << "\t\tProduct found by code" << endl;
            result->product.display();
        }
    }

    void found_by_name(string name) {
        Node* result = search_by_name(root, name);
        if (result == nullptr) {
            cout << "Product with name " << name << " not found." << endl;
        } else {
            cout << "\t\tProduct found by name" << endl;
            result->product.display();
        }
    }
};

int main() {
    BST catalog;

    catalog.insert("Laptop", "P001", 750.00);
    catalog.insert("Smartphone", "P002", 500.00);
    catalog.insert("Tablet", "P003", 300.00);
    catalog.insert("Headphones", "P004", 150.00);
    catalog.insert("Smartwatch", "P005", 200.00);

    catalog.display();


    string code;
    cout << "\nEnter product code to search: ";
    cin >> code;
    catalog.found_by_code(code);


    string name;
    cout << "\nEnter product name to search: ";
    cin.ignore();
    getline(cin, name);
    catalog.found_by_name(name);

    return 0;
}
