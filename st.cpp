#include<iostream>
#include"st.h"
using namespace std;
int main()
{
    stack s(5);
    s.push(50);
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(20);
    s.push(30);
    

    cout<<"Top : "<<s.peek()<<endl; 

    //s.pop();
    //s.pop();
    //s.pop();
    //s.reverse();
    //cout<<"Top : "<<s.peek()<<endl;
    s.reverse();
    cout<<"Top : "<<s.peek()<<endl;
}