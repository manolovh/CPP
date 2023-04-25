// Simple Accountt 
#ifndef _ACCOUNTT_H_
#define _ACCOUNTT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

class Accountt : public I_Printable {
private:   
    static constexpr const char *def_name = "Unnamed Accountt";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Accountt(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const override;
    virtual ~Accountt() = default;
};
#endif