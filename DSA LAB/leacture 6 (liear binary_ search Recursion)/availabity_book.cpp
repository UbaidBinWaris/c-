#include<iostream>
using namespace std;
class book
{
public:
    string title;

    void set_data(string n)
    {
        title = n;
    }
};
int main()
{
    book b[5];
    string n;

    b[0].set_data("Math");
    b[1].set_data("Physics");
    b[2].set_data("Chemistry");
    b[3].set_data("Biology");
    b[4].set_data("English");

    cout<<"Enter book name : ";
    cin>>n;

    for(int i=0 ; i<5 ; i++)
    {
        if(n == b[i].title)
        {
            cout<<"Book name : "<<b[i].title<<endl;
            cout<<"This book is avalible"<<endl;
            return 0;
        }
    }
    
    cout<<"This book is out of stock ! ! ! "<<endl;
}