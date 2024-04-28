#include<iostream>
using namespace std;
class stack
{
    public: 
        int top;
        int *arry;
        int size;

        stack(int s)
        {
            size = s;
            top = -1;
            arry = new int [size];
        }
        void push(int d)
        {
            if(!overflow())
            {
                top++;
                arry[top]=d;
            }
        }
        bool overflow()
        {
            if(top+1 < size)
            {
                return false;
            }
            cout<<"The stack is Overflow"<<endl;
            cout<<"Could not enter more entries"<<endl;
            return true;
        }
};
int main()
{
    stack s(1);
    s.push(10);
    s.push(20);

}