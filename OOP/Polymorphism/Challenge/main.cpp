// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_Printable.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    vector<Account *> accounts;
    Account *acc2 = new Savings_Account{"Wonderwoman", 5000, 5.0};
    Account *acc3 = new Checking_Account{"Spock", 2000};
    Account *acc4 = new Trust_Account{"Aramis", 30000};

    accounts.push_back(acc2);
    accounts.push_back(acc3);
    accounts.push_back(acc4);
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);

    delete acc2;
    delete acc3;
    delete acc4;

    return 0;
}

