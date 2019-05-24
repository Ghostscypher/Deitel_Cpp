#include <iostream>
#include "GradeBook.h"

using namespace std;

int main()
{
	GradeBook myGBook("");//create a gradebook object named myGBook, String will be null because we will be supplying our own variable
	string coursename;//create string variable
	
	cout << "Enter your course name: ";
	getline(cin, coursename);// Read a course name that may or may not contain blanks and then use setCourseName to set the course name
	myGBook.setCourseName(coursename);
	myGBook.welcome();//call our welcome screen using getcoursename
	
	//we can also create different grade books as shown below
	GradeBook GBook1("CIT3102 Introduction to Computer Programming");//create gradebook object with a vriable already supplied
	GradeBook GBook2("CIT3150 Introduction to Computer Architecture");
	
	//print out the above
	GBook1.welcome();
	GBook2.welcome();
	
}//end main function