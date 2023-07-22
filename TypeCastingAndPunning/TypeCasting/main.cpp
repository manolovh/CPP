#include <iostream>

class Base {
public:
    Base() = default;

    virtual void print() {
        std::cout << "Base" << std::endl;
    }
};

class Derived1 : public Base {
public:
    Derived1() = default;
    void print() {
        std::cout << "Derived1" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void print() {
        std::cout << "Derived2" << std::endl;
    }
};

void ex1() {
    int a = 5;
    float b;

    b = (float) a + 0.5;
    std::cout << b;
}

void ex2() {
    Derived1 d1;
    d1.print();

    // OK
    Base *b1 = dynamic_cast<Base*> (&d1);
    b1->print();

    // The line below errors out, because Derived2 is not compatible with Derived1
    // Derived2 *d2 = dynamic_cast<Derived2*> (&b1);
    // d2->print();

    // OK
    Derived1 *d2 = dynamic_cast<Derived1*> (b1);
    d2->print();

    // Prints 3 times `Derived1`
}

void ex3() {
    double x = 10;
    double* const pupil = &x;

    *pupil = 5;
}

int main() {
    ex3();
    return 0;
}