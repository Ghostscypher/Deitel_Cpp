#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Over
{	
friend ostream &operator<<(ostream &, const Over &);
friend iostream &operator>>(iostream &, const Over &);
private:
	string prefix;
	string word;
}; // End class Over

