//Chris Roe
// 1/12/17

#include <iostream>
#include <string>
using namespace std;
int main()
{
  for ( int i = 0 ; i<4; i++)
  {
    string password;
    cout<< "enter your password, note you only have 4 tries \n"; 
    getline ( cin , password ) ;
    if (password == "panthers")
    {
      cout<< "Access has been granted well done" << "\n";
      break;
    }
    else
    {
      cout<< "Bad password im sorry you may not enter \n";
    }
  }
  //continue 
}