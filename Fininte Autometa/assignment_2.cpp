#include<iostream>
using namespace std;

int main()
{
    int a[4][2] = {{1,4},{2,1},{0,0},{0,0}};

    int index = 0;
    int current_state =0;
    string n;
    cout << "Enter string : ";
    cin >> n;

    while(index+1 == n.length() )
    {

        current_state = a[current_state][index];
        index++;
    }
    if(current_state == 3)
    {
        cout << "The string is accepted by the language." << endl;
    }

return 0;
    


}