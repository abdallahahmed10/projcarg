#pragma once
#ifndef __PriorityQueue_H_
#define __PriorityQueue_H_
using namespace std;
#include "PriorityNode.h"
#include <iostream>


template <typename T>
class PriorityQueue
{
	int count;

	PriorityNode<T>* front;
public:
	PriorityQueue();

	~PriorityQueue();

	bool isEmpty();

	bool enqueue(const T&newItem ,int priority);

	bool dequeue(T& frontItem);

	bool peekFront(T& frontItem);

	int getcount()const;
	
	void PrintList() const;


};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	count = 0;
	front = nullptr;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T destruct;
	count = 0;

	while (front)
	{
		dequeue(destruct);
	}
}

template <typename T>
bool PriorityQueue<T>::isEmpty()
{
	if (front)
	{
		return false;
	}

	return true;
}

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newItem, int priority)
{
	PriorityNode<T>* newNode = new PriorityNode<T>(priority, newItem);

	if (isEmpty())
	{
		front = newNode;
		count++;

		return true;
	}

	if ((front->getPriority()) < priority)
	{
		newNode->setNext(front);	//sets the next of the new node to front
		count++;
		front = newNode;		// sets the new node as the new front
		return true;
	}
	else
	{
		PriorityNode<T>* temp1 = front;
		//temp pointers to help sort according to priority
		PriorityNode<T>* temp2 = front->getNext();

		while ((temp2 && temp2->getPriority() >= priority ))
		{
			temp1 = temp1->getNext();

			temp2 = temp2->getNext();
		}

		newNode->setNext(temp2);
		temp1->setNext(newNode);		//sets new node between temp1 and temp2

		count++;
		return true;
	}



}

template <typename T>
bool PriorityQueue<T>::dequeue(T& frontItem)
{
	if (isEmpty())
	{
		return false;
	}

	PriorityNode<T>* del = front;
	frontItem = front->getItem(); //moves item in front node to the new front item 
	front = front->getNext();	// moves front to second highest priority to delete the highest priority item

	delete del;
	count--;

	return true;
}

template <typename T>
bool PriorityQueue<T>::peekFront(T& frontItem)
{
	if (isEmpty())
	{
		return false;

	}
	frontItem = front->getItem();

	return true;
}

template <typename T>
int PriorityQueue<T>::getcount() const
{
	return count;
}

template <typename T>
void PriorityQueue<T> ::PrintList() const
{
	/*if (front==nullptr) { return; }*/

	PriorityNode<T>* Temp = front;

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

#endif

