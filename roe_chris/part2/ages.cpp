// Chris Roe
// 1/11/17

#include <iostream>
using namespace std;
int main()
{
	double age1;
	double age2;
	cout << "how old is the first person?";
	cin>> age1;
	cout << "how old is the second person?: ";
	cin>> age2;
	if (age1 > 100 & age2>100) 
	{
		cout<< "Both users are over 100 years old\n";
	}
	
	else if (age1>age2)
	{
		cout<< "user 1 is older \n";
	}
	else if (age2>age1)
	{
		cout<< "user number 2 is older\n";
	}
	
	else if (age2=age1)
	{
		cout<< "They are the same age\n";
	}
}