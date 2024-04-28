#include<iostream>
#include<string>
#include"stack.h"
using namespace std;
int menu();
void display_pop(string p);
void display_top(string p);
int main()
{
    string n;
    stack s;
    do
    {
        switch(menu())
        {
        case 1:
            cout<<"Enter DVD name : ";
            getline(cin,n);
            s.push(n);
            break;
        case 2:
            n=s.pop();
            display_pop(n);
            break;
        case 3:
            s.display();
            break;
        case 4:
            n=s.top();
            display_top(n);
            break;
        case 5:
            s.reverse();
            break;
        case 0:
            return 0;
        default:
            cout<<"Invalid choice ! ! ! Please Try Again"<<endl;
        }

        cout<<endl<<endl;
        system("pause");
        system("cls");
    } while(true);
    
}
