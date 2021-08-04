// Chris Roe
// 1/17/12
#include <iostream>

using namespace std;

void changeArgument (int x)
{
	x=x+5;
}
int main()
{
	int y = 4;
	changeArgument (y); // y will be untouched by function call
	cout<< y; // still prints 4
}

