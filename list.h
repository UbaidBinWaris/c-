#include<iostream>
using namespace std;
class LinkedList;
class node
{
    public:
        int data;
        node *next;
        node *prev;

        node()
        {
            data=0;
            next=nullptr;
            prev=nullptr;
        }
};
class LinkedList
{
    public:
        node *head;

        LinkedList()
        {
            head=nullptr;
        }
        void display()
        {
            node *temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        int get_size()
        {
            node *temp=head;
            int count=0;
            while(temp!=nullptr)
            {
                count++;
                temp=temp->next;
            }
            return count;
        }
        void insert(int data)
        {
            node *temp=new node;
            temp->data=data;
            temp->next=nullptr;
            temp->prev=nullptr;
            if(head==nullptr)
            {
                head=temp;
                return;
            }
            node *temp1=head;
            while(temp1->next!=nullptr)
            {
                temp1=temp1->next;
            }
            temp1->next=temp;
            temp->prev=temp1;
        }
        void insert(int index , int data)
        {
            node *temp=new node;
            temp->data=data;
            temp->next=nullptr;
            temp->prev=nullptr;
            if(head==nullptr)
            {
                head=temp;
                return;
            }
            else if(index  == 0)
            {
                temp->next=head;
                head->prev=temp;
                head=temp;
                return;
            }
            else if(index >= get_size()+1)
            {
                insert(get_size(),data);
                return;
            }
            else
            {
                node *temp1=head;
                int i=0;
                while(i<index-1)
                {
                    temp1=temp1->next;
                    i++;
                }
                temp->next=temp1->next;
                temp1->next=temp;
                temp->prev=temp1;
                temp1->next->prev=temp;
            }   
        }
        /*void delete_node(int index)
        {
            if(head==nullptr)
            {
                cout<<"The List is alraedy Empty !!!"<<endl;
            }
            else if(index == 0)
            {
                node *temp=new node;
                temp=head->next;
                temp->prev=nullptr;
                head = temp;
            }
            else if(index >= get_size())
            {
                cout<<"No Index fount in data"<<endl;
                cout<<"You have only indexing of size "<<get_size()<<endl;
            }
            elseif(index+1 == get_size())
            {
                
            }
            else
            {
                node *temp1=head;
                int i=0;
                while(i<index-1)
                {
                    temp1=temp1->next;
                    i++;
                }
                node *temp2=temp1->next;
                temp1->next=temp2->next;
                temp2->next->prev=temp1;
                delete temp2;
            }
        }
        void delete_data(int data)
        {
            if(head==nullptr)
            {
                cout<<"The List is alraedy Empty!!!"<<endl;
            }
            else
            {
                node *temp=head;
                int index=0;
                while(temp!=nullptr)
                {
                    if(temp->data==data)
                    {
                        delete_node(index);
                        return;
                    }
                    temp=temp->next;
                    index++;
                }
                cout<<"No record found in data"<<endl;
            }
        }*/
};