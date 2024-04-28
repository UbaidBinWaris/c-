#include<iostream>
using namespace std;
class contact
{
public:
    string name;
    long int contact_no;

    void set_data(string n , long int c)
    {
        name=n;
        contact_no=c;
    }
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Phone number : "<<contact_no<<endl;
    }
};
int main()
{
    contact c[5];
    string n;
    c[0].set_data("Ali", 3456789);
    c[1].set_data("Ahmed", 3456789);
    c[2].set_data("Afaq", 3456789);
    c[3].set_data("Haider", 3456789);
    c[4].set_data("Rizwan", 3456789);

    cout<<"Enter name : ";
    cin>>n;

    for(int i=0 ; i<5 ; i++)
    {
        if(n == c[i].name)
        {
            c[i].display();
            return 0;
        }
    }
    
    cout<<"No contact number found "<<endl;
}