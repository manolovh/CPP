#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Accountt.h"
#include "Savings_Account.h"
#include "Check_Account.h"
#include "Trust_Account.h"

// Utility helper functions for Accountt class

void display(const std::vector<Accountt> &accounts);
void deposit(std::vector<Accountt> &accounts, double amount);
void withdraw(std::vector<Accountt> &accounts, double amount);

// Utility helper functions for Savings Account class

void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

// Utility helper functions for Check Account class
void display(const std::vector<Check_Account> &accounts);
void deposit(std::vector<Check_Account> &accounts, double amount);
void withdraw(std::vector<Check_Account> &accounts, double amount);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector<Trust_Account> &accounts, double amount);
void withdraw(std::vector<Trust_Account> &accounts, double amount);

#endif