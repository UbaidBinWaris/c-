#include<iostream>
using namespace std;
class Shape
{
public:
    double a;
    virtual void area() = 0;
};
class circle : public Shape
{
    double r;
public:
    circle(double r)
    {
        this->r = r;
    }
    void area()
    {
        a = 3.14 * r * r;
        cout<<"Are of circle is : "<<a<<endl;
    }
};
class Rectangle : public Shape
{
    double l;
    double b;
public:
    Rectangle(double l , double b)
    {
        this->l=l;
        this->b=b;
    }
    void area()
    {
        a = l * b;
        cout<<"Are of Rectangle is : "<<a<<endl;
    }
};
class Triangle : public Shape
{
    double base;
    double height;
public:
    Triangle(double b , double h)
    {
        this->base = b;
        this->height = h;
    }
    void area()
    {
        a = 0.5* base * height;
        cout<<"Are of Triangle is : "<<a<<endl;
    }
};
class Square : public Shape
{
    double l;
public:
    Square(double l)
    {
        this->l = l;
    }
    void area()
    {
        a = l * l;
        cout<<"Are of Square is : "<<a<<endl;
    }
};
int main()
{
    Shape *s;
    
    circle c(5);
    s = &c;
    s->area();

    Rectangle r(5,6);
    s = &r;
    s->area();

    Triangle t(5,6);
    s = &t;
    s->area();

    Square sq(5);
    s = &sq;
    s->area();
}