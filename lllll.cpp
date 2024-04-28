#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;

        node()
        {
            data=0;
            next=nullptr;
        }
};
class list
{
    public:
        node *head;

        list()
        {
            head=nullptr;
        }
        void insert(int x)
        {
            node *temp=new node;
            temp->data=x;

            if(head == nullptr)
            {
                head=temp;
                head->next=nullptr;
            }
            else
            {
                node *temp1=new node;
                temp1=head;
                while(temp1->next != nullptr)
                {
                    temp1=temp1->next;
                }
                temp1->next=temp;
            }
        }
        void display()
        {
            if(head == nullptr)
            {
                cout<<"List is Empty"<<endl;
                return;
            }
            node *temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main()
{
    list l;

    l.display();

    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    l.display();
    
    return 0;
}