#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base class for all employees
class Employee {
protected:
    string name;
    int id;
public:
    Employee(const string& name, int id) : name(name), id(id) {}

    virtual double calculateSalary() const = 0;

    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id;
    }

    virtual ~Employee() = default;

    string getName() const { return name; }
    int getId() const { return id; }
};

// Derived class for full-time employees
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
public:
    FullTimeEmployee(const string& name, int id, double salary) 
        : Employee(name, id), monthlySalary(salary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void display() const override {
        Employee::display();
        cout << ", Monthly Salary: " << monthlySalary << endl;
    }
};

// Derived class for part-time employees
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(const string& name, int id, double rate, int hours) 
        : Employee(name, id), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void display() const override {
        Employee::display();
        cout << ", Hourly Rate: " << hourlyRate << ", Hours Worked: " << hoursWorked << endl;
    }
};

// Payroll Management System
class PayrollSystem {
private:
    static const int MAX_EMPLOYEES = 100;
    Employee* employees[MAX_EMPLOYEES];
    int employeeCount;

public:
    PayrollSystem() : employeeCount(0) {}

    void addEmployee(Employee* employee) {
        if (employeeCount < MAX_EMPLOYEES) {
            employees[employeeCount++] = employee;
        } else {
            cerr << "Cannot add more employees, maximum capacity reached." << endl;
        }
    }

    void calculateSalaries(const string& outputFilename) {
        ofstream outFile(outputFilename);
        if (!outFile.is_open()) {
            cerr << "Could not open file for writing: " << outputFilename << endl;
            return;
        }

        for (int i = 0; i < employeeCount; ++i) {
            outFile << "Name: " << employees[i]->getName() << ", ID: " << employees[i]->getId() << ", Salary: " << employees[i]->calculateSalary() << endl;
        }

        outFile.close();
    }

    ~PayrollSystem() {
        for (int i = 0; i < employeeCount; ++i) {
            delete employees[i];
        }
    }

    void displayAllEmployees() const {
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->display();
        }
    }
};

int main() {
    PayrollSystem payrollSystem;

    // Example employees
    payrollSystem.addEmployee(new FullTimeEmployee("Hassan", 1, 3000.0));
    payrollSystem.addEmployee(new PartTimeEmployee("Mir Hamza", 2, 20.0, 100));

    // Display all employees
    payrollSystem.displayAllEmployees();

    // Calculate salaries and store in file
    payrollSystem.calculateSalaries("salaries.txt");

    return 0;
}
