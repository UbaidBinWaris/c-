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
            arry = new char [size];
        }
        void push(char ch)
        {
            if(top<size)
            {
                top++;
                arry[top]=ch;
            }
        }
        bool plaindrome()
        {
            if(top < 1)
            {
                return false;
            }
            bool cheak=false;
            for(int i=0 ; i<top/2 ; i++)
            {
                if(arry[i] == arry [top-i])
                {
                    cheak=true;
                }
                else
                {
                    return false;
                }
            }
            return cheak;
        }
};
int main()
{
    stack s(5);
    s.push('c');
    s.push('i');
    s.push('v');
    s.push('i');
    s.push('c');

    cout<<s.plaindrome();
}