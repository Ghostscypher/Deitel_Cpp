#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
using namespace std;

int main()
{
	string s1("Happy");
	string s2(" birthday");
	string s3;
	system("Color b");
	
	// Test overloaded equality and relational operators
	cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
		 << "\"; s3 is \"" << s3 << "\""
		 << "\n\nThe results comparing s2 and s1:"
		 << "\ns2 == s1 yields: " << (s2 == s1 ? "True": "False")
		 << "\ns2 != s1 yields: " << (s2 != s1 ? "True": "False")
		 << "\ns2 > s1 yields: " << (s2 > s1 ? "True": "False")
		 << "\ns2 < s1 yields: " << (s2 < s1 ? "True": "False")
		 << "\ns2 >= s1 yields: " << (s2 >=s1 ? "True": "False")
		 << "\ns2 <= s1 yields: " << (s2 <= s1 ? "True": "False");
		 
   // Test string member function empty
   cout << "\n\nTesting s3.empty():" << endl;
   
   if (s3.empty())
   {
   		cout << "s3 is empty assigning s1 to s3;" << endl;
   		s3 = s1;
   		cout << "s3 is \"" << s3 << "\"";
   } // End if
   
   // Test overloaded string concatenation operator
   cout << "\n\ns1 + s2 yields s1 = ";
   s1 += s2;
   cout << s1;
   
   // Test overloaded 	string concatenation operator with a char * string
   cout << "\n\ns1 += \" to you\" yields" << endl;
   s1 += " to you";
   cout << "s1 = " << s1 << "\n\n";
   
   // Test string member function substr
   cout << "The substring of s1 starting at location 0 for\n"
        <<  "14 characters, s1.substr(0, 14) is: \n"
        << s1.substr(0, 14) << "\n\n";
        
  // Test copy constructor
  string s4(s1);
  cout << "\ns4 = " << s4 << endl;
  
  // Test overloaded assignment (=) operator with self assignment
  cout << "Assigning s4 to s4" << endl;
  s4 = s4;
  cout << "s4 = " << s4 << endl;
  
  // Test using overloaded subscript operator to create lvalue
  s1[0] = 'H';
  s1[6] = 'B';
  cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is:"
  	   << s1 << "\n\n";
  	   
  // Test subscript out of range with string member function "at"
  try
  {
	cout << "Attempt to assign 'd' to s1.at(30) yields:" << endl;
	s1.at(30) = 'd'; // Error subscript out of range  
  } 
  catch(out_of_range &ex)
  {
  	cout << "An exception occured: " << ex.what() << endl;
  } // End try...catch
} // End main