#include<iostream>
using namespace std;
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
            int size=0;
            node *temp=head;
            while(temp!=nullptr)
            {
                size++;
                temp=temp->next;
            }
            return size;
        }
        void insert(int data)
        {
            node *temp=new node();
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
        void insert(int index, int data)
        {
            node *temp=new node();
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
        void delete_node(int index)
        {
            if(head==nullptr)
            {
                cout<<"The List is alraedy Empty!!!"<<endl;
            }
            else if(index == 0)
            {
                node *temp=new node;
                temp=head->next;
                temp->prev=nullptr;
                head = temp;
                delete temp;
            }
            else if(index >= get_size())
            {
                cout<<"No Index fount in data"<<endl;
                cout<<"You have only indexing of size "<<get_size()<<endl;
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
        void reverse()
        {
            if(head==nullptr)
            {
                cout<<"The List is alraedy Empty!!!"<<endl;
            }
            else
            {
                node *temp=head;
                node *temp1=head;
                while(temp1->next!=nullptr)
                {
                    temp1=temp1->next;
                }
                while(temp!=nullptr)
                {
                    node *temp2=temp->next;
                    temp->next=temp1;
                    temp1->prev=temp;
                    temp=temp2;
                }
                head=temp1;
            }
        }
        }
};
int main()
{
    int a;
    LinkedList l;
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;
    
    l.delete_node(0);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;

    a=l.get_size();
    cout<<a<<endl;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;
    
    l.insert(0,40);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;

    l.insert(50);
    l.insert(60);
    l.insert(3,70);
    a=l.get_size();
    cout<<a<<endl;
    l.display();

    cout<<endl;

    l.insert(80);
    l.insert(90);
    l.insert(100);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;


    l.delete_node(0);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;

    /*l.delete_node(0);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;

    
    l.delete_node(0);
    l.display();
    a=l.get_size();
    cout<<a<<endl;
    cout<<endl;*/

    return 0;
}