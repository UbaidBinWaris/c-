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
class stack
{
    public:
        node*head;
        node*tail;

        stack()
        {
            head=nullptr;
            tail=head;
        }
        void push(int d)
        {
            node* newnode = new node;
            newnode->data=d;

            if(head == nullptr)
            {
                head=newnode;
                tail=head;
                return;
            }
            tail=head;
            while(tail->next != nullptr)
            {
                tail=tail->next;
            }
            tail->next = newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        int peek()
        {
            if(head == nullptr)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return tail->data;
        }
        void pop()
        {
            if(head == nullptr)
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            if(tail == head)
            {
                tail=nullptr;
                head=nullptr;
                return;
            }
            tail=tail->prev;
        }
        void reverse()
        {
            if(head == nullptr)
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            /*else if(head == tail)
            {
                node*temp;
                head=temp;
                tail=head;
                head=temp;
                return;
            }*/
            /*node*temp=head->next;
            node*temp1=head->next;
            head->next=nullptr;
            tail->next=head;
            head->prev = tail;

            while(temp1 != tail)
            {
                node *next_tail=tail->next;
                temp=temp1;
                tail->next=temp;
                temp->prev=tail;
                temp1=temp1->next;
            }*/

        }

};