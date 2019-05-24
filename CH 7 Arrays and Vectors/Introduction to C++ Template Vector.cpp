#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <exception>
using namespace std;

//start of prototype
	void outputVector(const vector <int> &);//display the elements
	void inputVector(vector <int> &);//input values into the vectors
//end of prototype

int main()
{
	vector <int> integers1(7);//7 - Elemenent vector
	vector <int> integers2(10);//10 - Element vector
	
	//print integer size and content
	cout << "Size of vectors integer1 is: "	<< integers1.size()
	<< "\nvector after initialization." << endl;
	outputVector(integers1);
	
	//print integers2 size and contents
	cout << "Size of vectors integer2 is: "	<< integers2.size()
	<< "\nvector after initialization." << endl;
	outputVector(integers2);
	
	//input and print integers1 and intergers2
	inputVector(integers1);
	inputVector(integers2);
	
	//
	cout << "\nAfter input, the vectors contain:\n" <<
	"Integers1: " << endl;
	outputVector(integers1);
	cout << "\nInteger2: " << endl;
	outputVector(integers2);
	
	//use (!=) operator with vectors
	cout << "\nEvaluating integers1 != integers2:" << endl;
	
	if(integers1 != integers2)
		cout << "Integers1 and integers2 are not equal" << endl;
	
	/*create vector integer3 using integer1 as initializer
	print it's size and contents */	
	vector <int> integers3(integers1);//copy constructor
	
	cout << "Size of vectors integer3 is: "	<< integers3.size()
	<< "\nvector after initialization." << endl;
	outputVector(integers3);
	
	//use overloaded assignement (=) operator
	cout << "\nAssigning integers2 to integers1: " << endl;
	integers1 = integers2;//assign integers2 to integers 1
	
	cout << "Integers1: " << endl;
	outputVector(integers1);
	cout << "Integers2: " << endl;
	outputVector(integers2);
	
	//use equality operator (==) with vector objects
	cout << "\nUsing equality operators with vectors i.e. ==" << endl;
	if(integers1 == integers2)
		cout << "Integer1 is equal to integer2";
	
	//use square brackets to create rvalue
	cout << "Integer1[5] is: " << integers1[5] << endl;
	
	//use square brakets to create lvalue
	cout << "\nAssigning 1000 to integer1[5]: " << endl;
	integers1[5] = 1000;
	outputVector(integers1);
	 
 	//attempt out of range subscript
 	
 	try
	{
	 	cout << "\nAttempt to display integers1 at 15. i.e. integers1.at(15)" << endl;
	 	cout << integers1.at(15) << endl;
	}// end try
	 catch(out_of_range& e)
	 {
		 cout << "An exception occured: " << e.what() << endl;
	 }//end catch
}

void outputVector(const vector <int> &array)
{
	size_t i;//declare control variable
	
	for(i = 0; i < array.size(); i++)
	{
		cout << setw(12) << array[i];
		
		if((i + 1) % 4 == 0)
			cout << endl;
	}
	if((i % 4) != 0)
		cout << endl;
}//end output vector

//input vector contents
void inputVector(vector <int> &array)
{
	static int numb = 0;
	numb++;
	cout << "Input for vector number: " << numb << endl;
	for(size_t i = 0; i < array.size(); i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> array[i]; 
	}
}//end function inputvector