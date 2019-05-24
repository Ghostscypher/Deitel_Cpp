#include <iostream>
#include <string>
using namespace std;

// Start of prototype
	void getBoardName();
	void printWelcomeScreen();
// End of prototype

int main() // Default Board Name if Name is not specified in command line
{
	string boardName = "Default Board Name";
	
	// Prompt user to enter number of rows and columns
	cout << "Please enter number of rows and columns" << endl;
	cout << "Column: ";
	cin >> rows; cin.ignore();
	cout << "Rows: "; 
	cin >> column; cin.ignore();
	cout << endl;
	
	cout << boardName;
	
} // End main