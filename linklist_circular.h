#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;

        node()
        {
            data=0;
            next=nullptr;
        }
};
class list
{
    public:
        node* head;

        list()
        {
            head=nullptr;
        }
        void insert(int d)
        {
            node*newnode = new node;
            newnode->data=d;
            if(head == nullptr)
            {
                head=newnode;
                newnode->next=head;
                return;
            }
            node*temp=head;
            while(temp->next != head)
            {
                temp=temp->next;
            }
            temp->next = newnode;
            newnode->next=head;
        }
        void display()
        {
            if(head == nullptr)
            {
                cout<<" list is empty"<<endl;
                return;
            }
            node*temp=head;
            cout<<temp->data<<" ";
            temp=temp->next;
            while(temp != head)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        bool search(int d)
        {
            node*temp;
            temp=head;

            if(temp->data = d)
            {
                cout<<"Found !"<<endl;
                return true;
            }/*
            temp=temp->next;
            while(temp->next!=head)
            {
                if(temp->data=d)
                {
                    cout<<"Found !"<<endl;
                    return true;
                }
            }*/
            return false;
        }
};