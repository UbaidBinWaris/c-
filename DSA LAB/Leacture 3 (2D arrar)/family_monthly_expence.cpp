#include<iostream>
using namespace std;
int main()
{
    string a[6][6];

    a[0][0]="Month";
    a[1][0]="Jan  ";
    a[2][0]="Feb  ";
    a[3][0]="March";

    a[0][1]="Rent";
    a[0][2]="Food";
    a[0][3]="Petrol";
    a[0][4]="Cloth";
    a[0][5]="Other";

    a[1][1]="25000";
    a[1][2]="18000";
    a[1][3]="10000";
    a[1][4]="6000";
    a[1][5]="10000";

    a[2][1]="25000";
    a[2][2]="20000";
    a[2][3]="15000";
    a[2][4]="3000";
    a[2][5]="10000";

    a[3][1]="25000";
    a[3][2]="18000";
    a[3][3]="18000";
    a[3][4]="4500";
    a[3][5]="15000";

    cout<<"Family Expence sheet"<<endl;
    for(int i=0 ; i<4 ; i++)
    {
        if(i==0 || i==1)
        {
            cout<<" ------------------------------------------------------------"<<endl;
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