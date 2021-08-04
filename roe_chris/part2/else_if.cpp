// Chris Roe
// 1/11/17

#include <iostream>
using namespace std;
int main()
{
	int num;
	cout << "Enter a number: ";
	cin>> num;
	if (num<0)
	{
		cout<< "You put in a negative number:\n";
	}
	else if (num==0)
	{
		cout<< "you entered Zero\n";
	}
	else
	{
		cout<< "You entered a positive number\n";
	}
}





