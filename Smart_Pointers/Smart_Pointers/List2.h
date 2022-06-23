#include "Node.h"

/*
▪ сортировка списка по возрастанию(убыванию)*/

template<class L>
class List 
{
	Node<L>* head = nullptr;
	Node<L>* tail = nullptr;
	int size = 0;
public:
	List();
	List(const List& obj);
	List(List&& obj);
	~List();
	int getSize();
	void push_back(const L& val);
	void push_front(const L& val);
	void insert(const L& val, int pos);
	void pop_front();
	void del(int pos);
	void pop_back();
	void print_forward() const;
	void print_backward()const;
	List& operator=(const List& obj);
	List& operator=(List&& obj);
	void sort_ascending();
	void sort_descending();
};
template<class L>
inline List<L>::List()
{
	head = tail = NULL;
	size = 0;
}

template<class L>
inline List<L>::List(const List& obj)
{
	auto cur = obj.head;
	while (cur)
	{
		push_back(cur->getData());
		cur = cur->getNext();
	}
}

template<class L>
inline List<L>::List(List&& obj)
{
	swap(size, obj.size);
	swap(head, obj.head);
	swap(tail, obj.tail);
}

template<class L>
inline List<L>::~List()
{
	while (head != 0)
		pop_back();
}
template<class L>
inline int List<L>::getSize()
{
	return size;
}
template<class L>
inline void List<L>::push_back(const L& val)
{
	auto tmp = new Node<L>(val);
	if (size == 0) {
		head = tail = tmp;
	}
	else {
		tmp->setPrev(tail);
		tail->setNext(tmp);
		tail = tmp;
	}
	size++;
}

template<class L>
inline void List<L>::push_front(const L& val)
{
	auto tmp = new Node<L>(val);
	if (size == 0) {
		head = tail = tmp;
	}
	else {
		tmp->setNext(head);
		head->setPrev(tmp);
		head = tmp;
	}
	size++;
}

template<class L>
inline void List<L>::insert(const L& val, int pos)
{
	if (pos<0 || pos>size)
		return;
	if (pos == 1) {
		push_front(val);
		return;
	}
	if (pos == size) {
		push_back(val);
		return;
	}
	auto cur = head;
	for (int i = 1; i < pos - 1; ++i) {
		cur = cur->getNext();
	}
	cout << cur->getData() << endl;
	auto tmp = new Node<L>(val);
	tmp->setPrev(cur);
	tmp->setNext(cur->getNext());
	cur->getNext()->setPrev(tmp);
	cur->setNext(tmp);
	size++;
}

template<class L>
inline void List<L>::pop_front()
{
	if (size == 0)
		return;
	if (size == 1) {
		delete head;
		head = tail = nullptr;
		size = 0;
		return;
	}
	head = head->getNext();
	delete head->getPrev();
	head->setPrev(nullptr);
	size--;
}

template<class L>
inline void List<L>::del(int pos)
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
	if (pos<1 || pos > size) {
		cout << "error\n";
		return;
	}
	auto cur = head;
	for (int i = 1; i < pos-1; ++i)
	{
		cur = cur->getNext();
	}
	//cout << cur->getData() << endl;
	auto tmp = cur->getNext();
	cur->setNext(tmp->getNext());
	cur = cur->getNext();
	cur->setPrev(tmp->getPrev());
	delete tmp;
	size--;
}

template<class L>
inline void List<L>::pop_back()
{
	if (size == 0)
		return;
	if (size == 1) {
		delete head;
		head = tail = nullptr;
		size = 0;
		return;
	}
	tail = tail->getPrev();
	delete tail->getNext();
	tail->setNext(nullptr);
	size--;
}

template<class L>
inline void List<L>::print_forward() const
{
	auto cur = head;
	while (cur)
	{
		cout << cur->getData() << " ";
		cur = cur->getNext();
	}
	cout << endl;
}

template<class L>
inline void List<L>::print_backward() const
{
	auto cur = tail;
	while (cur)
	{
		cout << cur->getData() << " ";
		cur = cur->getPrev();
	}
	cout << endl;
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

template<class L>
inline void List<L>::sort_ascending()
{
	L sort;
	auto cur = head;
	for (int i = 0; i < size - 1; ++i)
	{
		cur = head;
		while(cur->getNext())
		{
			auto tmp = cur->getNext();
			if (cur->getData() > tmp->getData()) {
				sort = cur->getData();
				//cout << sort<<endl;
				cur->setData(tmp->getData());
				tmp->setData(sort);
			}
			cur = cur->getNext();
		}
	}
}

template<class L>
inline void List<L>::sort_descending()
{
	L sort;
	auto cur = head;
	for (int i = 0; i < size - 1; ++i)
	{
		cur = head;
		while (cur->getNext())
		{
			auto tmp = cur->getNext();
			if (cur->getData() < tmp->getData()) {
				sort = cur->getData();
				//cout << sort << endl;
				cur->setData(tmp->getData());
				tmp->setData(sort);
			}
			cur = cur->getNext();
		}
	}
}