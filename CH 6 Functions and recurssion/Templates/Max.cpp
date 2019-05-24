#include <iostream>
#include "max.h"
using namespace std;

int main()
{
	// Test for all data types
	// 1. Integer
	int x, y, z;
	cout << "Input 3 integers: " ;
	cin >> x >> y >> z;
	
	// Compare and return results using template function
	cout << "The maximum of the three integers is: " << maximum(x, y, z) << endl;
	
	// 2. Double
	double a, b, c;
	cout << "Input 3 double: " ;
	cin >> a >> b >> c;
	
	// Compare and return results using template function
	cout << "The maximum of the three double is: " << maximum(a, b, c) << endl;
	
	// 3. Character
	char m, n, o;
	cout << "Input 3 characters: " ;
	cin >> m >> n >> o;
	
	// Compare and return results using template function
	cout << "The largest of the three characters is: " << maximum(m, n, o) << endl;
}// End main