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
        void deletion(int t)
        {
            node* temp= head;
            //node* temp2=temp->next;
            while(temp->next !=nullptr)
            {
                if(temp->d == t)
                {
                    if(temp->next->next == nullptr)
                    {
                        temp->next =nullptr;
                        return;
                    }
                    temp->next=temp->next->next;
                    return;
                }
                temp=temp->next;
            }
        }
};
int main()
{
    list l;
    l.add(10);
    l.add(20);

    l.deletion(10);
}