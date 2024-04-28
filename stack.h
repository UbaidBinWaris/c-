#include<iostream>
#include<string>
using namespace std;

class stack
{
	private:
	    int index;
		string *arry;
		int cap;
	public:

		stack();
		void push(string d);
		string top();
		string pop();
		int size();
		string display();
        bool empty();
		void reverse();
};
