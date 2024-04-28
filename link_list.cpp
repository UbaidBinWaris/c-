#include<iostream>
#include"link_list.h"
using namespace std;
int main()
{
    list l;
    //l.display();

    cout<<"List size : "<<l.size()<<endl;
    l.insert(10);

    //l.display();

    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);

    l.display();
    //cout<<"Is found : "<<l.search(10)<<endl;
    //cout<<"List size : "<<l.size()<<endl;
    //l.remove(50);
    //l.display();
    //cout<<"List size : "<<l.size()<<endl;
    l.insert_index(0,5);
    l.display();
    l.insert_index(2,15);
    l.display();
    l.insert_index(9,90);
    l.display();

    list l2;
    l2=l;

    l2.display();
    //l2++;
    l2.display();

    l2.remove_index(6);
    l2.display();

    l2.reverse();
    l2.display();
}