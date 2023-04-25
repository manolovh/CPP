#include "Accountt.h"

Accountt::Accountt(std::string name, double balance) 
    : name{name}, balance{balance} {
    if (balance < 0.0)
        throw IllegalBalanceException();
}

bool Accountt::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Accountt::withdraw(double amount) {
    if (balance-amount < 0)
        throw InsufficientFundsException();
    else {
        balance-=amount;
        return true;
    }
}

 void Accountt::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Accountt: " << name << ": " << balance << "]";
}
