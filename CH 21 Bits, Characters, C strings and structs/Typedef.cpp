#include <iostream>
using namespace std;

/**
 * @brief used to create aliases/synonyms
 * 
 * @description
 * typedef provide a way to create aliases/synonyms for previously
 * defined data types.
 * N.b. Typedef does not create a new data type as shown below
 * 
 * Typedef is mainly used for portability.
 */

int main()
{	
	typedef long lng;
	
	lng l = 10000;
	
	cout << l << endl;
} // End main