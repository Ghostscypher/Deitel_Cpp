#ifndef EMP_H
#define EMP_H

#include <string>
#include "Date.h"
using namespace std;

class Employee
{
public:
	Employee(const string &, const string &, const Date &, const Date &);
	void print() const;
	~Employee();
private:
	string firstName; // composition: Member object
	string lastName; // composition: Member object
	const Date birthDate; // composition: Member object
	const Date hireDate; // composition: Member object
};
#endif