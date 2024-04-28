#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int size;
    bool *arr;

    stack()
    {
        top = -1;
        size = 10;
        arr = new bool[size];
        for (int i = 0; i < size; ++i)
            arr[i] = false;
    }

    void push(bool present)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = present;
        }
        else
            cout << "Attendance stack overflow" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Attendance stack underflow" << endl;
    }

    void display()
    {
        cout << "Attendance: ";
        for (int i = 0; i <= top; ++i)
        {
            if (arr[i])
                cout << "P ";
            else
                cout << "A ";
        }
        cout << endl;
    }
};

class student
{
public:
    int rollno;
    string name;
    string Class;
    stack *attendance;

    student()
    {
        rollno = 0;
        name = "";
        Class = "";
        attendance = new stack();
    }
};

class node
{
public:
    student record;
    node *next;
    node *prev;

    node()
    {
        next = NULL;
        prev = NULL;
    }
};

class list
{
public:
    node *head;

    list()
    {
        head = NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        node *temp = head;
        while (temp != NULL)
        {
            cout << "Name : " << temp->record.name << endl;
            cout << "Roll no. : " << temp->record.rollno << endl;
            temp->record.attendance->display();
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(student s)
    {
        node *temp = new node;
        temp->record = s;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }

    void deleteNode(int rollno)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->record.rollno == rollno)
        {
            node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->record.rollno == rollno)
            {
                node *temp1 = temp->next;
                temp->next = temp1->next;
                if (temp1->next != NULL)
                {
                    temp1->next->prev = temp;
                }
                delete temp1;
                cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp->record.rollno == rollno)
        {
            temp->prev->next = NULL;
            delete temp;
            cout << "Node with roll no. " << rollno << " deleted successfully" << endl;
            return;
        }
        cout << "Roll no. not found" << endl;
    }

    void addAttendance(int rollno, bool present)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->record.rollno == rollno)
            {
                temp->record.attendance->push(present);
                cout << "Attendance added successfully for roll no. " << rollno << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Roll no. not found" << endl;
    }

    void deleteAttendance(int rollno)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->record.rollno == rollno)
            {
                temp->record.attendance->pop();
                cout << "Attendance deleted successfully for roll no. " << rollno << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Roll no. not found" << endl;
    }
};

void menu()
{
    cout << "Student Management record" << endl
         << endl;
    cout << " 1. Add student" << endl;
    cout << " 2. Delete student" << endl;
    cout << " 3. Display student" << endl;
    cout << " 4. Attendance" << endl;
    cout << " 5. Exit" << endl;
}

void attendanceMenu()
{
    cout << "Attendance" << endl
         << endl;
    cout << " 1. Add attendance" << endl;
    cout << " 2. Delete attendance" << endl;
    cout << " 3. Display attendance" << endl;
    cout << " 4. Back" << endl;
}

int main()
{
    list l;
    bool run = true;
    char option;

    do
    {
        menu();
        cout << "Please enter your choice : ";
        cin >> option;

        switch (option)
        {
        case '1':
        {
            student s;
            cout << "Enter name : ";
            cin >> s.name;
            cout << "Enter roll no. : ";
            cin >> s.rollno;
            cout << "Enter class : ";
            cin >> s.Class;
            l.insert(s);
            break;
        }
        case '2':
        {
            int rollno;
            cout << "Enter roll no. : ";
            cin >> rollno;
            l.deleteNode(rollno);
            break;
        }
        case '3':
        {
            l.display();
            break;
        }
        case '4':
        {
            char attendanceOption;
            int rollno;
            bool present;
            do
            {
                attendanceMenu();
                cout << "Please enter your choice : ";
                cin >> attendanceOption;

                switch (attendanceOption)
                {
                case '1':
                    cout << "Enter roll no. : ";
                    cin >> rollno;
                    cout << "Present? (1 for Yes, 0 for No): ";
                    cin >> present;
                    l.addAttendance(rollno, present);
                    break;
                case '2':
                    cout << "Enter roll no. : ";
                    cin >> rollno;
                    l.deleteAttendance(rollno);
                    break;
                case '3':
                    l.display();
                    break;
                case '4':
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
            } while (attendanceOption != '4');
            break;
        }
        case '5':
        {
            run = false;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (run);

    return 0;
}