//  Person_test.cpp
//
//  Unit Tests for CS 223, Winter 2016, Lab 3, Pt. 2.
//
//  <Chris Roe 1/26/17>

#include <cassert>
#include <sstream>
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// test together:
//    constructor
//    getFirstName
//    getLastName
//    getAge
//    setFirstName
//    setLastName
//    setAge
void test_basic_methods() 
{
   // try using the constructor with 3 arguments
   Person p3("Mary", "Poppins", 10);
   assert(p3.getFirstName() == "Mary");
   assert(p3.getLastName() == "Poppins");
   assert(p3.getAge() == 10);

    // Try constructor with 2 arguments

   Person p4("Chris","Roe");
   assert(p4.getFirstName() == "Chris");
   assert(p4.getLastName()== "Roe");
   assert(p4.getAge()==0);


   Person p5("----","455",1000);
   assert(p5.getFirstName() == "----");
   assert(p5.getLastName()== "455");
   assert(p5.getAge()==1000);


   // add more tests
}	 	  	 	  	   	    	  	      	 	

void test_getFullName()
{
   Person p17("Chris", "Roe", 18);
   p17.getFullName()== "Chris Roe";

}

void test_agePerson()
{
   Person p19("J","k", 18);
   p19.agePerson();
   assert(p19.getAge()== 19);

   Person p0("J","k", 0);
   p0.agePerson();
   assert(p0.getAge()== 1);

}

// test < operator
void test_lessThan() 
{
   // test 1: different first names, equal last names
   Person p2("Abe", "Lincoln");
   Person p3("Mary", "Lincoln");
   assert(p2 < p3);
   assert(!(p3 < p2));

   // last < ,first same, age same
   Person p4("Mary", "Aincoln",18);
   Person p5("Mary", "Lincoln",18);
   assert(p4 < p5);
   assert(!(p5 < p4));
   
   // testing age
   Person p6("Mary", "Lincoln",0);
   Person p7("Mary", "Lincoln",19);
   (p6 < p7);
}	 	  	 	  	   	    	  	      	 	

// test == and != operators together
void test_equalsUnequals() 
{
   // test 1: different names and age
   Person p2("Abe"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   assert(p2 != p3);
   assert(!(p2 == p3));

   Person p22("Mary", "Stark", 10); // 2-arg
   Person p33("Mary", "Stark", 10); // 3-arg
   assert(p22 == p33);

   Person p100("Thomas","stark",10);
   Person p101("Thomas","Stark",10);
   assert(p100!=p101);

   // add more tests
}

void test_addition() 
{
   Person p17("Joe","stan",33);
   Person p18("Mary", "The man",30);
   (p17 + p18);
}


int main() 
{
   // TODO:  UNCOMMENT one test call at a time, along with its cout line.
   // Once that test is fully implemented and passing, uncomment the next
   // test call and repeat.

   cout << "Ready to try some tests . . . " << endl;

   test_basic_methods();
   cout << "basic methods passed" << endl;

   test_getFullName();
   cout << "getFullName passed" << endl;

   test_agePerson();
   cout << "agePerson passed" << endl;

   test_lessThan();
   cout << "lessThan passed" << endl;

   test_equalsUnequals();
   cout << "equalsUnequals passed" << endl;

   test_addition();
   cout << "addition passed" << endl;


   // test_streamIO();
   // cout << "streamIO passed" << endl;

   cout << "All current tests passing!" << endl;
   return 0;
}
	 	  	 	  	   	    	  	      	 	
