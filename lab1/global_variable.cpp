// Chris Roe
// 1/17/12
#include <iostream>

using namespace std;
int dostuff ()
{
	return 2+3;
}

int count_of_function_calls = 0;
void fun ()
{
	count_of_function_calls++;
}
int main()
{
	fun();
	fun();
	fun();
	cout<< "function fun was called"
		<< count_of_function_calls<< "times";
}
