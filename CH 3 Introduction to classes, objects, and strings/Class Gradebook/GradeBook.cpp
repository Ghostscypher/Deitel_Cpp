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

#include <iostream>

using namespace std;

class GradeBook // start of class GradeBook
{
private://functions below this are only available locally i.e. accessed only bu this class only
	
protected:
	
public://function that come below this identifier are accessible by any other functions via this class. i.e/ public
	void welcome(string course_name)//Welcomes the user to our class
	{
		cout << "------Welcome to grade book Version 1.1-------" << endl;
		cout << "Course Name: " << course_name << endl;
		cout << "Author : G" << endl;
		cout << "Year: 2018" << endl;
	}
	 	
};//End of class GradeBook. Note the semicolon

int main()
{
	GradeBook myGBook;//create a gradebook object named myGBook
	string coursename;//create string variable
	
	cout << "Enter your course name: ";
	getline(cin, coursename);//read a course name that may or may not contain blanks
	myGBook.welcome(coursename);//call our welcome screen
}//end main function