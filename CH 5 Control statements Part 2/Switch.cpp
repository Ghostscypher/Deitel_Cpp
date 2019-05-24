#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char grade;
	
	while ((grade = cin.get()) != EOF)
	{
		switch(grade)
		{
		case 'A':
		case 'a':
			cout << 100 << endl;
			break;
		
		case 'B':
		case 'b':
			cout << 80 << endl;
			break;
		
		case 'C':
		case 'c':
			cout << 60 << endl;
			break;
		
		case 'D':
		case 'd':
			cout << 40 << endl;
			break;
		
		case ' ':
		case '\t':
		case '\n':
		cout << -1 << endl;
			break;
		
		default:
			cout << 0 << endl;
			break;
		}
	}
}