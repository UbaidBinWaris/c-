#include<iostream>
using namespace std;
class student
{
public:
    int id;
    string name;
    char grades;
};
int main()
{
    student s[5];

    s[0].name = "Ali";
    s[0].id = 1;
    s[0].grades = 'A';

    s[1].name = "Ahmed"; 
    s[1].id = 2;
    s[1].grades = 'B';

    s[2].name = "Mohamed";
    s[2].id = 3;
    s[2].grades = 'C';

    s[3].name = "Mohammed";
    s[3].id = 4;
    s[3].grades = 'D';

    s[4].name = "Mahmoud";
    s[4].id = 5;
    s[4].grades = 'E';

    cout<<"Enter student Id : ";
    int i;
    cin>>i;

    for(int j=0 ; j<5 ; j++)
    {
        if(s[j].id == i)
        {
            cout<<"Name           : "<<s[j].name<<endl;
            cout<<"Student ID     : "<<s[j].id<<endl;
            cout<<"Student Grades : "<<s[j].grades<<endl;
            return 0 ;        
        }
    }
    cout<<"No record found in Database ! ! ! "<<endl;

}