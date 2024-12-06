#include <iostream>
using namespace std;

class State {
public:
    State *nextA;
    State *nextB;
    bool output;

    State() {
        nextA = nullptr;
        nextB = nullptr;
        output = 0;
    }

    void setTransitions(State *a, State *b, bool out) {
        nextA = a;
        nextB = b;
        output = out;
    }
};

State q0, q1, q2, q3;
State *current;
string input;
int ctr = 0;

bool testString() {
    if (input[ctr] != 'a' && input[ctr] != 'b') {
        cout << "Invalid String Returning ! ! !" << endl;
        return false;
    }
    return true;
}

void runString(State *get_state) {
    current = get_state;

    while (ctr < input.length()) {
        cout << current->output << endl;

        if (!testString())
            return;

        if (input[ctr] == 'a') {
            current = current->nextA;
        } else if (input[ctr] == 'b') {
            current = current->nextB;
        }
        ctr++;
    }

    cout << current->output << endl;
    ctr = 0;
    cout << "String completed > > > " << endl;
}

int main() {
    q0.setTransitions(&q1, &q3, 1);
    q1.setTransitions(&q3, &q1, 0);
    q2.setTransitions(&q0, &q3, 0);
    q3.setTransitions(&q3, &q2, 1);
    current = &q0;

    while (true) {
        cout << "Enter 'exit' to terminate the program! \nEnter a String: ";
        cin >> input;
        if (input == "exit") {
            cout << "Exiting The Program < < < " << endl;
            return 0;
        }
        runString(current);
    }
}