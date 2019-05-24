// Binary Search.h
#include <vector>
using namespace std;

class BinarySearch
{
public:
	BinarySearch(int); // Default constructor
	int binarySearch(int) const; // Perform a binary search on vector
	void displayElements() const; // Display vector elements
private:
	int size; // Vector size
	vector<int> data; // Vector of ints
	void displaySubElements(int, int) const; // Display range of values
}; // End class BinarySearch