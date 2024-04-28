#include<iostream>
using namespace std;
struct car
{
    string name , numplate;
    bool overspeeding;
};
int main()
{

car c;

try
        {
            cout << "Enter the name of the car: " << endl;
            getline(cin, c.name);
            cout << "Enter the number plate: " << endl;
            getline(cin, c.numplate);
            cout << "Enter 1 for over speeding else 0 : ";
            cin >> c.overspeeding;
            if (cin.fail())
            {
                throw;
            }
        }
        catch(const exception& e)
        {
            cerr <<"Error : " <<e.what() << '\n';
        }

}