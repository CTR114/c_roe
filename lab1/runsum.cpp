//Chris Roe
// 1/12/17
#include <iostream>
using namespace std;
int main ()
{
	int n;
	int j;
	int times;
	 j = 1;
	cout<< "Please enter the number of times you would like to multiply";
	cin>> times;
	for(int i=0;i<times;i++)
    {
        cout << "Enter the number to multiply: \n";
        cin >> n; 
       
		j = j * n;

    }
    cout<<"The outcome is: "<< j <<endl;
}