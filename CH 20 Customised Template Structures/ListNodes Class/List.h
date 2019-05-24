#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNodes.h"
using namespace std;

template<typename NODETYPE>
class List
{
public:
	List(); // Constructor
	~List(); // Destructor
	
	// Manipulate data at front of list
	void insertAtFront(const NODETYPE &);
	bool removeFromFront(NODETYPE &);
	
	// Manipulate data at front of list
	void insertAtBack(const NODETYPE &);
	bool removeFromBack(NODETYPE &);
	
	// Predicate functions
	bool isEmpty() const;
	
	void print() const;
private:
	ListNode<NODETYPE> *firstPtr; // Pointer to first node
	ListNode<NODETYPE> *lastPtr; // Pointer to last node
	
	// Utility fubction to allocate new node
	ListNode<NODETYPE> *getNewNode(const NODETYPE &);
}; // End class list

// Default constructor
template<typename NODETYPE>
List<NODETYPE>::List()
:firstPtr(0), lastPtr(0)
{
	// Empty body
} // End constructor

// Destructor
template<typename NODETYPE>
List<NODETYPE>::~List()
{
	if (!isEmpty()) // If list is not empty
	{
		cout << "Destroying nodes...\n";
		
		ListNode<NODETYPE> *currentPtr = firstPtr;
		ListNode<NODETYPE> *tempPtr;
		
		while(currentPtr != 0)
		{
			tempPtr = currentPtr;
			cout << tempPtr->data << '\n';
			currentPtr = currentPtr->nextPtr;
			 delete tempPtr;
		} // End while
	} // End if
	
	cout << "All nodes destroyed\n\n";
} // End destructor

// Insert node at front of list
template<typename NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &value)
{
	ListNode<NODETYPE> *newPtr = getNewNode(value);
	
	if (isEmpty()) // If list is empty
		firstPtr = lastPtr = newPtr; // New list has only one node
	else // List is not empty
	{
		newPtr->nextPtr = firstPtr; // Point new node to previous first node
		firstPtr = newPtr; // Aim firstPtr to new node
	} // End if...else
} // End insertAtFront

// Delete list from front of list
template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &value)
{
	if (isEmpty()) // List is empty
		return false;
	
	ListNode<NODETYPE> *tempPtr = firstPtr; // Hold tempPtr to delete
	
	if (firstPtr == lastPtr)
		firstPtr = lastPtr = 0; // No nodes remain after removal
	else
		firstPtr = firstPtr->nextPtr; // Point to previous second node
	
	value = tempPtr->data; // Return data being removed
	delete tempPtr; // Reclaim previous front node
	
	return true; // Delete was successfull
} // End removeFromFront

// Insert list at back of list
template<typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &value)
{
	ListNode<NODETYPE> *newPtr = getNewNode(value);
	
	if (isEmpty()) // If list is empty
		lastPtr = lastPtr = newPtr; // New list has only one node
	else // List is not empty
	{
		lastPtr->nextPtr = newPtr; // Point new node to previous first node
		lastPtr = newPtr; // Aim firstPtr to new node
	} // End if...else
} // End insertAtBack

// Delete list from back of list
template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &value)
{
	if (isEmpty()) // List is empty
		return false; // Delete was unsuccessfull
	
	ListNode<NODETYPE> *tempPtr = lastPtr; // Hold tempPtr to delete
	
	if (firstPtr == lastPtr)
		firstPtr = lastPtr = 0; // No nodes remain after removal
	else
	{
		ListNode<NODETYPE> *currentPtr = firstPtr;
		
		// Locate second last element
		while(currentPtr->nextPtr != lastPtr)
			currentPtr = currentPtr->nextPtr;
		
		lastPtr = currentPtr; // Remove last node
		currentPtr->nextPtr = 0;
	} // End else
	
	value = tempPtr->data; // Return data being removed
	delete tempPtr; // Reclaim previous front node
	return true; // Delete was successfull
} // End removeFromFront

// Is list empty?
template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	return firstPtr == 0;
} // End is empty

// Return pointer to newly allocated node
template<typename NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value)
{
	return new ListNode<NODETYPE>(value);	
} // End List.getNewNode

// Display conntents of list
template<typename NODETYPE>
void List<NODETYPE>::print() const
{
	if (isEmpty()) // List is empty
	{
		cout << "The list is empty\n\n";
		return; // Exit the function
	} // End if
	
	ListNode<NODETYPE> *currentPtr = firstPtr;
	
	cout << "\nThe list is: ";
	
	while(currentPtr != 0)
	{
		cout << currentPtr->data << ' ';
		currentPtr = currentPtr->nextPtr;
	} // End while
	
	cout << endl << endl;
} // End print

#endif