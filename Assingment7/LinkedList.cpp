/**@file LinkedList.cpp*/

#include "LinkedList.h"
#include "PreCondViolatedExcep.h"
#include <cassert>

template < class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	//node to point to original list
	Node<ItemType> origListPtr = aList->headPtr;
	if (origListPtr == nullptr)
		headPtr = nullptr;  //original list empty
	else
	{
		//copy first node
		headPtr = new Node<ItemType>;
		headPtr = setEntry(origListPtr.getEntry());
		//point to the first node in the new list
		Node<ItemType>* newListPtr = headPtr;

		while (!origListPtr == nullptr)
		{
			//advance original list pointer
			origListPtr = origListPtr->getNext();
			//get next item from original list
			ItemType nextItem = origListPtr->getEntry();
			//create a new node to hold the item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			//link node to the end of the new list
			newListPtr->setNext(newNodePtr);
			//advance pointer to new last node
			newListPtr = newListPtr->getNext();

		}//end while
		newListPtr = newListPtr->setNext(nullptr); //flag end of list
	}//end if
}//end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}//end destructor

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PreCondViolatedExcep)
{
	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PreCondViolatedExcep(message));
	} // end if
}

template <class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position)const
{
	//debugging check for precondition
	assert((position >= 1) && (position <= itemCount));

	//count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1;skip < position;skip++)
	{
		curPtr = curPtr->getNext();
	}
	return curPtr;
}//end getNodeAt

template < class ItemType>
bool LinkedList<ItemType>::insert(int newPosition,
	const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) &&
		(newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		// Create a new node containing the new entry
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// Attach new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		} // end if
		itemCount++; // Increase count of entries
	} // end if
	return ableToInsert;
} // end insert

template<class ItemType>
bool LinkedList<ItemType>::isEmpty()const
{
	return  itemCount == 0;
}//end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength()const
{
	return itemCount;
}//end getLength

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = ((position >= 1) && (position <= itemCount));
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			//remove the first node
			curPtr = headPtr; //save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			//find the node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			//point to node to delete
			curPtr = prevPtr->getNext();
			//disconnect indicated node from chain by connecting the prior node to the one after
			prevPtr->setNext(curPtr->getNext());

		}//end if
		//return node to the system
		curPtr->setNext(nullptr);
		delete curPtr;
		itemCount--;
	}//end if
	return ableToRemove;
}//end remove

template <class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType & newEntry) throw(PreCondViolatedExcep)
{
	Node<ItemType>* changePtr = getNodeAt(position);
	changePtr->setItem(newEntry);
	changePtr = nullptr;
	delete changePtr;

}
//end clear