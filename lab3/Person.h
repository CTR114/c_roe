
/************* DO NOT CHANGE THIS FILE! *************/
#ifndef PERSON_H_
#define PERSON_H_

class Person
{
    public:
    //
    //
    // *********************** Person.h **********************
    // Class provided:  Person
    //
    // Author: Barbara Wahl
    // Date:   1-24-2016
    //
    // CONSTRUCTORS
          Person(std::string fname = "J", std::string lname = "Doe", int A = 0);
    //      Call this constructor with 0 to 3 arguments, to create a new Person
    //      Expects fname and lname to have size 1 or more, and A >= 0.

    // MODIFICATION MEMBER FUNCTIONS
          void setFirstName(std::string newName); // newName has size 1 or more
          void setLastName(std::string newName);  // newName has size 1 or more
          void setAge(int newAge);           // newAge >= 0
          void agePerson(); // makes the Person one year older

    // ACCESSOR MEMBER FUNCTIONS
          std::string getFirstName() const;
          std::string getLastName() const;
          int getAge() const;
          std::string getFullName() const;
    //
    // VALUE SEMANTICS
    //    The automatic assignment operator and copy constructor may be used with
    //    Person objects.
    //
    //    For example, if p1 and p2 are existing Person objects:
    //
    //          p2 = p1         is an assignment which changes the data for p2 to
    //                          match the data for p1, and
    //
    //          Person p3(p1)   uses the copy constructor to create a new Person
    //                          object, p3, with all the same data as p1.
    //
    //    Note that `Person p3(p1)` is equivalent to:  `Person p3 = p1`.

    // FRIEND FUNCTIONS -- explained at bottom of file
       friend std::ostream& operator <<(std::ostream& out, const Person& person);
       friend std::istream& operator >>(std::istream& in, Person& person);

    private:
       /* Instance Variables -- Private Data */
       std::string first;  // the person's first name; cannot be size 0
       std::string last;   // the person's last name; cannot be size 0
       int age;            // the person's age, in years; cannot be negative

}; // END OF PERSON CLASS

// OPERATOR OVERLOADING
    bool operator==(const Person& personA, const Person& personB);
//       equality operator (==); personA and personB are "equal" iff they have:
//          - the same first name,
//          - the same last name, and
//          - the same age
//
    bool operator!=(const Person& personA, const Person& personB);
//        inequality operator (!=); logical negation of the equality operator
//
    bool operator<(const Person& personA, const Person& personB);
//        strictly-less-than operator (<); personA and personB are compared as
//        follows:
//          1. By last name: "Jane Xa, age 5" < "Joe Z, age 2" since "Xa" < "Z".
//          2. If last names are the same, then by first name.
//          3. If full names are the same, then by age:
//               "Jane X, age 2" < "Jane X, age 37".
//
    Person operator+(const Person& personA, const Person& personB);
//        addition operator (+); as in real life, when you add two people
//        together you get a newborn person:
//          - new Person first name is "Baby"
//          - new Person last name is the hyphenation of the parents' last names:
//            "Jane Doe" + "Juan Sanchez" == "Baby Doe-Sanchez, age 0"
//
    std::ostream& operator<<(std::ostream& out, const Person& person);
//        stream output operator (<<); for example:  A Person named "John Doe"
//        with age 8 would produce the output:
//            Person: John Doe, age 8
//        note: returns the `out` parameter to allow chaining of stream output
//
    std::istream& operator>>(std::istream& in, Person& person);
//         stream input operator; for example: if the input stream `in` holds
//         the message, "Person: John Doe, age 8", then `in >> p1` will
//         cause p1's data to become:
//             - first name: "John"
//             - last name: "Doe"
//             - age: 8
//         note: returns the `in` parameter to allow chaining of stream input

#endif /* PERSON_H_ */
