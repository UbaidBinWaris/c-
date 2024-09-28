#include<iostream>
using namespace std;
class client
{
public:
    string email;
};
int main()
{
    client c[5];

    c[0].email = "xyz@email.com";
    c[1].email = "abc@email.com";
    c[2].email = "pqr@email.com";
    c[3].email = "mno@email.com";
    c[4].email = "def@email.com";



    cout<<"Enter email Id : ";
    string i;
    cin>>i;

    for(int j=0 ; j<5 ; j++)
    {
        if(c[j].email == i)
        {
            cout<<"Email Found Secussfully"<<endl;
            return 0 ;        
        }
    }
    cout<<"No record found in Database ! ! ! "<<endl;

}