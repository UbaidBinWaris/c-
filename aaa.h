#include <iostream>
#include "stack.h"
#include <iomanip>
using namespace std;

class car
{
    public:
        string name;
        string numplate;
        bool overspeeding;
        Stack challanNumber;

        car()
        {
            name = "NULL";
            numplate = "NULL";
            overspeeding = false;
        }
        void get_data()
        {
            cout << "Enter the car's name: ";
            getline(cin,name);
            cout << "Enter the car's number plate: ";
            getline(cin,numplate);
        }
};
class Node
{
    public:
        car record;
        Node *next;
        Node *prev;

        Node()
        {
            next = nullptr;
            prev = nullptr;
        }
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
            }
        }
        void AddNode()
        {
            Node *newnode = new Node;
            newnode->record.get_data();

            if (head != nullptr) 
            {
                if (SearchNode(newnode->record.numplate) != nullptr) 
                {
                    cout << "This car already exists in database. Were you overspeeding ? :  ";
                    cin >> cur->record.overspeeding;
                    if (cur->record.overspeeding == 1)  
                    {
                        int temp=0;
                        temp = cur->record.challanNumber.top();
                        temp++;
                        cur->record.challanNumber.push(temp);
                        cout << "Challan no." << temp << " generated and pushed in stack" << endl;
                        return;
                    }
                    if (cur->record.overspeeding == 0)
                        return;
                }
            }
 
            bool overspeeding;
            cout << "Enter 1 for over speeding or 0 for not overspeeding : " ;
            cin >> overspeeding;
            newnode->record.overspeeding = overspeeding;
            if (overspeeding == 1) 
            {
                newnode->record.challanNumber.push(1);
                cout << "Challan no." << newnode->record.challanNumber.top() << " generated and pushed in stack" << endl;
            }
            else 
            {
                cout << "You did not overspeeded \n";
                newnode->record.challanNumber.push(0);
            }
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
            while (cur->record.numplate != input)
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
        void Print()
        {
            Node *ptr = head;
            string stats;
            int i = 1;
            cout << "-----------Speed Trap Database-----------" << endl;
            while (ptr != nullptr)
            {
                cout << "\n" << setw(23) << "Car no." << i << endl
                    << "Name: " << ptr->record.name << endl
                    << "Number plate: " << ptr->record.numplate << endl
                    << "Overspeeding: ";
                if (ptr->record.overspeeding == true)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
                cout << "Number of Challans = " ;
                if (ptr->record.challanNumber.top() == 0)
                    cout << "0" << endl;
                else
                    cout << ptr->record.challanNumber.top() << endl;
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
            cout << "Name: " << temp->record.name << endl
                << "Number plate: " << temp->record.numplate << endl
                << "Overspeeding: ";
            if (temp->record.overspeeding == true)
                    cout << "Yes" << endl;
            else
                cout << "No" << endl;
            cout << "Number of Challans = " ;
                cout << temp->record.challanNumber.top() << endl;
            cout << "\n";
        }
};