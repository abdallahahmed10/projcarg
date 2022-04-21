#pragma once
#ifndef __PriorityNode_H_
#define __PriorityNode_H_

template <typename T>
class PriorityNode
{
	int priority;
	T item;
	PriorityNode<T>* next;
public:
	PriorityNode();

	PriorityNode(int prior,const T& it, PriorityNode<T>* nextNode);

	PriorityNode(int prior, const T& it);

	void setItem(const T& it);

	T getItem()const;

	void setNext(PriorityNode<T>* nextNode);

	PriorityNode<T>* getNext()const;

	int getPriority()const;

	void setPriority(int prior);

};


template <typename T>
PriorityNode<T>::PriorityNode()
{
	priority = 0;

	next = nullptr;
}

template <typename T>
PriorityNode<T>::PriorityNode(int prior, const T& it, PriorityNode<T>* nextNode)
{
	next = nextNode;

	priority = prior;

	item = it;
}

template <typename T>
PriorityNode<T>::PriorityNode(int prior, const T& it)
{
	next = nullptr;

	item = it;
}

template <typename T>
void PriorityNode<T>::setItem(const T& it)
{
	item = it;
}

template <typename T>
T PriorityNode<T> ::getItem() const
{
	return item;
}

template <typename T>
void PriorityNode<T>::setNext(PriorityNode<T>* nextNode)
{
	next = nextNode;
}

template <typename T>
PriorityNode<T>* PriorityNode<T> ::getNext() const
{
	return next;
}

template <typename T>
int PriorityNode<T>::getPriority() const
{
	return priority;
}

template <typename T>
void PriorityNode<T>::setPriority(int prior)
{
	if (prior >= 0)
	{
		priority = prior;
	}
}
#endif

