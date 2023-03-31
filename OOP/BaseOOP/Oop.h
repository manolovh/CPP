#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    string name;
    double balance;
    int id_num;
public:
    string show_name();
    double get_balance();
    void set_balance(double bal);
    int get_id();

    Account(string name_val = "None", double balance_val = 0.0, int id_val = 0);
    // Copy constructor
    Account(const Account &source); // source is optional
    // Destructor
    ~Account() {cout << name << " destructor called." << endl;}
};

#endif