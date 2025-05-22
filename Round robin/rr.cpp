#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int n = 10;
int process[n];
int burst_time[n];

void readAndDisplayCSV()
{
    ifstream file("input.csv");
    if (!file.is_open())
    {
        cout << "Failed to open file: " << "input.csv" << endl;
        return ;
    }
    string line;
    cout << "Arrival Time\tExecution Time" << endl;
    while (getline(file, line))
    {
        stringstream ss(line);
        string arrival, execution;
        if (getline(ss, arrival, ',') && getline(ss, execution, ','))
        {
            cout << arrival << "\t\t" << execution << endl;
        }
    }
    file.close();
}

int main()
{

    // Function to read arrival and execution times from input.csv and display them

    // Call the function before reading process data
    readAndDisplayCSV("input.csv");

    for (int i = 0; i < n; i++)
    {
        cout << "Enter process ID, burst time, waiting time, and turnaround time for process " << i + 1 << ": ";
        cin >> process[i] >> burst_time[i];
    }

    cout << "Process ID\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t" << burst_time[i] << "\t\t\n";
    }

    return 0;
}