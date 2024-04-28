#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "aaa.h"
using namespace std;

void load_data_file(LinkedList lk)
{
	car c;
	ifstream infile;
    infile.open("data.txt",ios::app);
    if (infile.is_open())
    {
        string line;
        while (eof()!=0)
        {
			getline(infile,line);
			c.name=line;
			getline(infile,line);
			c.numplate=line;
			getline(infile,line);
			c.overspeeding=line;
			getline(infile,line);

			lk.AddNode(c);
        }
        infile.close();
    }
}
int main() {


	LinkedList lk;
	car c;
	char inp = 0;
	string numplate;
	do {
		cout << "Press 1 to add cars in database. " << endl;
		cout << "Press 2 to view the challans. " << endl;
		cout << "Press 3 delete for a specific record. " << endl;
		cout << "Press 4 search for a specific record. " << endl;
		cout << "Press 5 check the speedtrap history. " << endl;
		cout << "Press 6 to Exit " << endl << endl;
		cout << "Enter an input: ";
		cin >> inp;
		//cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		system("cls");

		switch (inp) 
		{
			case '1':
				try
				{
					cout << "Enter the name of the car: " << endl;
					cin>>c.name;
					cout << "Enter the number plate: " << endl;
					getline(cin, c.numplate);
					cout << "Enter 1 for over speeding or 0 for not overspeeding: " << endl;
					cin >> c.overspeeding;
					lk.AddNode(c);
					cout << "Car added successfully. " << endl;

				}catch(const exception &e)
					{
						cerr << "Exception occurred: " << e.what() << endl;
						system("cls");
						cout << "Something went wrong! Please try again" << endl;
						system("pause");
						system("cls");
					}

				break;

			case '2':
				if (lk.Empty()==nullptr)
				{
					break;
				}
				break;

			case '3':
				if (lk.Empty()==nullptr)
				{
					break;
				}
				cout << "Enter the number plate of the car " << endl;
				getline(cin, numplate);
				lk.DeleteNode(numplate);
				cout << "Match found and deleted. " << endl;

				break;

			case '4':
				if (lk.Empty() == nullptr) 
				{
					break;
				}
				cout << "Enter the number plate of the car to get details" << endl;
				getline(cin, numplate);
				lk.PrintSpecific(numplate);

				break;

			case '5':
				if (lk.Empty()==nullptr)
				{
					break;
				}
				lk.Print();
				break;

			case '6':
				cout << "Exiting the program " << endl;
			return 0;

			default:
				cout << "Wrong input! Please enter a correct input " << endl;
		}
		system("pause");
		system("cls");

	} while(true);
}