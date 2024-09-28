#include<iostream>
using namespace std;
class BankAccount
{
private:
    int accountNumber;
    string name;
    string accountType;
    double balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        name = "NULL";
        accountType = "NULL";
        balance = 0;
    }
    BankAccount(int accountNumber, string name, string accountType, double balance)
    {
        this->accountNumber = accountNumber;
        this->name = name;
        this->accountType = accountType;
        this->balance = balance;
    }
    void depositemoney(double m)
    {
        balance = balance + m;
        cout << "Transaction Successful" << endl;
        cout << "now your new balance is : " << balance << endl;
    }
    void withdrawmoney(double m)
    {
        if (m > balance)
        {
            cout << "Insufficient Balance" << endl;
            return;
        }
        balance = balance - m;
        cout << "Transaction Successful" << endl;
        cout << "Remaining Balance : " << balance << endl<<endl;
    }
    void withdrawmoney(double m , double fee)
    {
        if (m+fee > balance)
        {
            cout << "Insufficient Balance" << endl;
            return;
        }
        balance = balance - m - fee;
        cout << "Transaction Successful" << endl;
        cout << "Remaining Balance : " << balance << endl<<endl;
    }
    void display()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Name : " << name << endl;
        cout << "Account Type : " << accountType << endl;
        cout << "Balance : " << balance << endl;
        cout << endl;
    }
};
int main()
{
    BankAccount b1(2212,"ALI","Default",1000);
    
    do
    {
        int ch;
        double m;
        cout<<"Bank managnment system"<<endl<<endl;
        cout<<"1.Deposit money"<<endl;
        cout<<"2.Withdraw money"<<endl;
        cout<<"3.Withdraw money with fee"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter money to deposit : ";
                cin>>m;
                b1.depositemoney(m);
                break;
            case 2:
                cout<<"Enter money to withdraw : ";
                cin>>m;
                b1.withdrawmoney(m);
                break;
            case 3:
                double fee;
                cout<<"Enter money to withdraw : ";
                cin>>m;
                cout<<"Enter Transaction fee : ";
                cin>>fee;
                b1.withdrawmoney(m,fee);
                break;
            case 4:
                b1.display();
                break;
            case 5:
                cout<<"\n\n Exiting"<<endl;
                return 0;
            default:
                cout<<"\n\nInvalid input \n\nPlease try Again\n\n\n";
        }
    } while (true);
}