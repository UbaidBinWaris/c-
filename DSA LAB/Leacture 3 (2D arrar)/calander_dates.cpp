#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a[4][7];
    int c=1;
    cout<<"Calander "<<endl;
    cout<<" S   | M    | T    | W    | T    | F    | S    |"<<endl;
    cout<<" -----------------------------------------------"<<endl;
    while (c<=31)
    {
        for(int i=0 ; i<7 ; i++)
        {
            cout<<" "<<setw(3)<<c<<" | ";
            c++;
            if(c>31)
            {
                return 0;
            }
        }
        cout<<endl;
    }
}