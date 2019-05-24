// MergeSort.h
#include <vector>
using namespace std;

class MergeSort
{
public:
	MergeSort(int); // Constructor initializes vector
	void sort(); // Sort vector using merge sort
	void displayElements() const; // Display vector elements
private:
	int size; // Vector size
	vector<int> data; // Vector of ints
	void sortSubVector(int, int); // Sort sub vector
	void merge(int, int, int, int); // Merge two sorted vectors
	void displaySubVector(int, int) const; // Display sub vector
}; // End class MergeSort