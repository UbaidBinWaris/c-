#include<iostream>
#include"st_list.h"
using namespace std;
int main()
{
    stack s;
    //cout<<"Top : "<<s.peek()<<endl;
    s.push(10);
    //cout<<"Top : "<<s.peek()<<endl;
    //s.push(20);
    //s.push(30);
    //cout<<"Top : "<<s.peek()<<endl;
    
    s.push(20);
    /*cout<<"Top : "<<s.peek()<<endl;
    s.pop();
    cout<<"Top : "<<s.peek()<<endl;
    s.pop();
    cout<<"Top : "<<s.peek()<<endl;*/
    s.reverse();
    cout<<"Top : "<<s.peek()<<endl;

}