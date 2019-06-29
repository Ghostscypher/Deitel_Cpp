#include "HugeInt.h"
using namespace std;

int main()
{
/*	// Create HugeInt objects
	HugeInt n1(7654321);
	HugeInt n2(7891234);
	HugeInt n3("99999999999999999999999999999");
	HugeInt n4("1");
	HugeInt n5;
	
	cout << "n1 is " << n1 << "\nn2 is " << n2
 	 	 << "\nn3 is " << n3 << "\nn4 is " << n4
 	 	 << "\nn5 is " << n5 << "\n\n";

	// HugeInt + HugeInt
	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

	// HugeInt + int
	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

	// HugeInt + string
	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;
	
	// HugeInt - HugeInt
	n5 = n1 - n2;
	cout << n1 << " - " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " - " << n4 << "\n= " << (n3 - n4) << "\n\n";

	// HugeInt - int
	n5 = n1 - 9;
	cout << n1 << " - " << 9 << " = " << n5 << "\n\n";

	// HugeInt - string
	n5 = n2 - "10000";
	cout << n2 << " - " << "10000" << " = " << n5 << endl;
	
	// Trying negative values
	HugeInt n6(1);
	HugeInt n7(9);
	cout << n6 << " - " << n7 << " = " << (n6 - n7) << endl;
	
	//  Number with a zero in between
	HugeInt n8(100);
	cout << n8 << " - 59 = " << (n8 - 59) << endl;*/
	
	HugeInt n8(1);
	HugeInt n9(-10);
	HugeInt n10(100);
	
	cout << n10 << " - " << n9 << " - " << n8 << " = " << (n9 + n8);
} // End main