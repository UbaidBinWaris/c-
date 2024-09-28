#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;

    Book() {
        title = "null";
        author = "null";
        ISBN = "null";
    }

    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
    }

    void set_data() {
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book ISBN: ";
        cin >> ISBN;
    }

    void display() const {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "ISBN   : " << ISBN << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    Book book;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* insert(Node* temp, Book book) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->book = book;
            return newnode;
        }
        else if (book.ISBN < temp->book.ISBN) {
            temp->left = insert(temp->left, book);
        }
        else if (book.ISBN > temp->book.ISBN) {
            temp->right = insert(temp->right, book);
        }
        return temp;
    }

    Node* search(Node* temp, const string& isbn) const {
        if (temp == nullptr || temp->book.ISBN == isbn) {
            return temp;
        }
        else if (isbn < temp->book.ISBN) {
            return search(temp->left, isbn);
        }
        else {
            return search(temp->right, isbn);
        }
    }

    void display(Node* temp) const {
        if (temp != nullptr) {
            display(temp->left);
            temp->book.display();
            display(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        Book book;
        book.set_data();
        root = insert(root, book);
    }

    void insert(const string& title, const string& author, const string& isbn) {
        Book book(title, author, isbn);
        root = insert(root, book);
    }

    void display() const {
        cout << "\n\t\tLibrary Catalog" << endl << endl;
        display(root);
    }

    void search(const string& isbn) const {
        Node* result = search(root, isbn);
        if (result == nullptr) {
            cout << "Book with ISBN " << isbn << " not found." << endl;
        } else {
            cout << "\t\tBook found" << endl;
            result->book.display();
        }
    }
};

int main() {
    BST catalog;
    
    catalog.insert("The Great Gatsby", "F. Scott Fitzgerald", "2542");
    catalog.insert("To Kill a Mockingbird", "Harper Lee", "2546");
    catalog.insert("1984", "George Orwell", "9875");
    catalog.insert("Pride and Prejudice", "Jane Austen", "6578");
    catalog.insert("The Catcher in the Rye", "J.D. Salinger", "6598");

    catalog.display();

    string isbn;
    cout << "\nEnter ISBN to search: ";
    cin >> isbn;
    catalog.search(isbn);

    return 0;
}
