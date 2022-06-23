#pragma once
#include <iostream>
#include<memory>
#include<vector>

class Test
{
private:
	int data;
public:
	Test() : data{ 0 }
	{
		std::cout << "\tTest constructor(" << data << ')' << std::endl;
	}
	Test(int data) :data{ data } { std::cout << "\tTest constructor (" << data << ')' << std::endl; }
	int get_data() const { return data; }
	~Test() { std::cout << "\tTest destructor (" << data << ')' << std::endl; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}
void fill(std::vector<std::shared_ptr<Test>> &vec, int num) 
{
	int temp;
	for (int i = 1; i <= num; ++i)
	{
		std::cout << "Enter data point [" << i << "] : ";
		std::cin >> temp;
		//std::shared_ptr<Temp> ptr = std::make_shared<Test>(temp);
		//vec.push_back(ptr);
		vec.push_back(std::make_shared<Test>(temp));
	}
}
void display(const std::vector<std::shared_ptr<Test>>& vec) 
{
	std::cout << "\nDisplay vector data" << std::endl;
	std::cout << "===================================" << std::endl;
	for (const auto& ptr : vec)
		std::cout << ptr->get_data() << std::endl;
	std::cout<< "===================================" << std::endl;
}

