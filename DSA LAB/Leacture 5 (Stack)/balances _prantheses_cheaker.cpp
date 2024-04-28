#include<iostream>
using namespace std;
class stack
{
    public:
        int top;
        int size;
        char* arry;

        stack()
        {
            top=-1;
            size=20;
            arry = new char[size];
        }
        void push(char ch)
        {
            if(top < size)
            {
                top++;
                arry[top]=ch;
            }
        }
        char peek()
        {
            if(top != -1)
            {
                return arry[top];
            }
            return 'a';
        }
        void pop()
        {
            if(top != -1)
            {
                top--;
            }
        }
        bool empty()
        {
            if(top == -1)
            {
                return true;
            }
            return false;
        }
};
int main()
{
    stack s;
    char ch;
    int l;
    cout<<"Enter Bracket size : ";
    cin>>l;

    cout<<"Enter brackets : ";
    for(int i=0 ; i<l ; i++)
    {
        cin>>ch;
        if(ch == '[' || ch == '(' || ch == '{')
        {
            s.push(ch);
        }
        else if(ch == ']' || ch == ')' || ch == '}')
        {
            s.pop();
        }
    }
    if(s.empty())
    {
        cout<<"braces are balanced "<<endl;
    }
    else
    {
        cout<<"Invalid Braces"<<endl;
    }
    return 0;
}