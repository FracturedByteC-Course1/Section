#pragma once
#include<iostream>
#include<iomanip>
#include<string>

bool is_palindrome(const std::string& s)
{
	for (int i = 0, n = s.size()-1; i < s.size(); ++i, --n)
	{
		if (s.at(i) != s.at(n))
			return false;
	}
	return true;
}

int main()
{
	std::string s;
	std::cout << std::boolalpha;
	do
	{
		std::cout << "Enter word for check to is palindrome: ";
		std::cin >> s;
		std::cout << std::endl;
		std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
		std::cout << "Press e for exit" << std::endl;
	} while (true);
	
	return 0;
}

