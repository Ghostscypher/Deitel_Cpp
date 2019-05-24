#include <iostream>

using namespace std;

class GradeBook // Start of class GradeBook
{
private: // Functions below this are only available locally i.e. accessed only by this class only
	
protected:
	
public: // Function(s) that come below this identifier are accessible by any other functions via this class. i.e/ public
	void welcome(string course_name)//Welcomes the user to our class
	{
		cout << "------Welcome to grade book Version 1.1-------" << endl;
		cout << "Course Name: " << course_name << endl;
		cout << "Author : G" << endl;
		cout << "Year: 2018" << endl;
	}
	 	
}; // End of class GradeBook. Note the semicolon

int main()
{
	GradeBook myGBook; // Create a gradebook object named myGBook
	string coursename; // Create string variable
	
	cout << "Enter your course name: ";
	getline(cin, coursename); // Read a course name that may or may not contain blanks
	myGBook.welcome(coursename); // Call our welcome screen
} // End main function