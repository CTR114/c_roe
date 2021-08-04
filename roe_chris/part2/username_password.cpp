// Chris Roe
// 1/11/17

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string username;
	string password;
	string username1;
	string password1;
	cout<< "enter a username:" <<"\n";
	getline(cin, username );
	cout<< "enter your password:"<<"\n";
	getline ( cin , password ) ;
	if (username== "chris" && password == "roe")
	{
		cout<< "You got it right good job!!";
		return 0;
	}
	else
	{

	}
	
	
	cout << "This is your last chance: Enter username \n ";
	getline(cin, username1 );
	cout<< "enter your password:"<<"\n";
	getline ( cin , password1 ) ;
	if (username1=="chris" && password1== "roe")
	{
		cout<< "Good job you have passed";
		return 0;
	
	}	 	  	 	  	   	    	  	      	 	
	else
	{
		cout<< "You are out of guesses im sorry:" <<"\n";
	}
}
		