#pragma once
#include<iostream>
#include<string>
#include"I_Printable.h"
#include"IllegalBalanceException.h"

using namespace std;

class Account:public I_Printable
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
	virtual bool deposit(double amount) = 0;
	virtual bool withdraw(double amount) = 0;
	virtual void print(ostream& os) const override;
	~Account() = default;
	//double get_balance() const;
};

