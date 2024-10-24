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
        void merg(const list *l)
        {
            if(l->head == nullptr )
            {
                return;
            }
            if(head == nullptr)
            {
                head=l->head;
                return;   
            }
            node*temp=head;
            while(temp->next != nullptr)
            {
                temp=temp->next;
            }
            temp->next=l->head;
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
        int get_length()
        {
            int count=0;
            if(head == nullptr)
            {
                return count;
            }
            node*temp=head;
            while(temp != nullptr)
            {
                temp=temp->next;
                count++;
            }
            return count;
        }
        void split(list* l)
        {
            int a=l->get_length();
            node*temp=l->head;
            for(int i=0 ; i<(a/2)-1 ; i++)
            {
                temp=temp->next;
            }
            node*temp2=temp->next;
            while(temp2 != nullptr)
            {
                add(temp2->d);
                temp2=temp2->next;
            }
            temp->next=nullptr;
        }

};
int main()
{
    list l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);

    list l2;
    l2.add(100);
    l2.add(90);
    l2.merg(&l);
    l2.display();

    cout<<"L2 size : "<<l2.get_length()<<endl;

    list l3;
    l3.split(&l2);
    l2.display();
    l3.display();


    
}