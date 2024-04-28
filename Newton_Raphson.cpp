#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    float x=2;
    float F_X  = (pow(x,3))-12;
    float FF_X = (3*pow(x,2));
    float e;

    float X1=x-(F_X/FF_X);

    cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  | n  |\tXn \t|\t F(x) \t\t|\t FF(x)\t \t|\t Xn+1\t  |\t\tE\t|"<<endl;
    cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0 ; i<10 ; i++)
    {
        F_X  = (pow(x,3))-12;
        FF_X = (3*pow(x,2));
        X1=x-(F_X/FF_X);
        if(x == X1)
        {
            break;
        }
        cout<<setprecision(7)<<"  | "<<i+1<<"  |"<<setw(12)<<x<<"\t|\t"<<setw(12)<<setprecision(7)<<F_X<<"\t|\t"<<setw(12)<<FF_X<<"\t|\t"<<X1<<
        "  |";
        if(i>0)
        {
            e=x-X1;
            cout<<setprecision(7)<<"\t"<<setw(12)<<e<<"\t|";
        }
        else
        {
            cout<<"\t\t\t|";
        }
        cout<<endl;
        x=X1;
    }
    cout<<"  ---------------------------------------------------------------------------------------------------------------"<<endl;

}