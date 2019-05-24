/*
The allocation and deallocation of memory is refered to as Dynamic Memory Allocation (DMM).
In C++ this is performed by using the keyword 'new' and 'Delete', this keywords are used
to allocate and deallocate/release the memory from heap/free store (Memory allocated to a program) respectively.
N.B. Not releasing the dynamically allocated memory can cause the system to run out of memory
prematurely, also called 'memory leaks'.

[INITIALIZING DYNAMIC MEMORY]

You can provide an initializer for a newly created fundamental-type variable as in
	double *Ptr = new double(3.14159);
The same can also be used to creaye comma separated variables e.g.
	Time *Ptr = Time(12, 45, 00);''''''
Also arrays
	int *gradeArrayPtr = new int[10];
To dellocate the above array i.e. where gradeArrayPtr points we use
	delete [] gradeArrayPtr
N.B. Using 'delete' instead of 'delete []' for arrays can lead to serious logocal
errors at runtime. However this, 'delete' can only be used iff there is one item
otherwise using 'delete []' would result in an 'undefined' error.
*/