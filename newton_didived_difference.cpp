#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class ddtable
{
public:
    int s;
    float h;
    long double dx[10][10] = {0};

    void set_data()
    {
        cout << "Newton divide difference table " << endl
             << endl;
        cout << "Enter the number of terms : " ;
        cin >> s;
        cout << "Enter the values of x" << endl;
        for (int i = 0; i < s; i++)
        {
            cout << "x [" << i + 1 << "] = ";
            cin >> dx[0][i];
            cout << "F(x) [" << i + 1 << "] = ";
            cin >> dx[1][i];

            cout << endl;
        }
        system("cls");

        /*s = 7;
        dx[0][0] = 1.0;
        dx[0][1] = 1.1;
        dx[0][2] = 1.2;
        dx[0][3] = 1.3;
        dx[0][4] = 1.4;
        dx[0][5] = 1.5;
        dx[0][6] = 1.6;

        dx[1][0] = 7.989;
        dx[1][1] = 8.403;
        dx[1][2] = 8.781;
        dx[1][3] = 9.129;
        dx[1][4] = 9.451;
        dx[1][5] = 9.75;
        dx[1][6] = 10.031;*/
    }
    bool cheak()
    {
        h = dx[0][1] - dx[0][0];
        float p;
        for (int i = 0; i < s - 1; i++)
        {
            p = dx[0][i + 1] - dx[0][i];
            if (h != p)
            {
                cout << "\n\n\t\tError ! ! !" << endl;
                return false;
            }
        }
        return true;
    }
    void calculate()
    {
        long double p = h;
        for (int i = 0; i < s - 1; i++)
        {
            for (int j = 0; j < s - 1 - i; j++)
            {
                dx[i + 2][j] = (dx[i + 1][j + 1] - dx[i + 1][j]) / p;
            }
            p = p + h;
        }
    }
    void display()
    {
        cout << "\n\n\t\t\t\tNewton Divided Difference Table" << endl;
         cout<<"\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout << "\t\t\t x\t\t\tF(x)\t\t\t\t\tDD Table" << endl;
        cout<<"\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        for (int i = 0; i < s; i++)
        {
            cout<<"  \t\t  "<<setw(10)<<dx[0][i]<<" \t\t "<<setw(10)<<dx[1][i];
            for(int j=2 ; j<s+1-i ; j++)
            {
                cout << "  \t\t" <<setw(10)<< dx[j][i];
            }
            cout<<endl<<endl;
        }
         cout<<"\t\t----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    }
};
int main()
{
    ddtable table;
    table.set_data();
    if (!table.cheak())
    {
        return 0;
    }
    table.calculate();
    table.display();
}