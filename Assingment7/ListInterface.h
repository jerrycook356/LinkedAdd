/**Interface for ADT list
@file ListInterface.h*/

#pragma 
#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class ItemType>
class ListInterface
{
public:
	/**sees whether the list is empty
	@return true if the list is empty,false otherwise*/

	virtual bool isEmpty() const = 0;

	/**gets the current number of entries in the list
	@return the integer number of entries in the list*/

	virtual int getLength() const = 0;

	/**inserts a new entry in a list at the given location
	@pre none
	@post if 1 <= position <= getLength()+1 and the insertion is sucessfull , newEntry is at given
	position in the list and the other entries are re numbered accordingly
	@param newPosition the list position to insert the newEntry
	@param newEntry the new entry
	@return true if insertion is sucessful, false otherwise*/

	virtual bool insert(int position, const ItemType& newEntry) = 0;

	/**removes entry from position in the list
	@pre none
	@post If 1 <= position <= getLength() and the rmoval is sucessful the entry at the given
	position in the list is removed. Other items are renumbered accordingly, and the returned value is true
	@param position the list position of the entry to remove
	@return true if removal is sucessful, false otherwise*/
	virtual bool remove(int position) = 0;

	/**removes all entries from the list
	@post list contains no entries and the count of items is 0*/
	virtual void clear() = 0;

	/**gets the entry at the given position in the list
	@pre 1<= position = getLength().
	@post the desired entry has been returned
	@param position the list position of the desired entry
	@return the entry at the given position*/
	virtual ItemType getEntry(int position)const = 0;

	/** replaces the entry at the given posiiton in this list
	@pre 1<= position <= getLength().
	@post the entry at the given position is newEntry
	@param position the list position of the entry to replace
	@param newEntry the replacement entry*/
	virtual void setEntry(int position, const ItemType& newEntry) = 0;

};//end ListInterface
#endif // 