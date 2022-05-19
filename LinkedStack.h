#ifndef ARRAY_STACK_
#define ARRAY_STACK_
#include "Node.h"
#include "StackADT.h"
#include <iostream>
using namespace std;

//Unless spesificed by the stack user, the default size is 100
template<typename T>
class LinkedStack : public StackADT<T>
{
private:
	Node<T>*top;
public:

	LinkedStack()
	{
		top =nullptr;
	}

	bool isEmpty() const
	{
		return (top==nullptr)
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (isEmpty())
		{
			Node<T>* newnode = new Node();
			newnode->setItem(newEntry);
			top = newnode;
		}
		else 
		{
			Node<T>* newnode = new Node();
			newnode->setItem(newEntry);
			newnode->setNext(top);
			top = newnode;
		}
		return true;
	}  

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = top->getItem();
		Node<T>* delptr = top;
        top=top->getNext();
		delete delptr;
		return true;
	} 

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = top->getItem();
		return true;
	}  // end peek
	int getcount()
	{
		int count = 0;
		Node<T> * p = top;
		if (isEmpty())
			return 0;
		while (p)
		{
			count++;
			p = p->getNext();
		}
		return count;
	}

	   //Destructor
	~LinkedStack()
	{
		T temp;
		while (pop(temp));
	}

	void PrintList() const
	{
		if (Head==nullptr) { return; }
		Node<T>* Temp = Head;

		while (Temp != nullptr)
		{
			cout << Temp->getItem() << ",";
			Temp = Temp->getNext();
		}
	}
};
#endif
