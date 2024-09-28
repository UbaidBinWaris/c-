#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollno;
    int marks[5];
    char grade;

    Student() {
        name = "";
        rollno = 0;
        for (int i = 0; i < 5; ++i) {
            marks[i] = 0;
        }
        grade = 'F';
    }

    void calculateGrade() {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += marks[i];
        }
        double average = sum / 5.0;

        if (average >= 90) grade = 'A';
        else if (average >= 80) grade = 'B';
        else if (average >= 70) grade = 'C';
        else if (average >= 60) grade = 'D';
        else grade = 'F';
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Grade: " << grade << endl << endl;
    }
};

void saveNameAndGrade(const string& filename, const string& name, char grade) {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cout << "Failed to open file for writing: " << filename << endl;
        return;
    }

    outfile << name << ", " << grade << endl;
    outfile.close();
}

int main() {
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Could not load data from file" << endl;
        cout << "Exiting" << endl;
        return 0;
    }

    ofstream outFile("grades.txt", ios::trunc); // Open the file in trunc mode to clear existing content
    outFile.close();

    while (!file.eof()) {
        Student s1;
        getline(file, s1.name);
        if (s1.name.empty()) {
            continue; // Skip any empty lines
        }
        file >> s1.rollno;
        for (int i = 0; i < 5; ++i) {
            file >> s1.marks[i];
        }
        file.ignore(); // Ignore the newline character after reading marks

        s1.calculateGrade();
        s1.display();

        saveNameAndGrade("grades.txt", s1.name, s1.grade);
    }

    file.close();
    return 0;
}
