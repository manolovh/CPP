#include <iostream>
#include <memory>
#include "Accountt.h"
#include "Check_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    std::unique_ptr<Accountt> goshos_account;
    std::unique_ptr<Accountt> peshos_account;
    try {
        peshos_account = std::make_unique<Check_Account>("Pesho", -10000);
        std::cout << *peshos_account << std::endl;
    }
    catch (IllegalBalanceException &ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "This prints?" << std::endl;
    goshos_account = std::make_unique<Check_Account>("Gosho", 10000);
    try {
        goshos_account->withdraw(12000.0);
    }
    catch (InsufficientFundsException &ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

