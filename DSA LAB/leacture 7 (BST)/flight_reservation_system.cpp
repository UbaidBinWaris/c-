#include <iostream>
#include <string>
using namespace std;

class Flight {
public:
    string flightNumber;
    string departureCity;
    string arrivalCity;
    string departureTime;
    string arrivalTime;

    Flight() {
        flightNumber = "null";
        departureCity = "null";
        arrivalCity = "null";
        departureTime = "null";
        arrivalTime = "null";
    }

    Flight(string fn, string dc, string ac, string dt, string at) {
        flightNumber = fn;
        departureCity = dc;
        arrivalCity = ac;
        departureTime = dt;
        arrivalTime = at;
    }

    void set_data() {
        cout << "Enter flight number: ";
        cin >> flightNumber;
        cout << "Enter departure city: ";
        cin.ignore();
        getline(cin, departureCity);
        cout << "Enter arrival city: ";
        getline(cin, arrivalCity);
        cout << "Enter departure time: ";
        getline(cin, departureTime);
        cout << "Enter arrival time: ";
        getline(cin, arrivalTime);
    }

    void display() {
        cout << "Flight Number  : " << flightNumber << endl;
        cout << "Departure City : " << departureCity << endl;
        cout << "Arrival City   : " << arrivalCity << endl;
        cout << "Departure Time : " << departureTime << endl;
        cout << "Arrival Time   : " << arrivalTime << endl;
        cout << "----------------------------------------" << endl;
    }
};

class Node {
public:
    Flight flight;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* insert(Node* temp, Flight flight) {
        if (temp == nullptr) {
            Node* newnode = new Node;
            newnode->flight = flight;
            return newnode;
        }
        else if (flight.flightNumber < temp->flight.flightNumber) {
            temp->left = insert(temp->left, flight);
        }
        else if (flight.flightNumber > temp->flight.flightNumber) {
            temp->right = insert(temp->right, flight);
        }
        return temp;
    }

    Node* search(Node* temp, string flightNumber) {
        if (temp == nullptr || temp->flight.flightNumber == flightNumber) {
            return temp;
        }
        else if (flightNumber < temp->flight.flightNumber) {
            return search(temp->left, flightNumber);
        }
        else {
            return search(temp->right, flightNumber);
        }
    }

    void display(Node* temp) {
        if (temp != nullptr) {
            display(temp->left);
            temp->flight.display();
            display(temp->right);
        }
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert() {
        Flight flight;
        flight.set_data();
        root = insert(root, flight);
    }

    void insert(string flightNumber, string departureCity, string arrivalCity, string departureTime, string arrivalTime) {
        Flight flight(flightNumber, departureCity, arrivalCity, departureTime, arrivalTime);
        root = insert(root, flight);
    }

    void display() {
        cout << "\n\t\tFlight Catalog" << endl << endl;
        display(root);
    }

    void found(string flightNumber) {
        Node* result = search(root, flightNumber);
        if (result == nullptr) {
            cout << "Flight with number " << flightNumber << " not found." << endl;
        } else {
            cout << "\t\tFlight found" << endl;
            result->flight.display();
        }
    }
};

int main() {
    BST catalog;

    catalog.insert("PK001", "Karachi", "Lahore", "08:00", "10:00");
    catalog.insert("PK002", "Islamabad", "Karachi", "09:00", "11:00");
    catalog.insert("PK003", "Lahore", "Peshawar", "10:00", "11:30");
    catalog.insert("PK004", "Karachi", "Quetta", "07:00", "09:00");
    catalog.insert("PK005", "Lahore", "Islamabad", "06:00", "07:30");

    catalog.display();

    string flightNumber;
    cout << "\nEnter flight number to search: ";
    cin >> flightNumber;
    catalog.found(flightNumber);

    return 0;
}
