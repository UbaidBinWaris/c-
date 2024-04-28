#include<iostream>
using namespace std;

int main()
{
    int a[3][3];

    cout<<"Tic tac toe Game Board"<<endl<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        if(i ==1 || i==2)
        {
            cout<<" -----------------"<<endl;
        }
        for(int j=0 ; j<3 ; j++)
        {
            if(j ==1 || j==2)
            {
                cout<<" | ";
            }
            else
            {
                cout<<"   ";
            }
            cout<<"  ";
        }
        
        cout<<endl;
    }
}