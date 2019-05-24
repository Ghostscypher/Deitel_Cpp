#include <iostream>
#include <string>

using namespace std;

class GradeBook // start of class GradeBook
{
private://functions below this identifier are only available locally i.e. accessed only by this class only
	   string CName;//set coursename variable for this class only
protected:
	
public://functions below this identifier are accessible by any other functions via this class. i.e. public
		
	GradeBook(string name)//start of constructer
	{
		setCourseName(name);
	}//end of constructer function
	
	void welcome()//Welcomes the user to our class
	{
		cout << "------Welcome to grade book Version 1.2-------" << endl;
		cout << "Course Name: " << getCourseName() << endl;
		cout << "Author : G" << endl;
		cout << "Year: 2018" << endl;
	}//end of welcome function
	
	//function that sets the course name
	void setCourseName(string name)//start of set course name function
	{
		CName = name;
	}//end of setcoursename function
	
	//function that gets the coursename
	string getCourseName()
	{
		return CName;
	}//end of getcoursename function
	
};//End of class GradeBook. Note the semicolon