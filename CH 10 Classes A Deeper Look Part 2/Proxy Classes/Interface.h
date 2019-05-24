#ifndef INTERFACE_H
#define INTERFACE_H

class Implimentation; // Forward class declaration

class Interface
{
public:
	Interface(int); // Constructor
	
	// Same public interface as 'class Implimentation' has.
	void setValue(int);
	int getValue() const;
	
	~Interface(); // Destructor
private:
	// Requires previous forward declaration
	Implimentation *ptr;
}; // End class Interface
#endif