#pragma once
#include <iostream>

using namespace std;

template <class L>
class Node {
	L data;
	Node<L>* next = nullptr;
	Node<L>* prev = nullptr;
public:
	Node(const L& val);
	L getData() const;
	Node<L>* getNext()const;
	Node<L>* getPrev()const;
	void setData(const L& val);
	void setNext(Node<L>* val);
	void setPrev(Node<L>* val);
};

template<class L>
inline Node<L>::Node(const L& val)
{
	data = val;
}

template<class L>
inline L Node<L>::getData() const
{
	return data;
}

template<class L>
inline Node<L>* Node<L>::getNext() const
{
	return next;
}

template<class L>
inline Node<L>* Node<L>::getPrev() const
{
	return prev;
}

template<class L>
inline void Node<L>::setData(const L& val)
{
	data = val;
}

template<class L>
inline void Node<L>::setNext(Node<L>* val)
{
	next = val;
}

template<class L>
inline void Node<L>::setPrev(Node<L>* val)
{
	prev = val;
}

