//Chris Roe
//1/10/17

#include <iostream>
#include <string>

using namespace std;

int main()

{
	string firstName;
	string lastName;

	cout << "please enter your first name: " ;
	cin >> firstName;
	cout << "please enter your last name: ";
	cin >> lastName;
	string fullName = firstName + " " + lastName;

	cout << "Your name is:" << fullName << "\n"; 
}