#include<iostream>
#include"stack.h"
using namespace std;
int menu()
{
    int choice;
    cout<<"\t\t< < < DVDs Shelf > > >"<<endl<<endl;
    cout<<" 1.\tADD to DVD Shelf"<<endl;
    cout<<" 2.\tDELETE the top DVD from Shelf"<<endl;
    cout<<" 3.\tDisplay all DVDs form the shelf"<<endl; 
    cout<<" 4.\tTop DVD in the shelf"<<endl;
    cout<<" 5.\treverse the order of DVDs"<<endl;
    cout<<" 0.\tExit"<<endl<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    return choice;
}
void display_pop(string p)
{
    cout<<"DVD Deleted : "<<p<<endl;
}
void display_top(string p)
{
    cout<<"Top DVD in the shelf is : "<<p<<endl;
}
stack :: stack()
{
	index=-1;
	cap = 100;
	arry = new string [cap];
}
void stack ::  push(string d)
{
	if(index < cap)
	{
		index++;
        arry[index] = d;
		
	}
	else
	{
		cout<<"Stack is full"<<endl;
	}
}
string stack ::  top()
{
	if(!empty())
	{
		return arry[index];
	}
}		
string stack ::  pop()
{
	if(!empty())
    {
		index--;
		return arry[index+1];
    }
}
int stack ::  size()
{
	return index+1;
}
string stack ::  display()
{
	if(!empty())
	{
		cout<<" < < < List of Stack > > >"<<endl<<endl;
		for(int i=0 ; i<index+1 ; i++)
		{
			cout<<i+1<<" .\t"<<arry[i]<<endl;
		}
	}
			
}
bool stack ::  empty()
{
	if(index == -1)
	{
		cout<<"! ! ! stack is empty ! ! ! "<<endl;
		return true;
	}
	return false;
}
void stack ::  reverse()
{
	if(!empty())
	{
		if(index<1)
		{
			cout<<"Stack contains only one element and cannot be ordered in reversed"<<endl;
			return;
		}
		string temp;
		cout<<"Reverse the Stack"<<endl<<endl;
    	for(int i=0 ; i<index ; i++)
    	{
    	    temp = arry[i];
    	    arry[i] = arry[index-i];
    	    arry[index-i] = temp;
    	}
		cout<<"\n\nReverse Secussfully"<<endl;
	}
}