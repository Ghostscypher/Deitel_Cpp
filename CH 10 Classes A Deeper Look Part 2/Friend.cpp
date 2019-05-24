#include <iostream>
using namespace std;

// Class Count definition

class Count
{
	friend void setX(Count &, int); // Friend declaration
public:
	// Constructor
	Count()
		: x(0) // Initialize x at 0
	{
		// Empty Body
	} // End Constructor Function

	// Output X

	void print() const
	{
		cout << x << endl;
	}

	// Destructor
	~Count()
	{
		// Empty Body
	} // End of Destructor function
private:
	int x; // data member
}; // End class count

// Function setX can modify private data of count because setX is declared as a
// friend of count
void setX(Count &c, int value)
{
	c.x = value; // Allowed because setX is a friend of count
} // End function setX

int main()
{
	Count counter; // Create a count object

	cout << "Counter .x after instantiation: ";
	counter.print();

	setX(counter, 8);
	cout << "Counter .x after call to setX friend function: ";
	counter.print();
} // End main
