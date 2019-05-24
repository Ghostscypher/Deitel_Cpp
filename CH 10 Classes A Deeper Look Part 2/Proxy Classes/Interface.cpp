#include "Implimentation.h"
#include "Interface.h"

Interface::Interface(int v)
: ptr (new Implimentation(v)) // Initialize ptr to point to a new implimentation object
{
	// Empty body
} // End constructor

// Call Implimentation's setValue function
void Interface::setValue(int v)
{
	ptr->setValue(v);
} // End function setValue

// Call Implimentation's getValue function
int Interface::getValue() const
{
	return ptr->getValue();
} // End function getValue

// Destructor
Interface::~Interface()
{
	delete ptr;
} // End ~Interface destructor