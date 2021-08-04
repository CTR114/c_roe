//Chris roe
//1/11/17


#include <iostream>
#include <string>
using namespace std;
int main()
{
	string password;
	cout<< "enter your password:"<<"\n";
	getline ( cin , password ) ;
	if (password == "panthers")
	{
		cout<< "Access has been granted well done" << "\n";
	}
	else
	{
		cout<< "Bad password im sorry you cant enter";
		cout<< password ;
		cout<< "was not correct" << "\n";
		//returning is a good way to stop the program
		return 0;
	}
	//continue 
}