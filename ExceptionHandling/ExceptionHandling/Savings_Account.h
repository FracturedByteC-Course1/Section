#pragma once
#include "Account.h"
class Savings_Account :
    public Account
{
    friend ostream& operator<<(ostream& os, const Savings_Account& account);
private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Savings_Account() = default;
};

