#include <iostream>
#include <limits>
#include <stack>
#include <iomanip>
using namespace std;
class car
{
    public:
        string name;
        string numplate;
        bool overspeeding;
        stack<int> challanNumber;

        car()
        {
            name = "";
            numplate = "";
            overspeeding = false;
            challanNumber.push('0');
        }
        ~car()
        {
            name = "";
            numplate = "";
            overspeeding = false;
            challanNumber.push('0');
        }
};
class Node
{
    public:
        Node *next;
        Node *prev;
};
class LinkedList
{
    private:
        Node *head = nullptr;
        Node *cur = nullptr;
    public:
        ~LinkedList()
        {
            Node *cur = head;
            Node *temp;
            while (cur != nullptr)
            {
                temp = cur;
                cur = cur->next;
                delete temp;
                delete 
            }
        }

        void AddNode(string nm, string num)
        {
            Node *newnode = new Node();
            bool overspeeding;
            int temp = 0;
            if (head != nullptr) {
                if (SearchNode(num) != nullptr) {
                    cout << "This car already exists in database. Were you overspeeding?" << endl;
                    cin >> cur->overspeeding;
                    if (cur->overspeeding == 1)  {
                        temp = cur->challanNumber.top();
                        temp++;
                        cur->challanNumber.push(temp);
                        cout << "Challan no." << temp << " generated and pushed in stack" << endl;
                        return;
                    }
                    if (cur->overspeeding == 0)
                        return;
                }
            }
            cout << "Enter 1 for over speeding or 0 for not overspeeding: " << endl;
            cin >> overspeeding;
            newnode->name = nm;
            newnode->numplate = num;
            newnode->overspeeding = overspeeding;
            if (overspeeding == 1) {
                newnode->challanNumber.push(1);
                cout << "Challan no." << newnode->challanNumber.top() << " generated and pushed in stack" << endl;
                }
        
            else {
                cout << "You did not overspeeded \n";
                newnode->challanNumber.push(0);
            }
            
            newnode->next = nullptr;
            newnode->prev = nullptr;
            if (head == nullptr)
            {
                head = newnode;
                return;
            }
            Node *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr; 
        }

        Node *Empty()
        {
            if (head == nullptr)
            {
                cout << "List is empty. " << endl;
                return nullptr;
            }
            return head;
        }

        Node *SearchNode(string input)
        {
            cur = head;
            while (cur->numplate != input)
            {
                if (cur->next == nullptr)
                {
                    cur = nullptr;
                    return nullptr;
                }
                cur = cur->next;
            }
            return cur;
        }

        void DeleteNode(string input)
        {
            if (SearchNode(input) == nullptr) {
                cout << "No match found in database." << endl;
                return;
            }
            Node *temp;

            if (cur->next == nullptr)
            {
                if (cur->prev == nullptr)
                {
                    delete cur;
                    head = nullptr;
                    return;
                }
                temp = cur->prev;
                temp->next = nullptr;
                delete cur;
                return;
            }

            if (cur->prev == nullptr)
            {
                head = cur->next;
                delete cur;
                return;
            }
            temp = cur->prev;
            temp->next = cur->next;
            delete cur;
            return;
        }

        void AddCar () {
            string name, numplate;
            cout << "Enter the name of the car: " << endl;
            getline(cin, name);
            cout << "Enter the number plate: " << endl;
            getline(cin, numplate);
            AddNode(name, numplate);
            cout << "Car added successfully. " << endl;
        }

        void Print()
        {
            Node *ptr = head;
            string stats;
            int i = 1;
            cout << "-----------Speed Trap Database-----------" << endl;
            while (ptr != nullptr)
            {
                cout << "\n" << setw(23) << "Car no." << i << endl
                    << "Name: " << ptr->name << endl
                    << "Number plate: " << ptr->numplate << endl
                    << "Overspeeding: ";
                if (ptr->overspeeding == true)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                cout << "Number of Challans = " ;
                if (ptr->challanNumber.top() == 0)
                    cout << "0" << endl;
                else
                    cout << ptr->challanNumber.top() << endl;
                ptr = ptr->next;
                i++;
            }
            cout << "\n";
        }

        void PrintSpecific(string numplate)
        {
            Node *temp;
            temp = SearchNode(numplate);
            if (temp == nullptr) {
                cout << "No match found in database. " << endl;
                return;
                }
            else
                cout << "Match found in database. " << endl
                    << endl;
            cout << "-----------Speed Trap Database-----------" << endl;
            cout << "Name: " << temp->name << endl
                << "Number plate: " << temp->numplate << endl
                << "Overspeeding: ";
            if (temp->overspeeding == true)
                    cout << "Yes" << endl;
            else
                cout << "No" << endl;
            cout << "Number of Challans = " ;
                cout << temp->challanNumber.top() << endl;
            cout << "\n";
        }
};