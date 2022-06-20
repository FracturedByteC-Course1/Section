#include "MyString.h"

/*перегрузить операторы:
Х S1 + 'T' (добавл€ем символ в строку)
Х S1 + "str" (добавл€ем массив к строке)
Х S1 == S2 (провер€ем не равна ли перва€ строка второй)
Х S1 > S2 (сравниваем строки)
Х S1 < S2 (сравниваем строки)
Х S1 = S2 (присваиваем левой строке правую)*/

MyString::MyString()
{
    capacity = 80;
    str = new char[capacity] {};
}

MyString::MyString(int c)
{
    capacity = c;
    str = new char[capacity] {};
}

MyString::MyString(const char* s)
{
    str = _strdup(s);
    capacity = strlen(str) + 1;
}

MyString::MyString(const MyString& obj)
{
    capacity = obj.capacity;
    str = new char[strlen(obj.str) + 1];
    strcpy(str, obj.str);
}

MyString::MyString(MyString&& obj)
{
    swap(capacity, obj.capacity);
    swap(str, obj.str);
}

MyString::~MyString()
{
    if (capacity)
        delete[]str;
}

void MyString::print() const
{
    cout << str << endl;
}

void MyString::input()
{
    char buf[500];
    cin.getline(buf, 500);
    int len = strlen(buf);
    if (len < capacity)
        strcpy(str, buf);
    else
    {
        delete[]str;
        str = _strdup(buf);
        capacity = strlen(str) + 1;
    }
}

int MyString::getSize() const
{
    return strlen(str);
}

int MyString::getCapacity() const
{
    return capacity;
}

MyString::operator const char* ()
{
    return str;
}
MyString::operator string()
{
    return str;
}

MyString MyString::operator+()
{
    char arr[] = {'T'};
    MyString tmp(getSize() + 2);
    strcpy(tmp.str, str);
    strcat(tmp.str, arr);
    return tmp;
}

MyString MyString::operator+(const MyString& obj) const
{
    MyString tmp(getSize() + obj.getSize() + 1);
    strcpy(tmp.str, str);
    strcat(tmp.str, obj.str);
    return tmp;
}

bool MyString::operator==(const MyString& obj) const
{
    return strcmp(str, obj.str) == 0;
}

bool MyString::operator>(const MyString& obj) const
{
    return strcmp(str,obj.str) < 0;
}

bool MyString::operator<(const MyString& obj) const
{
    return strcmp(str, obj.str) > 0;
}

MyString MyString::operator=(const MyString& obj)
{
    if (this == &obj)
        return *this;
    delete[] str;

    if (obj.str)
        str = _strdup(obj.str);
    else
        str = nullptr;
    return *this;
}
