#include <iostream>
using namespace std;
class queue
{
public:
    int rare;
    int front;
    int cap;
    int length;
    int *arry;

    queue()
    {
        cap = 5;
        arry = new int [cap];
        rare = -1;
        front = -1;
        length = 0;
    }
    void enqueue(int data)
    {
        if(full())
        {
            return;
        }
        else if(rare == cap)
        {
            rare=-1;
        }
        length++;
        rare++;
        arry[rare]=data;
    }
    int dequeue()
    {
        if(empty())
        {
            return -1;
        }
        else if(front == cap)
        {
            front =-1;
        }
        length--;
        front++;
        return arry[front];
    }
    bool empty()
    {
        if(length == 0)
        {
            cout<<"Queue underflow"<<endl;
            return true;
        }
        return false;
    }
    bool full()
    {
        if(length == cap)
        {
            cout<<"Queue overflow"<<endl;
            return true;
        }
        return false;
    }
    void size()
    {
        if(empty())
        {
            return;
        }
        cout<<"Size of queue is : "<<length<<endl;
    }
    void reset()
    {
        if(empty())
        {
            return;
        }
        front = -1;
        rare = -1;
        length = 0;
    }
    void display()
    {
        if(empty())
        {
            return;
        }
        cout<<"Queue data : ";
        int j=front+1;
        for(int i=0 ; i<length ; i++)
        {
            if(front+i == cap)
            {
                j=0;
            }
            cout<<arry[j]<<" ";
            j++;
        }
        cout<<endl;
    }
    void reverse()
    {
        if(length < 2)
        {
            cout<<"could not be reversed"<<endl;
            return;
        }
        int a[length];
        int l=length;
        int j=front +1;
        for(int i=0 ; i<length ; i++)
        {
            if(front+i == cap)
            {
                j=0;
            }
            a[i]=arry[j];
            j++;
        }
        reset();
        for(int i=l-1 ; i>=0 ; i--)
        {
            enqueue(a[i]);
            cout<<a[i]<<endl;
        }
        


    }
};
int main()
{
    queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    //q.display();
    //cout<<"deque value : "<<q.dequeue()<<endl;
    q.enqueue(30);
    q.enqueue(40);
    //q.display();
    //cout<<"deque value : "<<q.dequeue()<<endl;

    //q.enqueue(50);
    //q.enqueue(60);

    //q.display();

    cout<<"deque value : "<<q.dequeue()<<endl;
    cout<<"deque value : "<<q.dequeue()<<endl;
    //cout<<"deque value : "<<q.dequeue()<<endl;

    //q.display();
    //q.size();

    //cout<<"deque value : "<<q.dequeue()<<endl;
    //cout<<"deque value : "<<q.dequeue()<<endl;
    //cout<<"deque value : "<<q.dequeue()<<endl;

    q.display();
    q.reverse();
    q.display();
    //q.display();
}