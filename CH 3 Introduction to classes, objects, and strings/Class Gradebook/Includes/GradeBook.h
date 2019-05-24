#include <string>
using namespace std;

class GradeBook
{
private:
	string CourseName;
public:
	GradeBook(string); // Constructor function
	void setCourseName(string); // set course name prototype
	string getCourseName(); // get course name function prototype
	void welcome(); // display message function
}; // end of class GradeBook note the semicolon
