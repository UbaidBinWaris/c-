#include<iostream>
using namespace std;
class stack
{
    public:
        int top;
        char *arry;
        int size;

        stack(int s)
        {
            top = -1;
            size = s;
            arry = new char[size];
        }
        void push(char ch)
        {
            if(top < size)
            {
                top++;
                arry[top] = ch;
            }
        }
        char pop()
        {
            if(top > -1)
            {
                return arry[top--];
            }
            return '\0';
        }
        void display()
        {
            cout<<"String are : ";
            for(int i=0 ; i<size ; i++)
            {
                cout<<arry[i];
            }
            cout<<endl;
        }
};
int main()
{
    int size=2;
    stack s(size);
    char c;
    cout<<"Enter String : ";
    for(int i=0 ; i<size ; i++)
    {
        cin>>c;
        s.push(c);

    }
    cout<<"You Entered : ";
    for(int i=0 ; i<size ; i++)
    {
        cout<<s.pop();
    }

}