#ifndef STACK_H
#define STACK_H

template <typename T>

class Stack
{
public:
	explicit Stack(int = 10); // Default constructor. Stack size = 10
	bool push(const T&); // Push an element into the stack
	bool pop(T &); // Pop an element off the stack
	
	// Determine wheter a stack is empty
	bool isEmpty() const
	{
		return top == -1;
	} // End isEmpty
	
	// Determine if stack is full
	bool isFull() const
	{
		return top == size - 1;
	} // End isFull
	
	// Destructor
	~Stack()
	{
		delete [] stackPtr; // Deallocate internal space for stack
	} // End destructor
private:
	int size; // Number of elements in stack
	int top; // Location of top element (-1 means empty)
	T *stackPtr; // Pointer to internal representation of stack
}; // End class stack

// Constructor Template
template <typename T>
Stack<T>::Stack(int s)
:size(s > 0? s: 10), // Validate size
top(-1), // Stack initially empty
stackPtr(new T[size]) // Allocate memory for elements
{
	// Empty body
} // End Stack constructor template

// Push elements into stack
// If successfull return true else false
template <typename T>
bool Stack<T>::push(const T &pushValue)
{
	if (!isFull())
	{
		stackPtr[++top] = pushValue; // Place item on stack
		return true; // Push is successfull
	} // End if
	
	return false; // Push is unsuccessfull
} // End function template push

// Pop elements off the stack
// If successfull return true else false
template <typename T>
bool Stack<T>::pop(T &popValue)
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--]; // Remove item from stack
		return true; // Pop successfull
	} // End if
	
	return false; // Pop unsuccessfull
} // End function template pop

#endif