#include "List.h"

int main()
{
    List<int> list;
    list.push_back(0);
    list.push_back(2);
    list.push_back(7);
    list.push_back(4);
    list.insert(100,1);
    list.print_forward();
    //list.del(3);
   // list.print_forward();
    //list.print_backward();
    List<int> copy;
    copy = list;
    //copy.print_backward();
    //copy.print_forward();
    list.sort_ascending();
    list.print_forward();
    list.print_backward();
    list.sort_descending();
    list.print_forward();
    list.print_backward();
}