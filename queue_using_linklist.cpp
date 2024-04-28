#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;

    node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};
class queue
{
public:
    node* head;
    node* tail;

    queue()
    {
        head = nullptr;
        tail = nullptr;
    }
    void enqueue(int d)
    {
        node* newnode = new node;
        newnode->data = d;
        if(head == nullptr)
        {
            head = newnode;
            tail = head;
        }
        else if(head == tail)
        {
            head->next = newnode;
            newnode->prev = head;
            tail=newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;

        }
    }
    int dequeue()
    {
        if(head == nullptr)
        {
            return -1;
        }
        int a = head->data;
        head = head->next;
        return a;
    }
    void display()
    {
        if(empty())
        {
            return;
        }
        cout<<"Queue data : ";
        node* temp = head;
        while(temp != tail->next)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool empty()
    {
        if(head == nullptr)
        {
            return true;
        }
        return false;
    }
    void size()
    {
        if(empty())
        {
            return;
        }
        int count = 0;
        node *temp = head;
        while(temp != nullptr)
        {
            count++;
            temp=temp->next;
        }
        cout<<"Length of Queue is : "<<count<<endl;
    }
    void reset()
    {
        if(empty())
        {
            return;
        }
        head = nullptr;
        tail= nullptr;
    }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.size();

    q.display();


    cout<<"deque value : "<<q.dequeue()<<endl;
    cout<<"deque value : "<<q.dequeue()<<endl;
    cout<<"deque value : "<<q.dequeue()<<endl;

    q.display();
    q.size();
}