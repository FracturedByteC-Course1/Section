#pragma once
#include "Node.h"



template<class T>
class List
{
	int size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
public:
	List();
	List(const List&obj);
	List(List&& obj);
	List(const initializer_list<T> &list);
	~List();
	void add(const T& val, int pos);
	void push_back(const T& val);
	void push_front(const T& val);
	void pop_front();
	void del(int pos);
	void del(int pos, int count);
	void pop_back();
	void print();
	int getSize();
	List& operator=(const List&obj);
	List& operator=(List&& obj);
};

template<class T>
inline List<T>::List(const initializer_list<T>& list)
{
	for (auto item : list)
	{
		push_back(item);
	}
}

template<class T>
inline List<T>::List() = default;

template<class T>
inline List<T>::List(const List & obj)
{
	auto cur = obj.head;
	while (cur)
	{
		push_back(cur->getData());
		cur = cur->getNext();
	}
}

template<class T>
inline List<T>::List(List&& obj)
{
	swap(size, obj.size);
	swap(head, obj.head);
	swap(tail,obj.tail);
}

template<class T>
inline List<T>::~List()
{
	while (size)
		pop_front();
}

template<class T>
inline void List<T>::add(const T& val, int pos)
{
	if (pos == 1)
	{
		push_front(val);
		return;
	}
	if (pos == size + 1) {
		push_back(val);
		return;
	}
	auto cur = head;
	for (int i = 1; i < pos - 1; ++i)
	{
		cur = cur->getNext();
	}
	//cout << cur->getData() << endl;
	auto tmp = new Node<T>(val);
	tmp->setNext(cur->getNext());
	cur->setNext(tmp);
	size++;
}

template<class T>
inline void List<T>::push_back(const T& val)
{
	auto tmp = new Node<T>(val);
	if (size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->setNext(tmp);
		tail = tmp;
	}
	size++;
}

template<class T>
inline void List<T>::push_front(const T& val)
{
	auto tmp = new Node<T>(val);
	if (size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tmp->setNext(head);
		head = tmp;
	}
	size++;
}

template<class T>
inline void List<T>::pop_front()
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete head;
		head = tail = nullptr;
		size = 0;
		return; 
	}
	auto tmp = head;
	head = head->getNext();
	delete tmp;
	size--;
}

template<class T>
inline void List<T>::del(int pos)
{
	if (pos == 0) {
		return;
	}
	if (pos == 1) {
		pop_front();
		return;
	}
	if (pos == size) {
		pop_back();
		return;
	}
	if (pos > size) {
		cout << "error\n";
		return;
	}
	auto cur = head;
	for (int i = 1; i < pos-1; ++i)
	{
		cur = cur->getNext();
	}
	//cout << cur->getData() << " ";
	auto tmp = cur->getNext();
	cur->setNext(tmp->getNext());
	delete tmp;
	size--;
}

template<class T>
inline void List<T>::del(int pos, int count)
{
	if (pos == 0)
		return;
	if (pos + count > size) {
		cout << "error\n";
		return;
	}
	for (int i = 0; i <count; ++i) {
		del(pos);
	}
}

template<class T>
inline void List<T>::pop_back()
{
	if (size == 0)
		return;
	if (size == 1)
	{
		delete head;
		head = tail = nullptr;
		size = 0;
		return;
	}
	auto cur = head;
	while (cur->getNext() != tail)
	{
		cur = cur->getNext();
	}
	delete tail;
	tail = cur;
	tail->setNext(nullptr);
	size--;
}

template<class T>
inline void List<T>::print()
{
	auto cur = head;
	while (cur) {
		cout << cur->getData() << " ";
		cur = cur->getNext();
	}
	cout << endl;
}

template<class T>
inline int List<T>::getSize()
{
	return size;
}

template<class T>
inline List<T>& List<T>::operator=(const List& obj)
{
	if (this == &obj)
		return *this;
	auto cur = obj.head;
	while (cur)
	{
		push_back(cur->getData());
		cur = cur->getNext();
	}
	return *this;
}

template<class T>
inline List<T>& List<T>::operator=(List&& obj)
{
	if (this == &obj)
		return *this;
	swap(size, obj.size);
	swap(head, obj.head);
	swap(tail, obj.tail);
	return *this;
}
