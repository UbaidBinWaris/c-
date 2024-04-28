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
                newnode->next=head;
                return;
            }
            if(head->next = head)
            {
                head->next=newnode;
                newnode->next=head;
                return;
            }
            node *temp;
            temp = head;
            temp = temp->next;
            while(temp->next != head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
        bool loop()
        {
            node*temp=head;
            while(temp != nullptr)
            {
                temp=temp->next;
                if(temp == head)
                {
                    return true;
                }
            }
            return false;
        }
        void resolve_loop()
        {
            if(!loop())
            {
                return;
            }
            node*temp=head;
            temp=temp->next;
            while(temp->next != head)
            {
                temp=temp->next;
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
    l.add(50);
    l.add(60);

    cout<<"(loop for 1 otherwise 0 ) is loop : "<<l.loop()<<endl;
    l.resolve_loop();
    cout<<"(loop for 1 otherwise 0 ) is loop : "<<l.loop()<<endl;
    
}