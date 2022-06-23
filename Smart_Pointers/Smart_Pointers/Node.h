#pragma once
#include <iostream>
#include<initializer_list>

using namespace std;

template <class T>
class Node {
	T data;
	Node<T>* next = nullptr;
public:
	Node(const T& val);
	T getData() const;
	Node<T>* getNext()const;
	void setData(const T& val);
	void setNext(Node<T>* val);
};

template<class T>
inline Node<T>::Node(const T& val)
{
	data = val;
}

template<class T>
inline T Node<T>::getData() const
{
	return data;
}

template<class T>
inline Node<T>* Node<T>::getNext() const
{
	return next;
}

template<class T>
inline void Node<T>::setData(const T& val)
{
	data = val;
}

template<class T>
inline void Node<T>::setNext(Node<T>* val)
{
	next = val;
}

