#include <iostream>
#include <stdexcept>
#include "Array.h"
using namespace std;

int main()
{
	Array Integer(7); // Seven element array
	Array Integer2; // 10-Element array by default
	
	// print object 'Integer1' size and contents
	cout << "Size of Integer1 is: "
		 << Integer.getSize
		 << "\nAfter initialization" << Integer;
		 
   // Print Integer2 size and contents
   cout << "Size of Integer is: "
        << Integer2.getSize
        << "\nAfter initialization" << Integer2;
		 
    // Prompt user to Input and print Integer and Integer2 (17 Values)
   cin >> Integer >> Integer2;
   
   // Print values Integer and Integer2 after input
   cout << "\nAfter input, the arrays contain"
   	   << "\nInteger:\n" << Integer
   	   << "\nInteger2:\n" << Integer2 << endl;
   	   
   // Use overloaded inequality(!=) operator
   cout << "\nEvaluating Integer != Integer2" << endl;
   if (Integer != Integer2)
   	cout << "Not Equal";
   else
   	cout << "Equal";
   
   // Create another Array object Integer3 and use object Integer as initializer
   // print size and contents
   Array Integer3(Integer); // Invokes copy constructor
   cout << "\nSize of array Integer3 is"
   	   << Integer3.getSize
   	   << "\nArray after initialization:\n" << Integer3;
   	   
  // Use overloaded operator(=)
  cout << "Assigning Integer to Integer2:" << endl;
  Integer = Integer2; // N.B. Left operand is smaller to prevent 'out of range' error
  
  cout << "\nInteger:\n" << Integer
  	  << "\nInteger2\n" << Integer2;
  	  
  // Using overloaded equality operator (==)
  cout << "\nEvaluating Integer == Integer2" << endl;
  if (Integer == Integer2)
  	cout << "Equal";
  else
  	cout << "Not Equal";
  
  // Use overloaded subscript operator to create rvalue
  cout << "\nInteger[5] is " << Integer[5];
  
  // Use overloaded subscript operator to create lvalue
  cout << "\n\nAssigning 1000 to Integer[5]" << endl;
  cout << "\nInteger:\n" << Integer;
  
  // Attempt to use out of range subscript
  try
  {
	cout << "\n\nAttempt to assign 1000 to Integer[15]" << endl;
	Integer[15] = 1000; // Error subscript out of range
  }
  catch (out_of_range &e)
  {
  	cout << "An error occured: " << e.what() << endl;
  } // End try...catch
} // End main