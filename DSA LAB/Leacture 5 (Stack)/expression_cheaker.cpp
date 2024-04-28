#include<iostream>
using namespace std;
class stack
{
    public:
        int top;
        char* arry;
        int size;

        stack(int s)
        {
            top = -1;
            size = s;
            arry = new char [size];
        }
        void push(char d)
        {
            if(top+1 < size)
            {
                top++;
                arry[top]=d;
            }
        }
        void pop()
        {
            if(top < -1)
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
    stack s(10);
    int l;
    cout<<"Enter Expression lenght : ";
    cin>>l;
    char ch;
    cout<<"Enter Expression : ";
    for(int i=0 ; i<l ; i++)
    {
        cin>>ch;
        if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            s.pop();
        }
    }
    if(s.empty())
    {
        cout<<"Equation is un balanced"<<endl;
    }
    else
    {
        cout<<"Equation is balanced"<<endl;
    }
}