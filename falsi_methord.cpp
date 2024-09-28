#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class falsi
{
public:
    int n;
    float E;
    double X, X1 , FX , FX1;

    void set_data()
    {
        X = 0;
        X1 = 1.5708;
    }
    void calculate_display()
    {
        for (n = 1; n < 20; n++)
        {
            cout << "\n\t\t\tFor n = " << n <<endl;
           
            cout << "X" << n + 1 << " = X" << n << " - [ F(X" << n << " )( X" << n << " - X" << n - 1 << " ) / ( F( X" << n << ") - f(X" << n - 1 << " ) ]" << endl;
            
            FX = X - cos(X);
            FX1 = X1 - cos(X1);
            E = (X1 - X) / X1;
            if (E < 0)
                E = E * (-1);
            E = E * 100;

            cout << "F(X" << n - 1 << ") = " << X << " - cos (" << n << ")    =   " << FX << endl;
            cout << "F(X" << n << ") = " << X1 << " - cos (" << n + 1 << ")    =   " << FX1 << endl;
            
            double X2;
            X2 = X1 - ((FX1) * (X1 - X) / (FX1 - FX));
            cout << "X" << n + 2 << " = " << X2;
            
            if (n > 1)
            {
                cout << "\nError = " <<setprecision(4)<< E << "%" << endl;
            }

            cout << "\n\tCHEAK : ";
            cout << "F(X" << n + 1 << ") * F(X"<<n << ") < 0" << endl;
            if ((FX1 * FX) < 0)
            {
                cout << "True ! ! !" << endl;
                
                
                X = X1;
                X1 = X2;
            }
            else
            {
                cout << "False > > > " << endl;
                cout << "--------------------------------------------------------------------------------------------" << endl;
                return;

            }
            cout << "--------------------------------------------------------------------------------------------" << endl;
        }

    }
};
int main()
{
    falsi f;
    f.set_data();
    f.calculate_display();

}