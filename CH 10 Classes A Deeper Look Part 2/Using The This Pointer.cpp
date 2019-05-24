#include <iostream>
using namespace std;

class Test
{
public:
	Test(int = 0); // Default Constructor
	void print() const; // Print the value of x (Prototype)
private:
	int x; // Private member
}; // End class test

Test::Test(int value)
: x(value) // Intitialize x to value
{
	// Empty body
} // End constructor function

// Print x using implicit and explicit this pointers.
// The parentesis around the '*this' are required
void Test::print() const
{
	// Implicitly use this operator to access the member x 
	cout << "Implicitly x = " << x;
	
	// Explicitly use the this operator and arrow operator to access the member x
	cout << "\nExplicitly \'this->x\' x = " << this->x;
	
	//Explicitly use the dereferenced this operator and the dot operator to
	// access member x
	cout << "\nExplicitly and dereferenced \'(*this).x\' x = " << (*this).x << endl;
} // End print

int main()
{
	Test testObject(12); // Instatntiate and initialize test object
	
	testObject.print(); // output the value of x
} // End main