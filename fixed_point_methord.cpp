#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class fixed_point
{
public:
    int n;
    float E;
    double X, X_;

    void set_data()
    {
        //for the following function e^-2x = 1.5x on x0 = 0
        E = 100;
        n = 0;
        X = 0;
        cout << "e^-2x = 1.5x on x0 = 0" << endl;
        cout << "use a gernal case Xn+1 = e^-2x / 1.5" << endl << endl;
    }
    void calculate_display()
    {
        cout << " -----------------------------------------------" << endl;
        cout << " |  n   |\tXn   |\t  Xn+1    |\tE      |" << endl;
        cout << " -----------------------------------------------" << endl;
        for (n = 0; n < 20; n++)
        {
            X_ = (exp(-2*X))/1.5;
            
            cout << " |  " <<setw(2)<< n << "  |  " <<setw(7)<<setprecision(5)<< X << "   |  " << X_ << "   |   ";
            if (n < 1)
            {
                cout << setw(10) << "|" << endl;
            }
            else
            {
                E = (X_ - X)/X_;
                if (E < 0)
                {
                    E = E * (-1);
                }
                E = E * 100;
                cout << setw(6) << setprecision(4) << E << "%  |" << endl;
                if (E < 0.9)
                {
                    cout << " -----------------------------------------------" << endl;
                    return;
                }
                
            }
            X = X_;
        }
        cout << " -----------------------------------------------" << endl;
    }
};
int main()
{
    fixed_point f;
    f.set_data();
    f.calculate_display();

}