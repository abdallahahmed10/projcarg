#pragma once
using namespace std;
#include "LinkedList.h"
#include "Cargos.h"

class WaitingList : public LinkedList<Cargos*>
{
	Node<Cargos*>* Head1;
	friend bool Cargos:: operator== (const int x);
public:
	 Cargos* Find(int& id)
	{
		Node<Cargos*>* temp = Head1;
		if (!temp)
			return;
		while (temp)
		{
			if (temp->getItem()->getid() == id)
				return temp->getItem();
			temp = temp->getNext();
		}
		return;
	}
	
	virtual bool DeleteNode(const int value)
	{
		Node<Cargos*>* temp = Head1;
		Node<Cargos*>* temp2 = temp->getNext();
		if (!temp)
			return false;
		while (temp && temp2)
		{
			if (*temp2->getItem() == value)
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
 
};
