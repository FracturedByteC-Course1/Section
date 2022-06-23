#include "List.h"

int main()
{
	List<int> list{5,10,12,34,56};
	list.print();
	//list.del(1);
	//list.del(0);
	cout << list.getSize() << endl;
	//list.del(2,2);
	//list.del(1);
	//list.push_front(0);
	//list.push_back(78);
	list.add(66,3);
	list.print();
	List<int> copy;
	copy = list;
	copy.print();
}