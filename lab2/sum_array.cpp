//chris Roe
//1/17/17

#include <iostream>
using namespace std;


int sumarray(int values[],int size)
{
	int sum= 0;
	for (int i=0; i<size;i++)
	{
		sum+=values[i];
	}
	return sum;
}

int main()
{
	int values[10];
	for (int i=0; i<10; i++)
	{
		cout<< "Enter value" << i<< ":";
		cin>> values[i];
	}
	cout<< sumarray(values,10)<< endl;
}
