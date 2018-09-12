/**@file Node.h*/
#pragma once
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType item; //a data item
	Node<ItemType>* next; // pointer to next node

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node < ItemType>* nextNodePtr);
	void setItem(const ItemType anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem()const;
	Node<ItemType>* getNext()const;
};//end Node
#include "Node.cpp"
#endif
