#include "Account.h"

ostream& operator<<(ostream& os, const Account& account)
{
    os << "[Account: " << account.name << ": " << account.balance << ']';
    return os;
}

Account::Account(string _name, double _balance) : name(_name), balance(_balance) {}

bool Account::deposit(double amount)
{
    if(amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount)
{
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
        return false;
}

void Account::print(ostream& os) const
{
    os.precision(2);
    os << fixed;
    os << "[Account: " << name << ": " << balance << ']';
}

//double Account::get_balance() const
//{
//    return balance;
//}
