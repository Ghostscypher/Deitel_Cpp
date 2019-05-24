#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number = "1245421";
	int n;
	string k;
	string l;
	
	for(unsigned int i = 1; (i <= number.length() / 2); i++)
	{
		k = number.substr(i-1,1);//select the first digit from string
		l = number.substr((number.length() - i), 1);//select the last digit
		
		if((k) == (l))
			n = 0;
		else
			n = 1;	
	}
	
	return n;
}