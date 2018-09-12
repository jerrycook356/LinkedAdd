/**ADT list: link-based implementation
@file LinkedList.h*/
#pragma once
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PreCondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;         //pointer to first node int he chain
									//constains the first entry in the list
	int itemCount;                  //current count of list items

	//locates a specified node in a linked list.
	//@pre positin is the number of the desired node:
	//position >=1 and position <= itemCount.
	//@post the node is found and a pointer to it is returned
	//@param position the nujmber of the node to locate
	//@return a pointer to the node at the given position
	Node<ItemType>* getNodeAt(int position)const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	/** @throw PreCondViolatedExcep if position < 1 or position > getLength().*/

	void setEntry(int position, const ItemType& newEntry)throw(PreCondViolatedExcep);

	/**@thro PreCondViolatedExcep if position <1 or position > getLength().*/

	ItemType getEntry(int position) const throw(PreCondViolatedExcep);


};//end LindkedList
#include"LinkedList.cpp"
#endif // !_LINKED_LIST