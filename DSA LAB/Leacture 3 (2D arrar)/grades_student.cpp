#include<iostream>
using namespace std;
int main()
{
    char a[4][5] = {{'A','A','B','C','B'},{'A','B','C','A','C'},{'B','B','C','B','A'},{'C','A','A','D','B'}};
    cout<<"   Student Record "<<endl;
    cout<<"students  \t\t Grades"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        cout<<"Student "<<i+1<<"\t";
        for(int j=0 ; j<7 ; j++)
        {
            cout<<"  "<<a[i][j];
        }
        cout<<endl;
    }
}
