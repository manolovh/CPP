#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Pesho {
private:
    string name {"Petar"};
    int age {18};
public:
    string get_name() {
        return name;
    }
    int get_age() {
        return age;
    }
};

// Classes A and B for weak_ptr example
class B;

class A {
    shared_ptr<B> b_ptr;
public:
    void set_B(shared_ptr<B> &b) {
        b_ptr = b;
    }
    A() {cout << "A constr" << endl;}
    ~A() {cout << "A destr" << endl;}
};

class B {
    
    // shared_ptr<A> a_ptr; // destructors of A or B never get called
    weak_ptr<A> a_ptr;
public:
    void set_A(shared_ptr<A> &a) {
        a_ptr = a;
    }
    B() {cout << "B constr" << endl;}
    ~B() {cout << "B destr" << endl;}
};

// Unique Pointers -------
void move_unique_ptr() {
    vector<unique_ptr<int>> vec;
    
    unique_ptr<int> ptr {new int{100}};

    // vec.push_back(ptr); // Error - copying unique_ptr is not allowed
    vec.push_back(move(ptr));
    cout << *vec[0] << endl;
}

void unique_ptr_func() {
    unique_ptr<Pesho> ptr {new Pesho {}};
    unique_ptr<int> p1 = make_unique<int>(100); // since C++14

    auto p2 = make_unique<Pesho>(); // since C++14

    cout << ptr->get_age() << endl;

    cout << ptr.get() << endl; // pointer to the managed object
    cout << &ptr << endl; // address of ptr

    ptr.reset(); // ptr is now nullptr
    // cout << ptr->get_age() << endl; // program stops

    move_unique_ptr();
}

// Shared Pointers -------
void shared_ptr_func() {
    shared_ptr<int> pesho1 {new int{100}};
    cout << pesho1.use_count() << endl;

    shared_ptr<int> pesho_copy {pesho1};
    cout << pesho_copy.use_count() << endl;

//     shared_ptr<int> pesho3 = make_shared<int>(pesho1);
//     cout << pesho3.use_count() << endl;
    pesho1.reset();
    cout << pesho1.use_count() << endl;
    cout << pesho_copy.use_count() << endl;
}

// Weak pointers -------
void weak_ptr_func() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);
}

// Custom deleters (for pointers)
void ptr_deleter(Pesho *raw_ptr) {
    // custom deleter here;
    cout << raw_ptr->get_name() << ", give the Rakija, don't hide!" << endl;
    delete raw_ptr;
}

void custom_deleters_func() {
    shared_ptr<Pesho> p1 {new Pesho{}, ptr_deleter};
    cout << p1->get_name() << ", where are you?" << endl;
}

int main() {
    custom_deleters_func();
    return 0;
}