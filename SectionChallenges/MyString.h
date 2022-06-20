#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

/*перегрузить операторы:
Х S1 + 'T' (добавл€ем символ в строку)
Х S1 + "str" (добавл€ем массив к строке)
Х S1 == S2 (провер€ем не равна ли перва€ строка второй)
Х S1 > S2 (сравниваем строки)
Х S1 < S2 (сравниваем строки)
Х S1 = S2 (присваиваем левой строке правую)*/

class MyString
{
    int capacity = 0;
    char* str = nullptr;
public:
    MyString();
    MyString(int c);
    MyString(const char* s);
    MyString(const MyString& obj);
    MyString(MyString&& obj);
    ~MyString();
    void print()const;
    void input();
    int getSize()const;
    int getCapacity()const;
    operator const char* ();
    operator string();
    MyString operator+(const MyString& obj)const;
    bool operator== (const MyString& obj) const;
    bool operator>(const MyString& obj) const;
    bool operator<(const MyString& obj) const;
    MyString operator= (const MyString& obj);

};




