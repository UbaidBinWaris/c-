#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class bisection
{
public:
    int n;
    double A , B , Fa , Fb , X , Fx ;

    void set_data()
    {
        cout<<"For the Folling Function"<<endl; 
        cout<<"F(x) = ln(x)         With the roots of 0.5 and 2"<<endl<<endl;

       A=0.5;
       B=2; 
    }
    void calculate_display()
    {
        cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<" | n |\t\tA    |\t\tB     |\t      F(a)    |\t     F(b)     |\t\tX     |\t     F(x)     |    Condition   | "<<endl;
        cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl;
        for(n=0 ; n<10 ; n++)
        {
            X=(A+B)/2;
            Fa= log(A);
            Fb= log(B);
            Fx= log(X);

            cout<<setprecision(6)<<" | "<<n<<" | "<<setw(12)<<A<<"  |\t"<<setw(12)<<B<<"  |\t"<<setw(12)<<Fa<<"  |\t"<<setw(12)<<Fb<<"  |\t"<<setw(12)<<X<<"  |\t"<<setw(12)<<Fx<<"  |\t\t";
            if(Fa*Fx > 0)
            {
                cout<<"F x=b ";
                A=X;
            }
            else
            {
                cout<<"T x=a ";
                B=X;
            }
            cout<<" | "<<endl;
        }
        cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl;
    }

};
int main()
{
    bisection b1;
    b1.set_data();
    b1.calculate_display();
}