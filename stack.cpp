#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class list
{
    public:
        node *head;

        list()
        {
            head=nullptr;
        }
};
class stack
{
    public:
    node *top;
    node *head;
    
    stack()
    {
        head=nullptr;
        top=nullptr;
    }
    void push(int x)
    {
        node *temp=new node;
        if (head == nullptr)
        {
            head=temp;
            temp->data=x;
            temp->next=nullptr;
            top=temp;
        }
        else
        {
            while(temp != top)
            {
                temp=temp->next;
            }
            temp->data=x;
            temp->next=nullptr;
            top=temp;
        }
    }
    int pop()
    {
        if (top == nullptr)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        node *temp=head;
        while(temp->next != top)
        {
            temp=temp->next;
        }
        return temp->data;
    }
    void display()
    {
        if (top == nullptr)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        node *temp=head;
        while(temp!=top)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    void reverse()
    {
        if (top == nullptr)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        node *temp=head;
        node *prev=nullptr;
        while(temp!=top)
        {
            node *temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        head=prev;
    }
};
int main()
{
    stack s;
    s.display();
    s.push(1);
    s.display();
    s.push(2);
    s.display();
    s.push(3);
    s.display();
    //int a = s.pop();
    //cout<<"size : "<<a<<endl;
}