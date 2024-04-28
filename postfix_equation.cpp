#include<iostream>
using namespace std;
class stack
{
    public:
        int top;
        int *arry;
        int size;

        stack()
        {
            size = 20;
            top = -1;
            arry = new int [size];
        }
        void push(int x)
        {
            if(top < size)
            {
                top++;
                arry[top] = x;
            }
        }
        int pop()
        {
            if(top > -1)
            {
                return arry[top--];
            }
        }
};
int main()
{
    stack s;
    char l;
    int p;
    cout<<"Enter Expression length : ";
    cin>>p;
    cout<<"Enter Postfix expression : ";
    for(int i=0 ; i<p ; i++)
    {
        cin>>l;

        if(l == '1')
        {
            s.push(1);
        }
        else if(l == '2')
        {
            s.push(2);
        }
        else if(l == '3')
        {
            s.push(3);
        }
        else if(l == '4')
        {
            s.push(4);
        }
        else if(l == '5')
        {
            s.push(5);
        }
        else if(l == '6')
        {
            s.push(6);
        }
        else if(l == '7')
        {
            s.push(7);
        }
        else if(l == '8')
        {
            s.push(8);
        }
        else if(l == '9')
        {
            s.push(9);
        }

        else if(l == '+' || l == '-' || l == '*' || l == '/')
        {
            int a=s.pop();
            int b=s.pop();
            if(l == '+')
            {
                a=a+b;
            }
            else if(l == '-')
            {
                a=a-b;
            }
            else if(l == '*')
            {
                a=a*b;
            }
            else if(l == '/')
            {
                a=a/b;
            }
            s.push(a);
        }

    }
    cout<<"Result is : "<<s.pop()<<endl;
}