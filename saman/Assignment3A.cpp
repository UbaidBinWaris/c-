#include<iostream>
using namespace std;
class vehicle
{
protected:
    string make;
    int model;
    int year;

    virtual void display() = 0;
};
class car:public vehicle
{
private:
    int seats;
    int doors;
public:
    car()
    {
        seats=0;
        doors=0;
        make="";
        model=0;
        year=0;
    }
    car(int s , int d , int m , int y , string ma)
    {
        seats=s;
        doors=d;
        make=ma;
        model=m;
        year=y;
    }
    void display()
    {
        cout<<"\nCar Model : "<<model<<endl;
        cout<<"Car Year : "<<year<<endl;
        cout<<"Car Make : "<<make<<endl;
        cout<<"number of Seats : "<<seats<<endl;
        cout<<"number of Doors : "<<doors<<endl<<endl;
    }
};
class Motercycle : public vehicle
{
private:
    string engine;
public:
    Motercycle()
    {
        engine="";
        make="";
        model=0;
        year=0;
    }
    Motercycle(string e , int m , int y , string ma)
    {
        engine=e;
        make=ma;
        model=m;
        year=y;
    }
    void display()
    {
        cout<<"\nMotercycle Model : "<<model<<endl;
        cout<<"Motercycle Year : "<<year<<endl;
        cout<<"Motercycle Make : "<<make<<endl;
        cout<<"Motercycle Engine : "<<engine<<endl<<endl;
    }
};
int main()
{
    car c1(4,4,2019,2020,"BMW");
    c1.display();
    Motercycle m1("200cc",2019,2019,"Honda");
    m1.display();
    return 0;
}