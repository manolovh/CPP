#include <iostream> // cin/cout
#include <vector> // vectors
#include <string> // string
#include "oop.h"

void create_class();
void constructors();
void account1();
void player1();
void copy_object(Account object);
void display_shallow(Shallow obj);
void shallow_copy();

using namespace std;

class Player {
public:
    string name;
    int health;
    int xp;

    void show_health() {
        cout << name << "'s Health is " << health << endl;
    };
    bool show_experience() {
        cout << name << "'s Experience is " << xp << endl;
    };
    
    Player(string chosen_name, int chosen_health, int chosen_xp)
        : name {chosen_name}, health {chosen_health}, xp {chosen_xp} {
            cout << "Name, health and xp were passed." << endl;
    }
    Player()
        : Player {"None", 0, 0} { // called the previous constructor
            cout << "No arguments were passed." << endl;
    }
    Player(string name)
        : Player (name, 0, 0) { // called the previous constructor
        cout << "Only the name was passed." << endl;
    }
    ~Player() {
        cout << "The destuctor was called. Aborting the mission. :D" << endl;
    }
};

// Constructor init
Account::Account(string name_val, double balance_val, int id_val)
    : name {name_val}, balance {balance_val}, id_num {id_val} {
        }

// Copy constructor init
Account::Account(const Account &source)
    : name {source.name}, balance {source.balance}, id_num {source.id_num} {
        cout << "Copy constructor - made a copy of " << source.name << endl;
    }

void Account::set_balance(double bal){
    balance = bal;
}

double Account::get_balance(){
    return balance;
}

string Account::show_name(){
    return name;
}

int Account::get_id(){
    return id_num;
}

int main() {
    shallow_copy();
    return 0;
}

void display_shallow(Shallow obj) {
    cout << obj.get_data() << endl;
}

void shallow_copy() {
    Shallow obj1 {10};
    display_shallow(obj1);
    
    Shallow obj2 {obj1};
    obj2.set_data(200);
}

void copy_object(Account object) {
    cout << "A copy of " << object.show_name() << endl;
}

void account1() {
    Account account1;
    Account account2 {"Gosho", 10.2};
    Account account3 {"Pesho", 100, 23132};
    copy_object(account1);

    cout << account1.show_name() << " " << account1.get_balance() << " " << account1.get_id() << endl;
    cout << account2.show_name() << " " << account2.get_balance() << " " << account2.get_id() << endl;
    cout << account3.show_name() << " " << account3.get_balance() << " " << account3.get_id() << endl;
}

void player1() {
    Player player1;
    cout << player1.name << endl;
    cout << player1.health << endl;
    cout << player1.xp << endl;
    
    Player *player2 = new Player("Bro2", 20, 10);
    cout << player2->name << endl;
    cout << player2->health << endl;
    cout << player2->xp << endl;
    
    delete player2;
    cout << "Before descructor!" << endl;
}

void create_class() {
    Player gosho;
    Player pesho;

    Player *enemy = new Player();
    cout << enemy->health << endl;
    cout << enemy->xp << endl;
    
    enemy->health = 20;
    enemy->xp = 5;

    cout << (*enemy).health << endl; // same as enemy->health
    cout << (*enemy).xp << endl; // same as enemy->xp

    // used for testing private
    // gosho.show_health();
    // gosho.show_experience();
    // pesho.show_health();
    // pesho.show_experience();
}