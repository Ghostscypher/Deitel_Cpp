#include <iostream>
using namespace std;

//start of prototypes
	void retValue(int, int, int, int (*)(int, int, int), int &);
	int max(int, int, int);
	int min(int, int, int);
//end of prototypes

int main()
{
	int a = 25;
	int b = 356;
	int c = 41;
	int maxOrmin;
	
	int maxOrminValue = a;
	
	cout << "Enter\n1 To return maximum value\n2 To return minimum value" << endl;
	cout << "type: ";
	cin >> maxOrmin;
	
	cout << "\na = " << a
	<< "\nb = " << b
	<< "\nc = " << c;
	
	if(maxOrmin == 1)
	{
		cout << "\nThis will return maximum value" << endl;
		retValue(a, b, c, max, maxOrminValue);
		cout << maxOrminValue;
	}
	else
	{
		cout << "\nThis will return minimum value" << endl;
		retValue(a, b, c, min, maxOrminValue);
		cout << maxOrminValue;	
	}
	cout<< endl;
}

void retValue(int a, int b, int c, int (*test)(int, int, int), int &y)
{
	y = (*test)(a, b, c);
}

int max(int a, int b, int c)
{
	int maxvalue = a;
	
	if (b > maxvalue)
		maxvalue = b;
	
	if (c > maxvalue)
		maxvalue = c;
	
	return maxvalue;
}

int min(int a, int b, int c)
{
	int minvalue = a;
	
	if (b < minvalue)
		minvalue = b;
	
	if (c < minvalue)
		minvalue = c;
	
	return minvalue;
}