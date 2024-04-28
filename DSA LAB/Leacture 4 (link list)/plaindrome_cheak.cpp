#include<iostream>
using namespace std;
class node
{
    public:
        int d;
        node* next;
        node* prev;

        node()
        {
            d=0;
            next = nullptr;
            prev = nullptr;
        }
};
class list
{
    public:
        node *head;
        node* tail;

        list()
        {
            head = nullptr;
            tail = nullptr;
        }
        void add(int t)
        {
            node* newnode = new node;
            newnode->d = t;
            if(head == nullptr)
            {
                head = newnode;
                tail = newnode;
                return;
            }
            node*temp=head;
            while(temp->next != nullptr)
            {
                temp=temp->next;
            }
            tail=newnode;
            temp->next=tail;
            tail->prev=temp;
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
        bool plaindrome()
        {
            if(head == nullptr || head == tail)
            {
                return false;
            }
            node*temp=head;
            node*temp2=tail;
            bool cheak=false;
            while(temp != temp2)
            {
                if(temp->d == temp2->d)
                {
                    cheak=true;
                    temp2=temp2->prev;
                    temp=temp->next;
                }
                else
                {
                    return false;
                }
            }
            return cheak;

        }
};
int main()
{
    list l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(35);
    l.add(30);
    l.add(20);
    l.add(10);

    cout<<"Plaindrome is : "<<l.plaindrome()<<endl;
    cout<<"Is loop : "<<l.loop()<<endl;
}