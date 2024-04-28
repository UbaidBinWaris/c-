#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include "aaa.h"
using namespace std;

void menue()
{
    int option;
    cout << "Press 1 to add cars in database. " << endl;
    cout << "Press 2 to view the challans. " << endl;
    cout << "Press 3 delete for a specific record. " << endl;
    cout << "Press 4 search for a specific record. " << endl;
    cout << "Press 5 check the speedtrap history. " << endl;
    cout << "Press 6 to add challan. " << endl;
    cout << "Press 7 to Exit " << endl<<endl;
}
/*void load_data(LinkedList *lk)
{
    car c;
    string line , chal;
    fstream file("data.csv",ios::app);
    if(!file.is_open())
    {
        cout<<"Error in file opening"<<endl;
        return;
    }
    cout<<"File open secussfully"<<endl;
    string name,numberplate;
    while(file.good())
    {
        istringstream ss(line); 

        getline(ss , c.name,',');
        getline(ss , c.numplate,',');
        getline(ss , chal , '\n');

        if(chal == "true")
        {
            c.overspeeding = true;
        }
        else
        {
            c.overspeeding = false;
        }
        lk->AddNode(c);  
    }
    file.close();
    
}*/
int main()
{
    car c;
    LinkedList lk;
    //load_data(&lk);
    char inp = '0';
    bool run=true;
    do
    {
        menue();

            try
            {
                cout << "Enter an input: ";
                cin >> inp;
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                if(cin.fail())
                {
                    throw;
                }
            }
            catch(int)
            {
                cout << "\n\n Error : Invalid input ! ! ! "<<endl<<endl;

            }
            run=true;
        system("cls");
        switch (inp)
        {
            case '1':
                lk.AddCar(c);
                break;

            case '2':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                lk.displayChallans();
                break;

            case '3':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                cout << "Enter the number plate of the car " << endl;
                getline(cin, c.numplate);
                lk.DeleteNode(c.numplate);
                cout << "Match found and deleted. " << endl;
                break;

            case '4':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                cout << "Enter the number plate of the car to get details" << endl;
                getline(cin, c.numplate);
                lk.PrintSpecific(c.numplate);

                break;

            case '5':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                lk.Print();
                break;

            case '6':
                if (lk.Empty() == nullptr)
                {
                    break;
                }
                break;

            case '7':
                cout << "Exiting the program " << endl;
                run=false;
                break;

            default:
                cout << "Wrong input! Please enter a correct input " << endl;
        }
        system("pause");
        system("cls");
    }while(run);
}  