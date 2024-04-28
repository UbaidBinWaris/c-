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
            if (l->head == nullptr)
            {
                return;
            }
            if (head == nullptr)
            {
                head = l->head;
                return;
            }
            node* temp = head;
            node* temp2 = l->head;
            while (temp->next != nullptr || temp2 != nullptr)
            {
                if (temp2 == nullptr || (temp->next != nullptr && temp->next->d <= temp2->d))
                {
                    temp = temp->next;
                }
                else
                {
                    node* ttt = new node;
                    ttt->d=temp2->d; // Create a new node with the value of temp2->d
                    ttt->next = temp->next; // Link the new node to the next node of temp
                    temp->next = ttt; // Link temp to the new node
                    temp2 = temp2->next; // Move to the next node of the second list
                }
            }
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
    l2.add(5);
    l2.add(32);
    l2.display();
    l2.merg(&l);
    l2.display();  
}