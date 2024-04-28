#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file("afaq.txt");
    if(!file)
    {
        cout<<"Error";
        //return ;
    }
    string ss;
    while(getline(file,ss))
    {
        cout<<ss<<endl;
    }
    file.close();
}