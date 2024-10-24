#include <iostream>
using namespace std;

int main()
{
    int a[4][2] = {{1, 2},
                   {3, 1},
                   {2, 2},
                   {2, 2}};

    int index = 0;
    int current_state = 0;
    string language;
    cout << "Enter string : ";
    cin >> language;

    while (index != language.length())
    {
        if (language[index] == 'a')
        {
            current_state = a[current_state][0];
        }
        else if (language[index] == 'b')
        {
            current_state = a[current_state][1];
        }
        else
        {
            cout << "string contains invalid characters ! ! ! ";
            return 0;
        }
        index++;
    }
    if (current_state == 3)
    {
        cout << "String Accpected > > > " << endl;
    }
    else
    {
        cout << "string NOT Accpected ! ! ! " << endl;
    }
}