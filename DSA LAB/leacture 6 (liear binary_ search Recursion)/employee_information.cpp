#include<iostream>
using namespace std;
class employee
{
public:
    string name;
    int id;
    long int contact_no;

    void set_data(string n , long int c , int i)
    {
        name=n;
        id = i;
        contact_no=c;
    }
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Phone number : "<<contact_no<<endl;
    }
};
int main()
{
    employee e[5];
    int n;
    e[0].set_data("Ali", 3456789 , 1);
    e[1].set_data("Ahmed", 3456789 , 2);
    e[2].set_data("Afaq", 3456789 , 3);
    e[3].set_data("Haider", 3456789 , 4);
    e[4].set_data("Rizwan", 3456789 , 5);

    cout<<"Enter ID : ";
    cin>>n;

    for(int i=0 ; i<5 ; i++)
    {
        if(n == e[i].id)
        {
            e[i].display();
            return 0;
        }
    }
    
    cout<<"No Employee record found ! ! ! "<<endl;
}