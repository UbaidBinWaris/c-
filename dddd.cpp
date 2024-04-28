#include <iostream>
#include <limits>
#include <iomanip>
#include "aaa.h"
using namespace std;

char menu()
{
    char inp = 0;
    cout << "Press 1 to add cars in database. " << endl;
    cout << "Press 2 delete for a specific record. " << endl;
    cout << "Press 3 search for a specific record. " << endl;
    cout << "Press 4 check the speedtrap history. " << endl;
    cout << "Press 0 to Exit " << endl << endl;
    cout << "Enter an input: ";
    cin >> inp;
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    system("cls");
    return inp;
}
int main()
{
    LinkedList lk;
    string numplate;
    do
    {
        switch (menu())
        {
            case '1':
                lk.AddNode();
                break;

            case '2':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                cout<<"Enter car number plate : ";
                getline(cin,numplate); 
                lk.DeleteNode(numplate);
                cout << "Match found and deleted. " << endl;
                break;

            case '3':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                cout<<"Enter car number plate : ";
                getline(cin,numplate); 
                lk.PrintSpecific(numplate);
                break;

            case '4':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                lk.Print();
                break;

            case '0':
                cout << "Exiting the program " << endl;
                return 0;

            default:
                cout << "Wrong input! Please enter a correct input " << endl;
            }

        system("pause");
        system("cls");
    }while(true);
}