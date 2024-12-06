#include <iostream>
#include <fstream>
using namespace std;

string input;
int ctr = 0;
char value;
int current_state;

void state_q0();
void state_q1();
void state_q2();
void state_q3();

void load_state();
void select_state();
void update_state();

int main()
{
    while (true)
    {
        cout << "Enter 'exit' to terminate the program! \nEnter a String: ";
        cin >> input;
        if (input == "exit")
        {
            cout << "\n\n\t\t\t > > > Exiting The Program < < < " << endl;
            return 0;
        }
        ctr = 0;
        load_state();
        select_state();
        update_state();
    }
}
void select_state()
{
    switch (current_state)
    {
    case 0:
        state_q0();
        break;
    case 1:
        state_q1();
        break;
    case 2:
        state_q2();
        break;
    case 3:
        state_q3();
        break;
    default:
        cout << "Invalid State" << endl;
        break;
    }
}
void state_q0()
{
    cout << "1" << endl;
    current_state = 0;
    if (ctr >= input.length())
    {
        cout << "\tString Accepted > > >" << endl;
        return;
    }
    value = input[ctr++];
    if (value == 'a')
        state_q1();
    else if (value == 'b')
        state_q3();
    else
        cout << "Invalid String Returning ! ! !" << endl;
}
void state_q1()
{
    cout << "0" << endl;
    current_state = 1;
    if (ctr >= input.length())
    {
        cout << "\tString Accepted > > >" << endl;
        return;
    }
    value = input[ctr++];
    if (value == 'a')
        state_q3();
    else if (value == 'b')
        state_q1();
    else
        cout << "Invalid String Returning ! ! !" << endl;
}
void state_q2()
{
    cout << "0" << endl;
    current_state = 2;
    if (ctr >= input.length())
    {
        cout << "\tString Accepted > > >" << endl;
        return;
    }
    value = input[ctr++];
    if (value == 'a')
        state_q0();
    else if (value == 'b')
        state_q3();
    else
        cout << "Invalid String Returning ! ! !" << endl;
}
void state_q3()
{
    cout << "1" << endl;
    current_state = 3;
    if (ctr >= input.length())
    {
        cout << "\tString Accepted > > > " << endl;
        return;
    }
    value = input[ctr++];
    if (value == 'a')
        state_q3();
    else if (value == 'b')
        state_q2();
    else
        cout << "Invalid String Returning ! ! !" << endl;
}

void load_state()
{
    ifstream file("states.txt");
    if (!file.good())
    {
        ofstream outfile("states.txt");
        outfile << "0" << endl;
        outfile.close();
        current_state = 0;
        cout << "\t\t File created successfully with initial state 0" << endl
             << endl;
    }
    else
        file >> current_state;
    file.close();
}
void update_state()
{
    ofstream file("states.txt");
    file << current_state << endl;
    file.close();
}