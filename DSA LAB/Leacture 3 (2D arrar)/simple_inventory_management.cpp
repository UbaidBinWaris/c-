#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    string a[3][3];
    
    a[0][0]="Apple";
    a[1][0]="Orahnge";
    a[2][0]="Mango";

    a[0][1]="10";
    a[1][1]="3";
    a[2][1]="0";

    a[0][2]="600";
    a[1][2]="1500";
    a[2][2]="3000";

    cout<<" -------------------------------------"<<endl;
    cout<<" Products  |  Quantity  |     Price  |"<<endl;
    cout<<" -------------------------------------"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            cout<<setw(10)<<a[i][j]<<" | ";
        }
        cout<<endl;
    }
}