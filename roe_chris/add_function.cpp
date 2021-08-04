//Chris Roe
//1/17/12

#include <iostream>
using namespace std;

int add (int x, int y)
{
	return x+y;
}
int main ()
{
	int result = add (1,2); // add and assign the result to a variable

	cout<< "the result is :" << result<< "\n";
	cout<< "Adding 3 and 4 gives us :" << add(3,4); 
}
