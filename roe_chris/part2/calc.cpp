//Chris roe 
// 1/11/17

#include <iostream>
using namespace std;
int main()

{
	double num1;
	double num2;
	string a;

	cout << "what is the first number";
	cin>> num1;
	cout << "what is the second number";
	cin>> num2;
	cout << "what operation would you like to do?";
	cin>> a;
	if (a== "+")
	{
		cout <<"The answer is:" <<(num1 + num2);
	}
	else if (a=="-")
	{
		cout <<"The answer is:"<<(num1 -num2);
	}
	else if (a== "*")
	{
		cout <<"The answer is:" <<(num1 *num2);
	}
	else if (a== "/")
	{
		cout <<"The answer is:" <<(num1 /num2);
	}
	else
	{
		cout<< "This was not a correct operation";
	}	 	  	 	  	   	    	  	      	 	
}