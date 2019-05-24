#include <iostream>
using namespace std;

int main()
{
	int x, y;
	/*ptr is a constant pointer to an integer that can be modified through Ptr,
	but Ptr always points to the same memory location.*/
	
	int * const Ptr = &x;
	*Ptr = 7;//allowed ptr is not constant
	cout << &Ptr;
	cout << *Ptr;
	Ptr = &y;/*Error: Ptr is constant; cannot assign it to new address. This 
	will ensure that the pointer is not modified and that it will always point
	to the same memory location*/
}