//chris Roe
// 1/22/17



#include <iostream>
#include <string>
using namespace std;

void Min (const string& str, const string& str1, const& str2)
{
	if (str<=str1 && str<= str2)
	{
		cout<< "The minimum is:"<< str;
	}
	else if (str1<=str && str1<=str2)
	{
		cout<< "The minimum is:"<< str1;
	}
	else if (str2<=str && str2<=str1)
	{
		cout<< "The minimum is:"<< str2;
	}

}

void count()
{
	int arr[10];
	for (int i=0; i<10; i++)
	{
		string j;
		cout<< "Please enter a sentence or phrase";
		getline(cin,j);
		arr[i] = j.length();
	}

	double acc = 0;
	double average = 0;
	for (int i=0; i<10; i++)
	{	 	  	 	  	   	    	  	      	 	
		acc = arr[i];
	}
	average = acc/10;

	int min = arr[0];
	for (int i=1; i<0;i++)
	{
		if (arr[i]<min)
		{
			min = arr[i];
		}
		

	}


	int max = arr[0];
	for (int i= 1; i<0; i++)
	{
		if (arr[i] > max)
		{
			max=arr[i];
		}
	}


	cout<< "The average string length is"<<average;
	cout<< "The maximum string length is"<<max;
	cout<< "The minimum string length is"<<min;

}

void substring (const string& string1, const string& string2)
{
	if (string1 == string2)
	{	 	  	 	  	   	    	  	      	 	
		cout<< "The strings are equal \n";
	}
	else if (string1.find(string2) != string::npos )
	{
		cout<< "the first string is a substring to the second \n";
	}
	else if ( string2.find(string1) != string::npos)
	{
		cout<< "the second string is a substring of the first \n";
	}
	else if (string1 == "" && string2 == "")
	{
		cout<< "Neither is a substring";
	}
	else
	{
		cout<< "Neither string is a substring";
	}

}

int main()
{
	string str;
	string str1;
	string str2;

	cout<< "enter a string";
	getline(cin,str);
	cout<< "enter a string";
	getline(cin,str1);
	cout<< "enter a string";
	getline(cin,str2);

	min(str,str1,str2);

	count();

	string string1;
	string string2;
	cout<< "Enter a string";
	getline(cin,string1);
	cout<< "Enter a string";
	getline(cin,string1);

	substring(string1, string2);

	cout<< "Goodbye \n";
}	 	  	 	  	   	    	  	      	 	
