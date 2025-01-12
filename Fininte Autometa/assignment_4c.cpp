#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> stk;
char ch;
int ctr;
string state;
string str;
bool exitFlag;

bool read1();
bool read2();
bool pop1();
bool pop2();

int main()
{
    cout << "Enter the string: ";
    cin >> str;

    str += '#'; // Append '#' to the end of the string
    stk.push('#');

    ctr = 0;
    state = "R1";
    exitFlag = false;

    while (!exitFlag)
    {
        if (state == "R1")
            exitFlag = read1();
        else if (state == "R2")
            exitFlag = read2();
        else if (state == "P1")
            exitFlag = pop1();
        else if (state == "P2")
            exitFlag = pop2();
    }

    return 0;
}

bool read1()
{
    cout << "State: READ1, Stack: ";
    stack<char> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << ", Tape: " << str.substr(0, ctr) << endl;

    ch = str[ctr++];

    if (ch == 'a')
    {
        stk.push('a');
        cout << "State: PUSHa, Stack: ";
        temp = stk;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << ", Tape: " << str.substr(0, ctr) << endl;
        state = "R1";
    }
    else if (ch == 'b')
    {
        state = "P1";
    }
    else if (ch == '#')
    {
        state = "P2";
    }
    else
    {
        cout << "Invalid Alphabets in String" << endl;
        return true;
    }

    return false;
}

bool read2()
{
    cout << "State: READ2, Stack: ";
    stack<char> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << ", Tape: " << str.substr(0, ctr) << endl;

    ch = str[ctr++];

    if (ch == 'a')
    {
        cout << "String Rejected" << endl;
        return true;
    }
    else if (ch == 'b')
    {
        state = "P1";
    }
    else if (ch == '#')
    {
        state = "P2";
    }
    else
    {
        cout << "Invalid Alphabets in String" << endl;
        return true;
    }

    return false;
}

bool pop1()
{
    cout << "State: POP-1, Stack: ";
    stack<char> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << ", Tape: " << str.substr(0, ctr) << endl;

    ch = stk.top();
    stk.pop();

    if (ch == 'a')
    {
        state = "R2";
    }
    else if (ch == 'b' || ch == '#')
    {
        cout << "String Rejected" << endl;
        return true;
    }
    else
    {
        cout << "Invalid Alphabets in String" << endl;
        return true;
    }

    return false;
}

bool pop2()
{
    cout << "State: POP-2, Stack: ";
    stack<char> temp = stk;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << ", Tape: " << str.substr(0, ctr) << endl;

    ch = stk.top();
    stk.pop();

    if (ch == 'a' || ch == 'b')
    {
        cout << "String Rejected" << endl;
        return true;
    }
    else if (ch == '#')
    {
        cout << "String ACCEPTED !!!" << endl;
        return true;
    }

    cout << "Invalid Alphabets in String" << endl;
    return true;
}
