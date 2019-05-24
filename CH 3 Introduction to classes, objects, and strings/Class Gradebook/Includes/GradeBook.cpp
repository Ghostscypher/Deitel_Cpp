#include <iostream>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
	if (name.length() <= 25)
	{
        CourseName = name;
	}
	else
	{
		CourseName = name.substr(0, 25);
		cout << "The name is greater than 25 characters long" << endl;
	}
}

string GradeBook::getCourseName()
{
	return CourseName;
}

void GradeBook::welcome()
{
	cout << "------Welcome to grade book Version 1.3-------" << endl;
	cout << "Course Name: " << getCourseName() << endl;
	cout << "Author : G" << endl;
	cout << "Year: 2018" << endl;
}
