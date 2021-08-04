//chris roe
// 1/21/17

#include <iostream>
#include <string>

using namespace std;


int main()
{
	string input;
	int i = 0;
	int cat = 0;
	cout<< "please enter a line of text: ";
	getline (cin, input, '\n');

	for (i = input.find ("cat", 0);
		i != string::npos;
		i = input.find("cat",i))
	{
		cat++;
		// move past the last discovered instance to avoid finding same thing twice
		i++;
	}
		
	cout<< "The word cat appears: \n" << cat<< "times in the string"<< "''"<<input<<"''";
}