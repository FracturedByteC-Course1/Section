#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

/*����������� ���������:
� S1 + 'T' (��������� ������ � ������)
� S1 + "str" (��������� ������ � ������)
� S1 == S2 (��������� �� ����� �� ������ ������ ������)
� S1 > S2 (���������� ������)
� S1 < S2 (���������� ������)
� S1 = S2 (����������� ����� ������ ������)*/

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




