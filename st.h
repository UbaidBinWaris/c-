#include<iostream>
using namespace std;
class stack
{
    public:
        int size;
        int *arry;
        int top;

    stack(int s)
    {
        size=s;
        arry = new int [s];
        top=-1;
    }
    void push(int d)
    {
        if(top < size)
        {
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arry[top]=d;
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack is already empty "<<endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arry[top];
    }
    bool empty()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<endl;
            return true;
        }
        return false;
    }
    void reverse()
    {
        if(empty())
        {
            return;
        }
        else if(top == 0)
        {
            cout<<"Stack contains only one elemant and cannot be reversed"<<endl;
            return;
        }
        int temp;
        for(int i=0 ; i<top/2 ; i++)
        {
            temp=arry[i];
            arry[i]=arry[top-i];
            arry[top-i]=temp;
        }
    }
};