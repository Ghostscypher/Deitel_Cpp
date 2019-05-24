#include <iostream>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
	CName = name;
}

string GradeBook::getCourseName(string name)
{
	return CourseName;
}

void GradeBook::welcome()
{
	cout << "------Welcome to grade book Version 1.2-------" << endl;
	cout << "Course Name: " << getCourseName() << endl;
	cout << "Author : G" << endl;
	cout << "Year: 2018" << endl;
}
