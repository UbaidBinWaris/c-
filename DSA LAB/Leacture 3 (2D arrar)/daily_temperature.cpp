#include<iostream>
using namespace std;
int main()
{
    int a[3][7] = {{36,38,38,39,40,37,39},{36,38,38,39,40,37,39},{36,38,38,39,40,37,39}};
    cout<<"   Temperature Record "<<endl;
    cout<<"Cities  \t Days"<<endl;
    for(int i=0 ; i<3 ; i++)
    {
        cout<<"City "<<i+1<<"\t";
        for(int j=0 ; j<7 ; j++)
        {
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
}
