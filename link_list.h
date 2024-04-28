#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node* next;

        node()
        {
            data = 0 ;
            next = nullptr;
        }
};
class list
{
    public:
        node* head;

    list()
    {
        head = nullptr;
    }
    void display()
    {
        if(empty())
        {
            return;
        }
        node* temp = head;
        cout<<"Data in list is : ";
        while(temp != nullptr)
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
            cout<<"! ! ! List is Empty ! ! !"<<endl;
            return true;
        }
        return false;
    }
    void insert(int d)
    {
        node* newnode = new node;
        newnode->data = d;

        if(head == nullptr)
        {
            head=newnode;
            return;
        }

        node* temp = head;
        while(temp->next != nullptr)
        {
            temp=temp->next;
        }
        temp->next=newnode;

    }
    bool search(int d)
    {
        node* temp =head;
        while (temp != nullptr)
        {
            if(temp->data == d)
            {
                cout<<"Data Found "<<endl;
                return true;
            }
            temp=temp->next;
        }
        return false;
        
    }
    void remove(int d)
    {
        node* temp =head;
        if(temp->data == d)
        {
            head=temp->next;
            return;
        }
        while(temp->next->next == nullptr)
        {
            if(temp->next->data == d)
            {
                temp->next =nullptr;
                return;
            }
            temp=temp->next;
        }
        
        temp=head;
        node*temp1=temp->next;
        while (temp->next != nullptr)
        {
            if(temp->next->data == d)
            {
                temp->next=temp1->next;
                return;
            }
            temp=temp->next;
            temp1=temp->next;
        }
    }
    void remove_index(int i)
    {
        if(i == 0)
        {
            node* temp = head;
            head = temp->next;
            return;
        }
        if ((i >= size()))
        {
            node* temp= head;
            node*temp1=head;
            while(temp->next->next != nullptr)
            {
                temp1=temp->next;
                temp=temp->next;
            }
            temp1->next=nullptr;
            return;
            
        }
        node*temp =head;
        for(int j=0 ; j<i-1 ; j++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    int size()
    {
        int count=0;
        node* temp = new node;
        temp = head;
        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void insert_index(int i , int d)
    {
        node* newnode = new node;
        newnode->data=d;
        if(i == 0)
        {
            if(head == nullptr)
            {
                head=newnode;
            }
            else
            {
                newnode->next = head;
                head=newnode;
            }
            return;
        }
        if ((i >= size()))
        {
            node* temp= head;
            while(temp->next != nullptr)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            return;
            
        }
        node*temp = head;
        for(int j=0 ; j<i-1 ; j++)
        {
            temp=temp->next;
        }
        node* temp1 =temp->next;
        temp->next=newnode;
        newnode->next=temp1;
    }
    list operatr(const list &l)
    {
        node*temp=head;
        l.head->data=head->data;
        while(temp != nullptr)
        {
            node *newnode = new node;
            temp->data=newnode->data;
            l.head->next=newnode;
            temp=temp->next;
        }
    }
    void reverse()
    {
        node*temp1=head->next;
        node*end=head;
        while(end->next != nullptr)
        {
            end=end->next;
        }
        head->next=nullptr;
        end->next=head;
        node*end_next;
        while(temp1 != end)
        {
            node*temp=temp1;
            temp1=temp1->next;
            end_next=end->next;
            end->next=temp;
            temp->next=end_next;
        }
        head=end;
    }
};