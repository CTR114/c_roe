//Chris Roe
// 1/12/17
#include <iostream>
using namespace std;

int add (int num1,int num2)
{
	return num1+num2;
}

int multiply (int num1,int num2)
{

	return num1*num2;
}

int subtraction (int num1,int num2)
{
	return num1-num2;
}

int division (int num1,int num2)
{
	return num1/num2;
}



int main()

{
	
	int num1;
	int num2;
	string a;

	cout << "what is the first number";
	cin>> num1;
	cout << "what is the second number";
	cin>> num2;
	cout << "what operation would you like to do?";
	cin>> a;

	if (a== "+")
	{	 	  	 	  	   	    	  	      	 	
		int j = add(num1,num2);
		cout<<" The answer is"<< j<< "\n";
		
	}
	else if (a=="-")
	{
		int k = subtraction(num1,num2);
		cout<<" The answer is"<< k<< "\n";
	}
	else if (a== "*")
	{
		int r = multiply(num1,num2);
		cout<<" The answer is"<< r<< "\n";
	}
	else if (a== "/")
	{
		int h = division(num1,num2);
		cout<<" The answer is"<< h<< "\n";
	}
	else
	{
		cout<< "Im sorry invalid operator \n";
	}
}