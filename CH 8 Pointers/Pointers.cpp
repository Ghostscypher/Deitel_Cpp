#include <iostream>
using namespace std;

//aliases aka pointers

int main()
{
	int a = 7;
	int *aPtr = &a;
	
	cout << "The address of a is: " << &a << endl;
	cout << "The value of aPtr is: " << aPtr << endl;
	cout << "The Value of a is: " << a << endl;
	cout << "The address of *aPtr is: " << *aPtr << endl;
	cout << "The address of &aPtr is: " << &aPtr << endl;
	cout << "Show that *&aPtr and &*aPtr are inverses of each other" << endl;
	cout << "&*aPtr = " << &*aPtr << " Inverse of memory location"
	<<"\n*&aPtr = " << *&aPtr << " Inverse of 8";
}