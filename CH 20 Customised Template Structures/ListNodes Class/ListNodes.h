#ifndef LISTNODES_H
#define LISTNODES_H

// Forward declaration of class list required to announce that class ListNodes
// exists so that it can be used in the friend declaration ata line 11
template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode
{
friend class List<NODETYPE>; // Make List friend
public:
	ListNode(const NODETYPE &); // Constructor
	NODETYPE getData() const; // Return data in node
private:
	NODETYPE data; // Data
	ListNode<NODETYPE> *nextPtr; // Next node in list
}; // End class ListNodes

// Constructor
template<typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
:data(info), nextPtr(0)
{
	// Empty body
} // End constructor

// Return copy of data in node
template<typename NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const
{
	return data;
} // End getData 
#endif