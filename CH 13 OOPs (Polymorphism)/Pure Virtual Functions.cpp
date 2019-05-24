/**
A class is made abstract by declaring one or more of its virtual functions to be 'Pure'. A pure virtual function is specified by placing a '= 0' in it's 
declaration. For example:
	virtual void draw() const = 0; // Pure virtual function
The '= 0' is a pure specifier. Pure virtual functions do not provide implimentations
Every concrete derived class must override all-base-class virtual functions with
concrete implimentation of those functions.
The difference between a virtual function and a pure virtual function is that
a virtual function has an implimentation that gives the derived class the option
of overriding the function. By contrast, a pure virtual function does not provide
an implimentation and requires the derived class to be concrete, otherwise, the
derived class remains concrete.
*/