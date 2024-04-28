#include<iostream>
using namespace std;
class node
{
    public:
        int d;
        node* next;

        node()
        {
            d=0;
            next = nullptr;
        }
};
class list
{
    public:
        node *head;

        list()
        {
            head = nullptr;
        }
        void add(int t)
        {
            node *newnode = new node;
            newnode->d=t;
            if(head == nullptr)
            {
                head = newnode;
                return;
            }
            node *temp;
            temp = head;
            while(temp->next != nullptr)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        void clone(const list* l)
        {
            head=l->head;
        }
        void display()
        {
            if(head == nullptr)
            {
                cout<<"List is Empty "<<endl;
                return;
            }
            node*temp = head;
            cout<<"List elements are : ";
            while(temp != nullptr)
            {
                cout<<temp->d<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

};
int main()
{
    list l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    
    l.display();

    list l2;
    l2.clone(&l);
    l2.display();
}