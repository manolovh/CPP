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
    virtual void withdraw(double amount) {
        cout << "Savings Account withdrawal" << endl;
    }
    virtual ~Savings_Account() {cout << "Savings virtual destructor" << endl;}
};

class Trust_Account : public Account {
private:
    double amount;
public:
    // best practise is to put virtual in all derived classes, for better readibility
    virtual void withdraw(double amount) {
        cout << "Trust Account withdrawal" << endl;
    }
    virtual ~Trust_Account() {cout << "Trust virtual destructor" << endl;}
};

int main() {
    Account *p1 = new Account();
    Account *p2 = new Savings_Account();
    Account *p3 = new Trust_Account();
    Account *p4 = new Trust_Account();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    cout << "\nFreeing: " << endl;

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}