#include<iostream>
using namespace std;
class product
{
public:
    string name;
    bool avalible;
    int quantity;

    bool is_avalible()
    {
        if(quantity > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
int main()
{
    product p[5];

    p[0].name = "bread";
    p[0].avalible = true;
    p[0].quantity = 10;

    p[1].name = "milk";
    p[1].avalible = true;
    p[1].quantity = 10;

    p[2].name = "eggs";
    p[2].avalible = true;
    p[2].quantity = 10;

    p[3].name = "cheese";
    p[3].avalible = true;
    p[3].quantity = 10;

    p[4].name = "meat";
    p[4].avalible = true;
    p[4].quantity = 10;

    cout<<"Enter Producct name : ";
    string name;
    cin>>name;

    for(int i = 0; i < 5; i++)
    {
        if(p[i].name == name)
        {
            if(p[i].is_avalible())
            {
                cout<<p[i].name<<" is avalible"<<endl;
                cout<<"Quantity : "<<p[i].quantity<<endl;
                p[i].quantity--;
                return 0;
            }
        }
    }
    cout<<name<<" is not avalible"<<endl;
    cout<<"Out of Stock"<<endl;
    return 0;
}