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
    void reverse()
    {
        if(head->next == nullptr)
        {
            return;
        }
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
    void reverse(int l)
    {
        if(head->next == nullptr || l == 0)
        {
            return;
        }
        node*temp1=head->next;
        node*end=head;
        for(int i=0 ; i<l ;i++)
        {
            end=end->next;
        }
        node*end_end=end->next;
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
        head->next=end_end;
        head=end;   
    }
};
int main()
{
    list l;
    l.add(20);
    l.add(10);

    l.display();
    l.reverse();
    l.display();

    l.add(30);
    l.add(40);
    l.add(50);
    l.add(60);

    l.reverse(4);
    l.display();
}