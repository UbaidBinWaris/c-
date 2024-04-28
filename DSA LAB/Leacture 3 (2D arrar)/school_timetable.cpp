#include<iostream>
using namespace std;
int main()
{
    string a[3][6];

    a[0][0]="Classes";
    a[0][1]="Monday";
    a[0][2]=" Tuesday ";
    a[0][3]=" Wednessday";
    a[0][4]="Thursday";
    a[0][5]="Friday";

    a[1][0]="SSC    ";
    a[1][1]=" Math ";
    a[1][2]=" Physics ";
    a[1][3]=" Chemistery";
    a[1][4]="Computer";
    a[1][5]="English";
    
    a[2][0]="HSSC   ";
    a[2][1]="English";
    a[2][2]="Computer";
    a[2][3]="Chemistery ";
    a[2][4]="Physics ";
    a[2][5]="  Math ";

    cout<<"Tame table"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        if(i==0 || i==1)
        {
            cout<<"--------------------------------------------------------------------------------"<<endl;
        }
        for(int j=0 ; j<6 ; j++)
        {
            cout<<" | ";
            cout<<" "<<a[i][j]<<" ";
            if(j==5)
            {
                cout<<" | ";
            }
        }
        cout<<endl;
    }

}