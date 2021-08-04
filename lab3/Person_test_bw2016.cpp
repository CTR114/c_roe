//  Person_test.cpp
//
//  Unit Tests for CS 223, Winter 2016, Lab 3, Pt. 2.
//
//  Barb Wahl, 1-26-15

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
void test_basic_methods() {
   Person p1;  // 0-arg
   Person p2("Abe", "Lincoln"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   assert(p1.getFirstName() == "J");
   assert(p2.getFirstName() == "Abe");
   assert(p3.getFirstName() == "Mary");
   assert(p1.getLastName() == "Doe");
   assert(p2.getLastName() == "Lincoln");
   assert(p3.getLastName() == "Poppins");
   assert(p1.getAge() == 0);
   assert(p2.getAge() == 0);
   assert(p3.getAge() == 10);
   p1.setFirstName("Bill");
   p1.setLastName("Smith");
   p1.setAge(25);
   assert(p1.getFirstName() == "Bill");

   assert(p1.getLastName() == "Smith");
   assert(p1.getAge() == 25);
}

void test_getFullName() {
   Person p1;  // 0-arg
   Person p2("Abe", "Lincoln"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   assert(p1.getFullName() == "J Doe");
   assert(p2.getFullName() == "Abe Lincoln");
   assert(p3.getFullName() == "Mary Poppins");
}

void test_agePerson() {
   Person p1;  // 0-arg
   Person p2("Abe", "Lincoln"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   p1.agePerson(); // now J Doe is 1
   p2.agePerson(); // now Abe Lincoln is 1
   p3.agePerson(); // now Mary Poppins is 11
   assert(p1.getAge() == 1);
   assert(p2.getAge() == 1);
   assert(p3.getAge() == 11);
}

// test < operator
void test_lessThan() {
   // test 1: different last names
   Person p2("Abe", "Lincoln"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   assert(p2 < p3);
   assert(!(p3 < p2));

   // test 2: same last names, different first names
   p2.setLastName("Poppins");
   assert(p2 < p3);
   assert(!(p3 < p2));

   // test 3: same full names, different ages
   p2.setFirstName("Mary");
   assert(p2 < p3);
   assert(!(p3 < p2));

   // test 4: same full names, same ages
   p2.setAge(p3.getAge());
   assert(!(p2 < p3));
   assert(!(p3 < p2));
}

// test == and != operators together
void test_equalsUnequals() {
   // test 1: different last names
   Person p2("Abe", "Lincoln"); // 2-arg
   Person p3("Mary", "Poppins", 10); // 3-arg
   assert(p2 != p3);
   assert(!(p2 == p3));

   // test 2: same last names, different first names
   p2.setLastName("Poppins");
   assert(p2 != p3);
   assert(!(p2 == p3));

   // test 3: same full names, different ages
   p2.setFirstName("Mary");
   assert(p2 != p3);
   assert(!(p2 == p3));

   // test 4: same full names, same ages
   p2.setAge(p3.getAge());
   assert(!(p2 != p3));
   assert(p2 == p3);
}

void test_addition() {
   Person abe("Abe","Lincoln",40);
   Person mary("Mary","Contrary",45);
   Person baby;
   baby = abe + mary;
   assert(baby.getFullName() == "Baby Lincoln-Contrary");
   assert(baby.getAge() == 0);

   Person mary2("Mary","X",40);
   Person bob("Bob","Y",40);
   Person baby2;
   baby2 = mary2 + bob;
   assert(baby2.getFullName() == "Baby X-Y");
   assert(baby2.getAge() == 0);
}

// test stream I/O
// This is tricky since we haven't discussed stringstreams, so all tests are
// provided.  You don't need to add more tests, but write the implementations
// in Person.cpp for Extra Credit.
void test_streamIO()
{
   // 1. Create local variables:
   //  - a stringstream for input, called in
   //  - a stringstream for output, called out
   //  - a string for storing the expected message, called correct
   //  - a Person with specific name and age, called p
   stringstream in, out;
   string correct;
   Person p("Zoe", "Davis", 16);

   // 2. Store the expected message in the string variable "correct"
   // Get it exactly right!
   correct = "Person: Zoe Davis, age 16\n";

   // 3. Use the output stream variable "out" and the operator "<<" to
   // (hopefully) put the expected message for person "p" into the stream
   out << p;

   // 4. Inside an assert, test whether the "out.str()" result (.str() converts
   // stream to string) equals the expected message string, "correct".
   string actual = out.str();
   // here's a 'friendly' test:
   assert(actual == correct || (actual + "\n") == correct ||
      (correct + "\n" == actual));

   // 5. To test stream input, use the input stream variable "in" and the
   // operator "<<" to store an approprate message such as,
   // "Person: Abe Lincoln, age 50\n"
   in << "Person: Abe Lincoln, age 50\n";

   // 6. Use the input stream variable "in" and the operator ">>" to
   // change the person "p"
   in >> p;

   // 7. Use asserts to test that the first name, last name, and age of "p"
   // now match the information that you fed into "in" in step 5.
   assert(p.getFirstName() == "Abe" &&
          p.getLastName() == "Lincoln" &&
          p.getAge() == 50);
}

int main() {
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

   test_equalsUnequals();
   cout << "equalsUnequals passed" << endl;

   test_addition();
   cout << "addition passed" << endl;

   test_lessThan();
   cout << "lessThan passed" << endl;

   test_streamIO();
   cout << "streamIO passed" << endl;

   cout << "All current tests passing!" << endl;
   return 0;
}
