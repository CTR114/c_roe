//Chris Roe
// 1/12/17

#include <iostream>
#include <string>
using namespace std;


int check ( string pass)
{
  if (pass == "panthers")
  {
    
    return 7; 
    
  }
  else
  {
    return 3;
  }
}

    

  int main()
{
  
  for ( int i = 0 ; i<4; i++)
  {
    string pass;
    cout<< "enter your password, note you only have 4 tries \n"; 
    getline ( cin , pass ) ;
    int j = check(pass);
    if (j==7)
    {
      cout<< "access granted good job! \n";
      break;
    }	 	  	 	  	   	    	  	      	 	
    else if (j==3)
    {
      cout<<" password was incorrect \n";
    }
    
  }
  
  //continue 
}
