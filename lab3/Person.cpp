//  Person.cpp
//
//  Function implementations for CS 223 Winter 2016, Lab 3, Part 2.
//
//  <Chris Roe>
//  <1/26/17>

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

// CONSTRUCTORS for the Person class:

/*
*  Person
*  Precondition: May be called with 0 parameters, 1 parameter (fname),
*                2 parameters (fname, lname), or three parameters. 
*  Precondition: fname has size 1 or more
*  Precondition: lname has size 1 or more
*  Precondition: A cannot be negative
*  Postcondition: An instance of a Person has been created with 
*                 first name `fname`, last name `lname`, and age `age`.
*/
Person::Person(string fname, string lname, int A)
{
   first=fname;
   last=lname;
   age=A;
   fname.length()> 0;
   lname.length()> 0;
   A >=0;
}


// MODIFICATION MEMBER FUNCTIONS

/*
 *  setFirstName
 *  Precondition: newName has size 1 or more
 *  Postcondition: person's first name is now newName
 */
void Person::setFirstName(string newName)
{	 	  	 	  	   	    	  	      	 	
   newName.length()>0;
   first= newName;
}

/*
 *  setLastName
 *  Precondition: newName has size 1 or more
 *  Postcondition: person's last name is now newName
 */
void Person::setLastName(string newName)
{
   newName.length()>0;
   last= newName;
}
   


/*
 *  setAge
 *  Precondition: newAge >= 0
 *  Postcondition: person's age is now newAge
 */
void Person::setAge(int newAge)
{
   newAge>=0;
   age = newAge;
}

/*
 *  agePerson
 *  Precondition: None
 *  Postcondition: person's age is now one year older
 */
void Person::agePerson()
{
   age>=0;
   age=age+1;
   
}	 	  	 	  	   	    	  	      	 	


// ACCESSOR MEMBER FUNCTIONS

/*
 *  getFirstName
 *  Precondition: None  
 *  Postcondition: person's first name is returned
 */
string Person::getFirstName() const
{
   // stub
   return first;
}

/*
 *  getLastName
 *  Precondition: None  
 *  Postcondition: person's last name is returned
 */
string Person::getLastName() const{
   // stub
   return last;
}

/*
 *  getAge
 *  Precondition: None  
 *  Postcondition: person's age is returned
 */
int Person::getAge() const
{
   // stub
   return age;
}

/*
 *  getFullName
 *  Precondition: None  
 *  Postcondition: person's full name (first and last) is returned
 *  
 *  Example:  If first name is "Chris" and last name is "Smith", return value
 *     is "Chris Smith".
 */
string Person::getFullName() const
{	 	  	 	  	   	    	  	      	 	
   // stub
   return first+" " + last;
}


// OPERATOR OVERLOADING
/*
 *  equality operator (==)
 *     
 *  Note: personA and personB are "equal" iff they have:
 *     - the same first name,
 *     - the same last name, and
 *     - the same age
 */
bool operator==(const Person &personA, const Person &personB)
{
   if (personA.getFirstName()== personB.getFirstName())
   {
      if (personA.getLastName()==personB.getLastName())
      {
         if(personA.getAge()==personB.getAge())
         {
            return true;
         }
      }
   }
   else
   {
      return false;
   }
}

/*
 * inequality operator (!=), the logical opposite of the equality operator
 *  
 *  Note:  != returns true iff == returns false
 */
bool operator!=(const Person &personA, const Person &personB)
{	 	  	 	  	   	    	  	      	 	
   if (personA.getFirstName() != personB.getFirstName())
   {
      return true;
   }
   else if (personA.getLastName()!=personB.getLastName())
   {
      return true;
   }

   else if (personA.getAge()!=personB.getAge())
         {
            return true;
         }
   else
   {
   return false;
   }
}

/*
 * strictly-less-than operator (<)
 *  
 *  Note:  personA and personB are compared as follows:
 *    - by last name: "Jane Doe, age 5" < "Jane Smith, age 5"
 *    - if last names are the same, then by first name:  "Jane Doe, age 5" < "Pete Doe, age 5"
 *    - if full names are the same, then by age:  "Jane Doe, age 5" < "Jane Doe, age 12"
 */
bool operator<(const Person &personA, const Person &personB)
{
   if (personA.getLastName()< personB.getLastName())
   {
      return true;
   }
    else if (personA.getLastName() == personB.getLastName())
   {
       if (personA.getFirstName() < personB.getFirstName())
       {	 	  	 	  	   	    	  	      	 	
         return true;
       }
   }       
   else
   {
      if (personA.getAge()< personB.getAge())
      {
         return true;
      }
   }
   return false;
}

/*
 * addition operator (+)
 *
 *  Note:  as in real life, when you add two people together you get a newborn person:
 *    - the new person's first name is "Baby"
 *    - the new person's last name is the hyphenation of the parents' last names:
 *      "Jane Doe" + "Juan Sanchez" == "Baby Doe-Sanchez, age 0"
 */
Person operator+(const Person &personA, const Person &personB)
{
   // stub

   return Person("Baby", personA.getLastName() + "-" + personB.getLastName(), 0);
}


// STREAM I/O -- IMPLEMENT THESE FOR EXTRA CREDIT
/*
 * output stream operator (<<)
 *
 * output a person to a stream
 * returns the `out` parameter to allow for chaining (see p.340-341 in textbook)
 *
 * Note:  The output consists of these pieces in the given order:
 *           "Person: "
 *            person's first name
 *            " "
 *            person's last name
 *            ", age " [with no space between last name and comma]
 *            person's age
 *            endl
 *
 * Example:  A Person named "John Doe" with age 8 would produce the output:
 *    Person: John Doe, age 8
 */
ostream& operator<<(ostream &out, const Person &person)
{	 	  	 	  	   	    	  	      	 	
   out << "stream output not implemented";
   return out;
}

/*
 * input stream operator (>>)
 *
 * read in data for a person from a stream
 * returns the `in` parameter to allow for chaining
 *    - assumes the input is formatted as specified for the output stream operator
 *    - takes data from the input stream and assigns new values to the instance
 *      variables of the person
 *
 * Example: If the input stream `in` holds the message,
 *             "Person: John Doe, age 8"
 *      then `in >> person` will cause person's data to become:
 *      first name: "John"; last name: "Doe"; age: 8
 */
istream& operator>>(istream &in, Person &person)
{
   // stub, does nothing but return `in`, unchanged
   return in;
}
