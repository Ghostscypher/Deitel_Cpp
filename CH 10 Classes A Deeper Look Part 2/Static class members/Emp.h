#ifndef EMP_H
#define EMP_H

#include <string>
using namespace std;

class Employee
{
public:
	Employee(const string &, const string &);
	string getFirstName() const;  // Return first name
	string getLastName() const; // Return last name
	
	// Static member function
	static int getCount(); // return the number of objects instantiated
	
	~Employee();
private:
	string firstName; // composition: Member object
	string lastName; // composition: Member object
	
	// Static data
	static int count; // Number of objects instatiated
}; // End class employee
#endif