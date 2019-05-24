#include <iostream>
using namespace std;
/*In this code the ->(aarrow member selection) and .(dot) selectors*/

class Count
{
	private:
		int x;
	public:
		//sets the value of private data member x
		void setx(int value)
		{
			x = value;
		}
		
		//print value of private data memeber x
		void print()
		{
			cout << x << endl;	
		}
};

int main()
{
	Count counter;//create counter object
	Count *counterPtr = &counter;//create pointer to counter
	Count &counterRef = counter;//create reference to counter
	
	cout << "Set X to 1 and print using the objects name: ";
	counter.setx(1);
	counter.print();
	
	cout << "Set X to 2 and print using a reference to an object: ";
	counterRef.setx(2);
	counterRef.print();
	
	cout << "Set X to 3 and print using a pointer to an object: ";
	counterPtr->setx(3);
	counterPtr->print();
}//end main