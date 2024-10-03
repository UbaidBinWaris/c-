#include <iostream>
using namespace std;

string language;
int index;
int current_state;

void state_1()
{
    if (index >= language.length())
    {
        cout << "\n\t" << language << " : String  NOT Accpected ! ! ! \n\n";
        return;
    }

    if (language[index] == 'a')
        current_state = 2;

    else if (language[index] == 'b')
        current_state = 4;
    else
        current_state = -1;
}
void state_2()
{
    if (index >= language.length())
    {
        cout << "\n\t" << language << " : String  NOT Accpected ! ! ! \n\n";
        return;
    }

    if (language[index] == 'a')
        current_state = 2;

    else if (language[index] == 'b')
        current_state = 3;
    else
        current_state = -1;
}
void state_3()
{
    if (index >= language.length())
    {
        cout << "\n\t" << language << " : String Accpected > > >\n\n";
        return;
    }

    if (language[index] == 'a')
        current_state = 2;

    else if (language[index] == 'b')
        current_state = 3;
    else
        current_state = -1;
}
void state_4()
{
    if (index >= language.length())
    {
        cout << "\n\t" << language << " : String  NOT Accpected ! ! ! \n\n";
        return;
    }

    if (language[index] == 'a')
        current_state = 4;

    else if (language[index] == 'b')
        current_state = 4;
    else
        current_state = -1;
}
int main()
{
    while (true)
    {
        index = 0;
        current_state = 1;
        cout << "Enter 'QUIT' to stop the program. ";
        cout << "Enter a string : ";
        cin >> language;
        if (language == "QUIT")
        {
            cout << "\nProgram is Quiting ! ! ! \n";
            return 0;
        }

        while (index < language.length() + 1)
        {
            switch (current_state)
            {
            case -1:
                cout << "\n\t" << language << " : String  Contains Invalid Characters ! ! ! \n\n";
                index = language.length() + 1;
                break;

            case 1:
                state_1();
                break;

            case 2:
                state_2();
                break;

            case 3:
                state_3();
                break;

            case 4:
                state_4();
                break;

            default:
                cout << "Code have some Errors and working ! ! !" << endl;
                return 0;
            }
            index++;
        }
    }
}