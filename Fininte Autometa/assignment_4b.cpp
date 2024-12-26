#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input;
int i = -1;
stack<char> pdaStack;

void Read1();
void Read2();
void pop1();
void pop2();

int main()
{
    int choice;

    cout << "Enter a string use '^' for lembda : ";
    cin >> input;

    pdaStack.push('^');
    input = input + '^';

    Read1();

    return 0;
}

void Read1()
{
    i++;
    if (input[i] == '^' && input.length() == 1)
        cout << "String Accepted\n";
    if (input[i] == 'a')
    {
        pdaStack.push('a');
        Read1();
    }
    else if (input[i] == 'b')
        pop1();
    else if (input[i] == '^')
        pop2();
    else
        cout << "string Rejected";
}
void Read2()
{
    i++;

    if (input[i] == 'b')
        pop1();
    else if (input[i] == '^')
        pop2();
    else
        cout << "string Rejected";
}
void pop1()
{
    char ch = pdaStack.top();
    pdaStack.pop();

    if (ch == 'a')
        Read2();
    else
        cout << "string Rejected";
}
void pop2()
{
    char ch = pdaStack.top();
    pdaStack.pop();

    if (ch == '^')
        cout << "String Accepted";
    else
        cout << "string Rejected";
}