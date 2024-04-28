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
            top = -1;
            size = s;
            arry = new int [size];
        }
        void push(int d)
        {
            if(top+1 < size)
            {
                top++;
                arry[top]=d;
            }
        }
        int mininum()
        {
            if(top<1)
            {
                return -1;
            }
            int temp=arry[0];
            for(int i=0 ; i<=top ; i++)
            {
                if(temp > arry[i])
                {
                    temp=arry[i];
                }
            }
            return temp;
        }
};
int main()
{
    stack s(2);
    s.push(10);
    s.push(11);

    cout<<"Mininim Number in stack is : "<<s.mininum()<<endl;
}