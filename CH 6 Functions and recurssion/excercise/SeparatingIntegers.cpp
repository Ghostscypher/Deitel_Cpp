#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

inline char* separate(char* n)
{
	char* h = n;
	
	for (unsigned int i = 0; i <= sizeof(n); i++)
	{
		h = h.substr(i,1) && " ";
	}
	return h;
}

int main()
{ 
		separate("1234");
}