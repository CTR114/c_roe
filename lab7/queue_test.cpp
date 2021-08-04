/*
*  queue_test.cpp
*
*  Unit Tests for queue class -- Lab 7 Part 1
*
*  Student name: Chris Roe
*  Date: March 14 2017
*/

#include <cassert>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "queue.h"

using namespace std;
using namespace main_savitch_8B;

namespace generic
{
// TEMPLATE FUNCTION TO HELP US WITH TESTING
// Use with number types -- see tests for basic functionality below.
// Makes it easy to create a long queue of unique string items based
// on the integers 0 through CAPACITY-1
template < class T > std::string to_string(const T& n)
{
    // put n into a stream, then return the .str() result (string
    // equivalent of n)
    std::ostringstream stm;
    stm << n;
    return stm.str();
}

// EXAMPLE OF USING generic::to_string...
// int main()
// {	 	  	 	  	   	    	  	      	 	
//     std::cout << generic::to_string(1234) << '\n'
//               << generic::to_string(1234.56) << '\n';
// }

}  // end namespace generic

static const std::size_t CAPACITY = queue::CAPACITY;

void test_basic_functionality1()
{
    string test = "  basics.test.1: create an empty queue (empty, size)";
    cout << test << endl;
}

void test_basic_functionality2()
{
    string test = "  basics.test.2: create a 1-item queue (empty, size)";
    cout << test << endl;

    queue q1;
    assert(q1.empty());
    q1.push("yo");
    assert(q1.size() == 1);
    assert(q1.front() == "yo");
    assert(!q1.empty());
    assert(q1.size() == 1);  // check that front() did not change size
}

void test_basic_functionality3()
{
    string test = "  basics.test.3: create a 1-item queue, then pop";
    cout << test << endl;

    queue q1;
    assert(q1.empty());
    q1.push("yo");
    q1.pop();
    assert(q1.empty());
    assert(q1.size() == 0);
}	 	  	 	  	   	    	  	      	 	

void test_basic_functionality4()
{
    string test = "  basics.test.4: create a 3-item queue, then pop three times";  // NOLINT
    cout << test << endl;

    queue q1;
    q1.push("ants");
    q1.push("buy");
    q1.push("coffee");
    assert(q1.size() == 3);
    assert(q1.front() == "ants");
    q1.pop();
    assert(q1.size() == 2);
    assert(q1.front() == "buy");
    q1.pop();
    assert(q1.size() == 1);
    assert(q1.front() == "coffee");
    q1.pop();
    assert(q1.empty());
}

