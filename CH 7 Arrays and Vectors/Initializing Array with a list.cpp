#include <iostream>
#include <iomanip>
using namespace std;

/*If there are fewer initializers than array elements, the remaining elements
are initialized to zero for example int indexes[10] = {}. All the elements
in this array are initialized to zero because no  element value was supplied.
If the number of elements in the array is missing, the array is sized according
to the number of elemnts present. For example int indexes[] = {0, 1, 2, 3} then
the number of elemnts is initilized to 4 because there are four elemnts in our
array i.e. int indexes[4] = {0, 1, 2, 3}. If the number of elements are
initialized, then the number of elemnts must be less or equal than the array size
otherwise a compilation error occurs. for example int indexes[3] = {1, 2, 3, 4}
will cause a compilation error beacuse the number of elements in the list is
more than the array size*/

int main()
{
	//use initializer list to initialize array
	int indexes[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//use loop to print the above
	cout << "Element" << setw(15) << "Values" << endl;
	for(int i = 0; i < 10; i++)
	{
		cout << "Element [" << i << "]" << setw(12) << indexes[i] << endl;
	}//end loop
}//end main