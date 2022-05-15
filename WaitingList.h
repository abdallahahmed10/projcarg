#pragma once
using namespace std;
#include "LinkedList.h"
#include "Cargos.h"

class WaitingList : public LinkedList<Cargos*>
{
	Node<Cargos*>* Head1;
	friend bool Cargos:: operator== (const int x);
	virtual Node<Cargos*>* getNodeAt(int position)
	{
		if (position >= 1 && position <= itemcount)
		{
			Node<Cargos*>* curptr = Head1;
			for (int i = 1; i < position; i++)
				curptr = curptr->getNext();
			return curptr;
		}
		return nullptr;
	}
 public:
	 WaitingList()
	 {
		 Head1 = nullptr;
	 }
	 Cargos* Find(int& id)
	{
		Node<Cargos*>* temp = Head1;
		if (!temp)
			return nullptr;
		while (temp)
		{
			if (temp->getItem()->getid() == id)
				return temp->getItem();
			temp = temp->getNext();
		}
		return nullptr;
	}
	 virtual Cargos* GetEntry(int position)
	 {
		 {
			 itemcount = getcount();
			 bool ableToGet = (position >= 1) && (position <= getcount());
			 if (ableToGet)
			 {
				 Node<Cargos*>* nodePtr = getNodeAt(position);
				 return (nodePtr->getItem());
			 }
			 else
				 return NULL;
		 }
	 }
	 virtual void InsertEnd(Cargos* data)
	 {
		 Node<Cargos*>* R = new Node <Cargos*>(data);
		 if (!Head1)
		 {
			 Head1 = R;
		 }
		 Node<Cargos*>* p = Head1;
		 while (p->getNext())
		 {
			 p = p->getNext();
		 }
		 p->setNext(R);
		 R->setNext(nullptr);
	 }
	
	virtual bool DeleteNode(const int value)
	{
		
		if (!Head1->getNext())
		{
			delete Head1;
			Head1 = nullptr;
			return true;
		}
		Node<Cargos*>* temp = Head1;
		if (Head1->getItem()->getid() == value)
		{
			Head1 = Head1->getNext();
			delete temp;
			temp = nullptr;
			return true;
		}
		Node<Cargos*>* temp2 = temp->getNext();
		if (!temp)
			return false;
		while (temp && temp2)
		{
			if (temp2->getItem()->getid() == value)
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
		Node<Cargos*>* Temp = Head1;

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
	virtual int getcount()
	{
		int count = 0;
		Node<Cargos*>* p = Head1;
		if (!Head1)
			return 0;
		while (p)
		{
			count++;
			p = p->getNext();
		}
		return count;
	}
	virtual void DeleteFirst()
	{
		Node<Cargos*>* temp = Head1;
		if (!temp)
			return;
		Head1 = Head1->getNext();
		delete temp;
		itemcount--;
	}
	bool IsEmpty()
	{
		return (Head1 == nullptr);
	}
	bool GetFirstItem(Cargos*& c)
	{
		if (IsEmpty())
			return false;
		c = Head1->getItem();
	}
};
