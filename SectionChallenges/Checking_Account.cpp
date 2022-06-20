#include "Checking_Account.h"

ostream& operator<<(ostream& os, const Checking_Account& account)
{
    os << "[Checking_Account: " << account.name << ": " << account.balance << ']';
    return os;
}

Checking_Account::Checking_Account(string name, double balance) 
    : Account {name, balance}{}

bool Checking_Account::withdraw(double amount)
{
    amount += per_check_fee;
    return Account::withdraw(amount);
}
