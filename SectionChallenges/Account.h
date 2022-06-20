#pragma once
#include<iostream>
#include<string>

using namespace std;

class Account
{
	friend ostream& operator<<(ostream& os, const Account& account);
private:
	static constexpr const char* def_name = "Unnamed Account";
	static constexpr double def_balance = 0.0;
protected:
	string name;
	double balance;
public:
	Account(string _name = def_name, double _balance = def_balance);
	bool deposit(double amount);
	bool withdraw(double amount);
	double get_balance() const;
};

