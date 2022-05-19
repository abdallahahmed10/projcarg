#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
protected:
	int itemcount;
	Node<T>* Head;	//Pointer to the head of the list
protected:
	virtual Node<T>* getNodeAt(int position)
	{
		if (position >= 1 && position <= itemcount)
		{
			Node<T>* curptr = Head;
			for (int i = 1; i < position; i++)
				curptr = curptr->getNext();
			return curptr;
		}
		return nullptr;
	}
	
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
		itemcount = 0;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	/*void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}*/
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/

	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		itemcount++;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		itemcount = 0;
	}
	virtual int getcount()
	{
		int count = 0;
		Node<T>* p = Head;
		if (!Head)
			return 0;
		while (p)
		{
			count++;
			p = p->getNext();
		}
		return count;
	}

	virtual T GetEntry(int position) 
	{
		bool ableToGet = (position >= 1) && (position <= getcount());
		if (ableToGet)
		{
			Node<T>* nodePtr = getNodeAt(position);
			return nodePtr->getItem();
		}
		else
			return NULL;
	}

	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	virtual void InsertEnd(const T& data)
	{
		Node<T>* R = new Node <T>(data);
		if (!Head)
		{
			Head = R;
		}
		Node<T>* p = Head;
		while (p->getNext())
		{
			p = p->getNext();
		}
		p->setNext(R);
		R->setNext(nullptr);
		itemcount++;
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	//virtual bool Find(int Key);

	//[4] DeleteFirst
	//Deletes the first node in the list
	virtual void DeleteFirst()
	{
		Node<T>* temp = Head;
		if (!temp)
			return;
		Head = Head->getNext();
		delete temp;
		itemcount--;
	}


	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	virtual bool DeleteNode(const T& value)
	{
		Node<T>* temp = Head;
		Node<T>* temp2 = temp->getNext();
		if (!temp)
			return false;
		while (temp && temp2)
		{
			if (temp2->getItem() == value)
			{
				temp->setNext(temp2->getNext());
				delete temp2;
				temp2 = nullptr;
				return true;
			}
			temp = temp->getNext();
			temp2 = temp2->getNext();
		}
		return false;
	}
	virtual void PrintList() const
	{
		//if (!Head) { return; }
		Node<T>* Temp = Head;

		if (Temp != nullptr)
		{
			cout << (Temp->getItem());
			Temp = Temp->getNext();
		}
		while (Temp != nullptr)
		{
			cout << "," << (Temp->getItem());
			Temp = Temp->getNext();
		}
	}


	

};

#endif	