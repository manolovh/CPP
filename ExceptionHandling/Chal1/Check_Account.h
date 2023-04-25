#ifndef _CHECK_ACCOUNT_H_
#define _CHECK_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Accountt.h"

class Check_Account: public Accountt {
private:
    static constexpr const char *def_name = "Unnamed Check Accountt";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Check_Account(std::string name = def_name, double balance = def_balance);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;

    virtual ~Check_Account() = default;
};

#endif // _CHECK_ACCOUNT_H_
