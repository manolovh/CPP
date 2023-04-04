#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    double amount;
public:
    virtual void withdraw(double amount) {
        cout << "Account withdrawal" << endl;
    }
    virtual ~Account() {cout << "Account virtual destructor" << endl;}
};

class Savings_Account : public Account {
private:
    double amount;
public:
    // best practise is to put virtual in all derived classes, for better readibility
    virtual void withdraw(double amount) override {
        cout << "Savings Account withdrawal" << endl;
    }
    virtual ~Savings_Account() {cout << "Savings virtual destructor" << endl;}
};

class Trust_Account : public Account {
private:
    double amount;
public:
    // best practise is to put virtual in all derived classes, for better readibility
    virtual void withdraw(double amount) override {
        cout << "Trust Account withdrawal" << endl;
    }
    virtual ~Trust_Account() {cout << "Trust virtual destructor" << endl;}
};

void outside_withdraw(Account &acc, double amount) {
    acc.withdraw(amount);
}

int main() {
    Account *p1 = new Account();
    Account *p2 = new Savings_Account();
    Account *p3 = new Trust_Account();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);

    Trust_Account t;
    Account &ref_t = t;
    ref_t.withdraw(100); // Trust::withdraw() called
    cout << "\n==========\n";

    Savings_Account s;
    Account &ref_s = s; 

    outside_withdraw(ref_t, 100.0);
    outside_withdraw(ref_s, 100.0);

    cout << "\nFreeing: " << endl;

    delete p1;
    delete p2;
    delete p3;

    return 0;
}