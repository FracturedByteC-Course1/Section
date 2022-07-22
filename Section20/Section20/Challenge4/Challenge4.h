#pragma once
#include<cctype>
#include<stack>
#include<queue>
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

bool is_palindrome(const std::string& s) 
{
	std::stack<char> stk;
	std::queue<char> q;

	for (char c : s)
		if (std::isalpha(c))
		{
			c = std::toupper(c);
			q.push(c);
			stk.push(c);
		}

	char c1{};
	char c2{};

	while (!q.empty())
	{
		c1 = q.front();
		q.pop();
		c2 = stk.top();
		stk.pop();
		if (c1 != c2)
			return false;
	}
	return true;
}

int main()
{
	std::vector<std::string> test_strings;
	std::cout << "Enter palindrome:" << std::endl;
	std::string val;
	bool job = true;
	while (job) {
		getline(std::cin,val);
		if (val == "exit")
			job = false;
		else {
			test_strings.push_back(val);
			std::cout << std::endl;
		}
	};

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : test_strings)
		std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
	std::cout << std::endl;
	return 0;
}