void test_basic_functionality5()
{
    string test = "  basics.test.5: large numbers of pops and pushes";  // NOLINT
    cout << test << endl;

    string str;
    queue q1;

    for (int i = 0; i < CAPACITY; i++)
    {
        str =  generic::to_string(i);
        q1.push(str);
    }
    assert(q1.size() == CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
    {	 	  	 	  	   	    	  	      	 	
        str = generic::to_string(i);
        assert(q1.front() == str);
        q1.pop();
    }
    assert(q1.empty());
    for (int i = 0; i < CAPACITY; i++)
    {
        str = generic::to_string(i);
        q1.push(str);
    }
    assert(q1.size() == CAPACITY);
    for (int i = 0; i < CAPACITY - 1; i++)
    {
        str = generic::to_string(i);
        assert(q1.front() == str);
        q1.pop();
    }
    assert(q1.size() == 1);
    assert(!q1.empty());
    assert(q1.front() == generic::to_string(CAPACITY - 1));
}

void test_basic_functionality()
{
    cout << "\nTesting queue basics (empty, push, pop, front size)"
         << " . . ." << endl;

    // Test 1: create an empty queue (empty, size)
    test_basic_functionality1();

    // Test 2: create a queue of size 1 (push, front, empty, size)
    test_basic_functionality2();

    // Test 3: create a queue of size 1, then pop (empty, size)
    test_basic_functionality3();

    // Test 4: create a queue of size 3, then pop three times and check
    test_basic_functionality4();

    // Test 5: large number of pops and pushes -- so next_index is
    // exercised
    test_basic_functionality5();

    cout << ". . . queue basics are OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_copy_constructor1()
{
    string test = "  copy.constructor.test.1: empty queue";
    cout << test << endl;

    queue q1;
    queue q2(q1);
    assert(q2.empty());
}

void test_copy_constructor2()
{
    string test = "  copy.constructor.test.2: 1-item queue";  // NOLINT
    cout << test << endl;

    queue q1;
    q1.push("ziggy");
    queue q2(q1);

    assert(q2.front() == "ziggy");
    assert(q2.size() == 1);
}

void test_copy_constructor3()
{
    string test = "  copy.constructor.test.3: many pushes/pops to make size 3 before copying";  // NOLINT
    cout << test << endl;

    queue q1;
    string str;

    for (int i = 0; i < CAPACITY - 1; i++)
    {
        str = generic::to_string(i);
        q1.push(str);
    }	 	  	 	  	   	    	  	      	 	

    for (int i = 0; i < CAPACITY - 1; i++)
    {
        str = generic::to_string(i);
        q1.pop();
    }
    assert(q1.empty());

    q1.push("eat");
    q1.push("more");
    q1.push("vegetables");

    queue q2(q1);   // activate the copy constructor

    assert(q2.front() == "eat");
    q2.pop();
    assert(q2.front() == "more");
    q2.pop();
    assert(q2.front() == "vegetables");
    q2.pop();
    assert(q2.empty());
}

void test_copy_constructor4()
{
    string test = "  copy.constructor.test.4: full queue"; // NOLINT
    cout << test << endl;

    string str;
    queue q1;
    q1.push("a");
    q1.push("a");
    q1.pop();
    q1.pop();

    // make a full queue
    for (int i = 0; i < CAPACITY; i++)
    {	 	  	 	  	   	    	  	      	 	
        str = generic::to_string(i);
        q1.push(str);
    }
    // activate copy constructor
    queue q2(q1);
    for (int i = 0; i < CAPACITY; i++)
    {
        assert(q2.front() == generic::to_string(i));
        q2.pop();
    }
    assert(q2.empty());
}

void test_copy_constructor5()
{
    string test = "  copy.constructor.test.5: test that copy and original are independent";  // NOLINT
    cout << test << endl;

    queue q1;
    q1.push("ants");
    q1.push("buy");
    q1.push("coffee");
    q1.pop();
    q1.push("now");

    queue q2(q1);
    assert(q2.size() == q1.size());
    q2.pop();
    assert(q2.size() != q1.size());
    assert(q2.front() == "coffee");
    assert(q1.front() == "buy");
}

void test_automatic_copy_constructor()
{
    cout << "\nTesting automatic copy constructor" << " . . ." << endl;

    // Test 1: copy an empty queue
    test_copy_constructor1();

    // Test 2: copy a queue of length 1, with first at index 0
    test_copy_constructor2();

    // Test 3: copy a 3-item queue with first at index CAPACITY - 1
    test_copy_constructor3();

    // Test 4: copy a full queue with first at index 2
    test_copy_constructor4();

    // Test 5
    test_copy_constructor5();

    cout << ". . . copy constructor is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_stream_output1()
{
    string test = "  stream.output.test.1: 3-item queue";
    cout << test << endl;

    stringstream out;
    string correct, actual;
    queue q1;
    q1.push("cat");
    q1.push("monkey");
    q1.push("tortoise");
    correct = "queue of size 3:\ncat\nmonkey\ntortoise\n";

    out << q1;      // activate stream output
    actual = out.str();
    assert(actual == correct);
}

void test_stream_output2()
{
    string test = "  stream.output.test.2: << chaining";
    cout << test << endl;

    stringstream out;
    string correct, actual;
    queue q1;
    q1.push("cat");
    q1.push("monkey");
    q1.push("tortoise");
    correct = "queue of size 3:\ncat\nmonkey\ntortoise\n";

    out << q1 << q1;        // activate chaining
    correct = correct + correct;
    actual = out.str();
    assert(actual == correct);
}	 	  	 	  	   	    	  	      	 	

void test_stream_output3()
{
    string test = "  stream.output.test.3: empty queue";
    cout << test << endl;

    stringstream out;
    string correct, actual;
    queue q1;

    correct = "queue of size 0:\n";
    out << q1;
    actual = out.str();
    assert(actual == correct);
}

void test_stream_output()
{
    cout << "\nTesting stream output operator (<<) . . ." << endl;

    // Test 1: queue of size 3
    test_stream_output1();

    // Test 2: chaining
    test_stream_output2();

    // Test 3: stream output for empty queue
    test_stream_output3();

    cout << ". . . stream output OK!" << endl;
}

void test_exceptions1()
{
    string test = "  exceptions.test.1: when popping an empty queue";
    cout << test;

    try {	 	  	 	  	   	    	  	      	 	
        queue q1;
        q1.pop();       // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions2()
{
    string test = "  exceptions.test.2: when fronting an empty queue";
    cout << test;

    try {
        queue q1;
        q1.front();     // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions3()
{
    string test = "  exceptions.test.3: when pushing a full queue";
    cout << test;

    try {
        string str;
        queue q1;

        for (int i = 0; i < CAPACITY; i++)
        {
            str =  generic::to_string(i);
            q1.push(str);
        }	 	  	 	  	   	    	  	      	 	
        q1.push("Hey, I'm full.");      // should throw domain_error
    } catch (domain_error&  e) {
        cout << " ... ok" << endl;
        return;
    }
    assert(false);      // shouldn't make it here;
}

void test_exceptions()
{
    cout << "\nTesting that exceptions are thrown when necessary . . ."
         << endl;

    // Test 1: pop an empty queue
    test_exceptions1();

    // Test 2: front() an empty queue
    test_exceptions2();

    // Test 3: push a full queue
    test_exceptions3();

    cout << ". . . exception throwing is OK!" << endl;
}
void test_full1()
{
    queue q1;
    assert(q1.empty());
    assert(q1.full() == false);
}

void test_full2()
{
    queue q1;
    assert(q1.empty());
    q1.push("ants");
    q1.push("buy");
    q1.push("coffee");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    assert(q1.full() == true);
}	 	  	 	  	   	    	  	      	 	
void test_full3()
{
    queue q1;
    assert(q1.empty());
    q1.push("ants");
    q1.push("buy");
    q1.push("coffee");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    q1.push("ants");
    assert(q1.full() == false);
}
void test_full4()
{	 	  	 	  	   	    	  	      	 	
    queue q1;
    assert(q1.empty());
    q1.push("ants");
    assert(q1.full() == false);
}

void test_full()
{
    cout << "\nTesting full . . ." << endl;

    test_full1(); // testing empty list  = false
    test_full2(); // testing list full == true 
    test_full3(); // testing list of 29 == false
    test_full4(); // testing list of 1 == false 


    cout << ". . . full is OK!" << endl;
}

void test_equiv_inequiv1()
{
    queue q1;
    q1.push("Hanover");
    queue q2;
    q2.push("Hanover");
    q2.push("Panthers");
    assert(q1 != q2);
}
void test_equiv_inequiv2()
{
    queue q1;
    queue q2;
    assert(q1 == q2);
    assert(!(q1 != q2));
}
void test_equiv_inequiv3()
{	 	  	 	  	   	    	  	      	 	
    queue q1;
    q1.push("Hanover");
    queue q2;
    q2.push("Hanover");
    assert(q1 == q2);
}
void test_equiv_inequiv4()
{
    queue q1;
    q1.push("Hanover");
    queue q2;
    q2.push("over");
    assert(q1 != q2);
}
void test_equiv_inequiv5()
{
    queue q1;
    q1.push("Hanover");
    q1.push("Hanov");
    q1.push("Han");
    queue q2;
    q2.push("Hanover");
    q2.push("Hanov");
    q2.push("Han");
    assert(q1 == q2);
}
void test_equiv_inequiv6()
{
    queue q1;
    q1.push("Hanover");
    q1.push("Hanov");
    q1.push("Han");
    queue q2;
    q2.push("Hanover");
    q2.push("Hanov");
    q2.push("Hanoverian");
    assert(q1 != q2);   
}	 	  	 	  	   	    	  	      	 	

void test_equiv_inequiv7()
{
    queue q1;
    queue q2;
    for (int i = 0; i < CAPACITY; i++)
    {
        q1.push("chris");
        q2.push("chris");
    }
    assert(q1 == q2);

}
void test_equiv_inequiv8()
{
    queue q1;
    q1.push("Push");
    q1.pop();
    queue q2;
    for (int i = 0; i < CAPACITY ; i++) 
    {
        q1.push("Hanover");
    }
    for (int i = 0; i < CAPACITY -1 ; i++) 
    {
        q2.push("Hanover");
    }
    q2.push("roe");
    assert(q1 != q2);
}

void test_equiv_inequiv()
{
    cout << "\nTesting equivalence, inequivalence . . ." << endl;
    //Test 1:testing different lengths !=
    test_equiv_inequiv1();
    //Test2:testing empty list are ==
    test_equiv_inequiv2();
    //Test3:testing list length 1 are ==
    test_equiv_inequiv3();
    //Test4:testing list length 1 are !=
    test_equiv_inequiv4();
    //Test 5:testing list length of 3 are ==
    test_equiv_inequiv5();
    //Test 6:testing list length 3 are != , different last
    test_equiv_inequiv6();
    //Test7:testing list length capacity ==
    test_equiv_inequiv7();
    //Test8: list length capacity != 
    test_equiv_inequiv8();
    

    cout << ". . . equivalence and inequivalence OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

void test_reverse1()
{
    queue q1;
    q1.push("Chris");
    q1.push("lucas");
    q1.reverse();
    assert(q1.front() == "lucas");
}
void test_reverse2()
{
    queue q1;
    q1.push("Chris");
    q1.push("Roe");
    q1.push("panther");
    q1.push("lucas");
    q1.push("Miller");
    q1.reverse();
    assert(q1.front() == "Miller");
}
void test_reverse3()
{
    queue q1;
    for (int i = 0; i <CAPACITY - 1; i++)
    {
        q1.push("Chris");
    }
    q1.push("lucas");
    q1.reverse();
    assert(q1.front() == "lucas");

}
void test_reverse()
{
    cout << "\nTesting reverse . . ." << endl;
    test_reverse1(); // reverse queue of 1
    test_reverse2(); // reverse queue of 5
    test_reverse3(); // reverse queue of CAPACITY

    cout << ". . . reverse is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	
void test_automatic_assignment_operator1()
{
    queue q1;
    q1.push("chris");
    queue q2;
    q2 = q1;
    assert(q2.front() == "chris");

}
void test_automatic_assignment_operator2()
{
    queue q1;
    q1.push("chris");
    q1.push("Roe");
    q1.push("lucas");
    queue q2;
    q2 = q1;
    assert(q1 == q2);
}
void test_automatic_assignment_operator3()
{
    queue q1;
    for (int i = 0; i < CAPACITY; i++)
    {
        q1.push("Chris");
    }
    queue q2;
    q2 = q1;
    assert(q1 == q2);
}

void test_automatic_assignment_operator()
{
    cout << "\nTesting automatic assignment operator (=) . . ." << endl;

    test_automatic_assignment_operator1(); // copy queue of 1
    test_automatic_assignment_operator2(); // copy queue at 3
    test_automatic_assignment_operator3(); // copy queue at CAPACITY
    cout << ". . . assignment is OK!" << endl;
}	 	  	 	  	   	    	  	      	 	

int main()
{
    // complete tests provided
    test_basic_functionality();
    test_automatic_copy_constructor();
    test_stream_output();
    test_exceptions();

    // tests not provided -- students need to implement
    test_full();
    test_equiv_inequiv();
    test_reverse();
    test_automatic_assignment_operator();

    cout << "\nAll current tests are passing!  Need to add more??" << endl;
}
