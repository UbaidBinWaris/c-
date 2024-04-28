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
        void reverse()
        {
            if(top > 1)
            {
                int temp;
                for(int i=0 ; i<top/2 ; i++)
                {
                    temp = arry[top-i-1];
                    arry[top-i-1] = arry[i];
                    arry[i] = temp;
                }
            }
        }
        stack copy()
        {
            stack newStack(size);

            for (int i = 0; i < top; i++) 
            {
                newStack.arry[i] = arry[i];
            }
            newStack.top = top;
            return newStack;
        }


};

int main()
{
    stack s1(20) , s2(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();

    s1.reverse();
    s1.display();

    s2=s1.copy();
    s2.display();

}