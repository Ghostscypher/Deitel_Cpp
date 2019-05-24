#include <iostream>
#include "CandD.h"
using namespace std;

/*The name of the destructor function is the tilde character i.e ~. Tilde
is a bitwise complement therefore using a tilde gives an intuitive of
constructor compliment. A destructor is called implicitly when the object
is destroyed. It does not actually release the object's memory. But instead
it does a little housekeeping before the object's memory is reclaimed,
so the memory may be used to hold new objects.

N.B. It is a syntax error to attempt to pass arguments to a destructor dunction,
specify a return type for it (yes even void!), or to overload the destructor


WHEN CONSTRUCTORS AND DESTRUCTORS ARE CALLED
Constructors and destructors are called implicitly by the compiler. The order in which
these function calls occur depends on the order in which execution enters and leaves the
scopes where the objects are instantiated. Generally, destructor calls are made in the reverse
order of the corresponding constructor calls, but as we’ll see in Figs. 9.11–9.13, the storage
classes of objects can alter the order in which destructors are called.


Constructors and Destructors for Objects in Global Scope
Constructors are called for objects defined in global scope before any other function (including
main) in that file begins execution (although the order of execution of global object
constructors between files is not guaranteed). The corresponding destructors are called
when main terminates. Function exit forces a program to terminate immediately and does
not execute the destructors of automatic objects. The function often is used to terminate
a program when an error is detected in the input or if a file to be processed by the program
cannot be opened. Function abort performs similarly to function exit but forces the program
to terminate immediately, without allowing the destructors of any objects to be
called. Function abort is usually used to indicate an abnormal termination of the program.
(See Appendix F for more information on functions exit and abort.)


Constructors and Destructors for Local Automatic Objects
The constructor for an automatic local object is called when execution reaches the point
where that object is defined—the corresponding destructor is called when execution leaves
the object’s scope (i.e., the block in which that object is defined has finished executing).
Constructors and destructors for automatic objects are called each time execution enters
and leaves the scope of the object. Destructors are not called for automatic objects if the
program terminates with a call to function exit or function abort.


Constructors and Destructors for static Local Objects
The constructor for a static local object is called only once, when execution first reaches
the point where the object is defined—the corresponding destructor is called when main
terminates or the program calls function exit. Global and static objects are destroyed in
the reverse order of their creation. Destructors are not called for static objects if the program
terminates with a call to function abort.*/

void create();//prototype for create

ConstructAndDestroy first(1, "(Global before main)");

int main()
{
	cout << "\nMAIN FUNCTION EXECUTION BEGINS" << endl;
	ConstructAndDestroy second(2, "(Local automatic main)");
	static ConstructAndDestroy third(3, "(Local static in main)");
	
	create();//call function to create object
	
	cout << "\nMAIN FUNCTION EXECUTION RESUMES" << endl;
	ConstructAndDestroy fourth(4, "(Local automatic in main)");
	cout << "\nMAIN FUNCTION EXECUTION ENDS" << endl;
}

void create()
{
	cout << "\nCREATE FUNCTION EXECUTION BEGINS" << endl;
	ConstructAndDestroy fifth(5, "(Local automatic in create)");
	static ConstructAndDestroy sixth(6, "(local static in main)");
	cout << "\nFUNCTION CREATE EXECUTION ENDS"<< endl;
}