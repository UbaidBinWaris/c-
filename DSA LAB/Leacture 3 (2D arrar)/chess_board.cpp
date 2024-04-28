#include<iostream>
using namespace std;
int main()
{
    char a[8][8];

    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ; j<8 ; j++)
        {
            a[i][j]='0';
        }
    }

    for(int i=0 ; i<8 ; i++)
    {
        a[1][i]='P';
        a[6][i]='p';
    }
    a[0][0]='R';
    a[0][1]='N';
    a[0][2]='B';
    a[0][3]='Q';
    a[0][4]='K';
    a[0][5]='B';
    a[0][6]='N';
    a[0][7]='R';

    a[7][0]='r';
    a[7][1]='n';
    a[7][2]='b';
    a[7][3]='q';
    a[7][4]='k';
    a[7][5]='b';
    a[7][6]='n';
    a[7][7]='r';

    cout<<"Chess board"<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        cout<<" -----------------------------------------"<<endl;
        for(int j=0 ; j<8 ; j++)
        {
            cout<<" | ";
            if(a[i][j] == '0')
            {
                cout<<"  ";
            }
            else
            {
                cout<<a[i][j]<<" ";
            }
            if(j == 7)
            {
                cout<<" | ";
            }
            
        }
        cout<<endl;
    }
}