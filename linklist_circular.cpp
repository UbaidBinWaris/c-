#include<iostream>
#include"linklist_circular.h"
using namespace std;
int main()
{
    list l;
    //l.insert(10);
    l.display();
    
    l.insert(10);
    l.insert(20);
    l.insert(30);

    l.display();
    cout<<"Found : "<<l.search(5)<<endl;
}
