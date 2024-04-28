#include<iostream>
using namespace std;
class stack
{
    public:
        int  size;
        int *arry;
        int top;

        stack(int s)
        {
            size=s;
            arry= new int[s];
            top=0;
        }
        void push(int d)
        {
            arry[top]=d;
            top++;
        }
        void display()
        {
            cout<<"Stack Elelemants"<<endl;
            for(int i=0 ; i<top ; i++)
            {
                cout<<arry[i]<<" ";
            }
            cout<<endl;
        }
        int pop()
        {
            top--;
            return arry[top];
        }

};
int main()
{
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();

    int a=0;
    a=s.pop();
    cout<<"Delete "<<a<<endl;
    a=s.pop();
    cout<<"Delete "<<a<<endl;
    a=s.pop();
    cout<<"Delete "<<a<<endl;
    a=s.pop();
    cout<<"Delete "<<a<<endl;

}