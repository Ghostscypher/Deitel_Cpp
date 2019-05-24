#include "overloaded"
using namespace std;

ostream &operator<<(ostream &out, const Over &num)
{
	cout << "\nThe prefix of the word is " << num.prefix
		 << " and the word is: " << num.word;

    return out;
}

istream &operator>>(istream &in, Over &num)
{
	in >> num.prefix;
	in.ignore();
	in >> num.word;
	
	return in;
}