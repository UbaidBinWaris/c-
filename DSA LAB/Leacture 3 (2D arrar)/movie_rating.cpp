#include<iostream>
using namespace std;
int main()
{
    float a[2][3];
    cout<<"   Movie Rating "<<endl;
    cout<<"Enter Rating out of 10 "<<endl;
    
    for(int i=0 ; i<2 ; i++)
    {
        cout<<"Movie "<<i+1<<"\n";
        for(int j=0 ; j<3 ; j++)
        {
            cout<<"Rating : ";
            cin>>a[i][j];
        }
        cout<<endl;
    }

    cout<<"Movies \t  Ratting "<<endl;
    for(int i=0 ; i<2 ; i++)
    {
        cout<<"Movie "<<i+1<<"\t";
        for(int j=0 ; j<3 ; j++)
        {
            cout<<"  "<<a[i][j];
        }
        cout<<endl;
    }
}
