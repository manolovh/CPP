#include "Check_Account.h"

Check_Account::Check_Account(std::string name, double balance)
    : Accountt {name, balance} {}


bool Check_Account::withdraw(double amount) {
    amount += per_check_fee;
    return Accountt::withdraw(amount);
}

bool Check_Account::deposit(double amount) {
    return Accountt::deposit(amount);
}

void Check_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Check_Account: " << name << ": " << balance  << "]";
}

