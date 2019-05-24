#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Over
{	
public:
	friend ostream &operator<<(ostream &out, const Over &num)
	{
		cout << "\nThe prefix of the word is " << num.prefix
			 << " and the word is: " << num.word;
 
        return out;
	}
	
	friend istream &operator>>(istream &in, Over &num)
	{
		in >> num.prefix;
		in.ignore();
		in >> num.word;
		
		return in;
	}
	
private:
	string prefix;
	string word;
}; // End class Over

int main()
{
	Over o; // Intialize a class over object
	
	// Prompt user to eneter word with prefix
	cout << "Please enter the word in the form 'pre-word': ";
	cin >> o;
	
	// Print everything
	cout << o;
} // End main