#include<iostream>
using namespace std;
class Geometry
{ 
public:
    double area;
    double perimeter;
    virtual void calculate_area() = 0;
    virtual void calculate_perimeter() = 0;
};
class Rectangle : public Geometry
{
private:
    double length;
    double breadth;

public:
    Rectangle(double l , double b)
    {
        length = l;
        breadth = b;
    }
    void calculate_area()
    {
        area = length * breadth;
        cout<<"\nArea of Rectangle is : "<<area<<endl;
    }
    void calculate_perimeter()
    {
        perimeter = 2 * (length + breadth);
        cout<<"Perimeter of Rectangle is : "<<perimeter<<endl<<endl;
    }
};
class Circle : public Geometry
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }
    void calculate_area()
    {
        area = 3.14 * radius * radius;
        cout<<"\nArea of Circle is : "<<area<<endl;
    }
    void calculate_perimeter()
    {
        perimeter = 2 * 3.14 * radius;
        cout<<"circumference of Circle is : "<<perimeter<<endl<<endl;
    }
};
class Triangle : public Geometry
{
private:
    double base;
    double height;
    double hypo;

public:
    Triangle(double b, double he , double hy)
    {
        base = b;
        height = he;
        hypo = hy;
    }
    void calculate_area()
    {
        area = 0.5 * base * height;
        cout<<"\nArea of Triangle is : "<<area<<endl;
    }
    void calculate_perimeter()
    {
        perimeter = height + base + hypo;
        cout<<"Peramiter of Triangle is : "<<perimeter<<endl<<endl;
    }
};
int main()
{
    Rectangle r(10,20);
    r.calculate_area();
    r.calculate_perimeter();

    Circle c(10);
    c.calculate_area();
    c.calculate_perimeter();

    Triangle t(10,20,30);
    t.calculate_area();
    t.calculate_perimeter();
}