#include<iostream>
using namespace std;
class node
{
    public:
        int d;
        node* next;
        node*prev;

        node()
        {
            d=0;
            next=nullptr;
            prev=nullptr;
        }
};
class list
{
    public:
        node* head;
        node* tail;

        list()
        {
            head=nullptr;
            tail=nullptr;
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
        int get_length()
        {
            if(head==nullptr)
            {
                return -1;
            }
            node* temp=head;
            int count=0;
            while(temp != nullptr)
            {
                count++;
                temp=temp->next;
            }
            return count;

        }
        void find(int a)
        {
            node* temp=tail;
            for(int i=0 ; i<a-1 ;i++)
            {
                temp=temp->prev;
            }
            cout<<"From last index : "<<a<<"  node data is : "<<temp->d<<endl;
        }
        void middle()
        {
            int a=get_length();
            node* temp=tail;
            for(int i=0 ; i<(a/2)-1 ; i++)
            {
                temp=temp->prev;
            }
            cout<<"Middle of the list node is : "<<temp->d<<endl;
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
    l.add(70);

    l.find(3);
    l.middle();
}