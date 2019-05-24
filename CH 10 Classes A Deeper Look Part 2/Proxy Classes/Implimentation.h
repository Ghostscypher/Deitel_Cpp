#ifndef IMPLIMENTATION_H
#define IMPLIMENTATION_H

class Implimentation
{
public:
	// Constructor
	Implimentation (int v)
	: value(v)
	{
		// Empty body
	} // End constructor
	
	void setValue(int v)
	{
		value = v; // Should validate v
	} // End setValue
	
	// Return the value of v
	int getValue() const
	{
		return value;
	} // End getValue function
	
	~Implimentation()
	{
		// Empty body	
	} // End destructor
private:
	int value; // Data that we would like to hide from the client
}; // End class Implimentation
#endif