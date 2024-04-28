#include<iostream>
using namespace std;
class stack
{
    public:
        int  size;
        int *arry;
        int top1;
        int top2;

        stack(int s)
        {
            size=s;
            arry= new int[s];
            top1=-1;
            top2=s;
        }
        void push1(int d)
        {
            if(top1 != top2-1)
            {
                top1++;
                arry[top1]=d;
            }
            else
            {
                cout<<"stack is full "<<endl;
            }
        }
        void push2(int d)
        {
            if(top2 > top1+1)
            {
                top2--;
                arry[top2]=d;
            }
            else
            {
                cout<<"Stack is full "<<endl;
            }
        }
        void display()
        {
            cout<<"Stack Elelemants"<<endl;
            for(int i=0 ; i<size ; i++)
            {
                cout<<arry[i]<<" ";
            }
            cout<<endl;
        }
        int peek1()
        {
            return arry[top1];
        }
        int peek2()
        {
            return arry[top2];
        }
        int pop1()
        {
            return arry[top1--];
        }
        int pop2()
        {
            return arry[top2++];
        }

};
int main()
{
    stack s1(6);
    s1.push1(10);
    s1.push1(20);
    s1.push1(30);
    
    s1.push2(40);
    s1.push2(30);
    s1.push2(40);
    s1.push2(30);
    s1.push2(40);
    s1.push1(5);

    s1.display();
    cout<<"Peek 1 : "<<s1.peek1()<<endl;

    cout<<"Peek 2 : "<<s1.peek2()<<endl;
    
    s1.display();

    cout<<"pop 1 : "<<s1.pop1()<<endl;
    cout<<"pop 1 : "<<s1.pop1()<<endl;
    cout<<"pop 2 : "<<s1.pop2()<<endl;
    cout<<"pop 2 : "<<s1.pop2()<<endl;

    s1.push2(30);
    s1.push2(40);
    s1.push1(5);

    s1.display();

}