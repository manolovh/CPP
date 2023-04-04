#include <iostream>

using namespace std;

class Printable {
    /* declaring the ostream operator << as a friend to the Abstract
       base class, just so we don't need to declare it in each derived */
    friend ostream &operator<<(ostream &os, const Printable &obj);
public:
    /* using this declaration, all derived classes override this
       funciton and implement their required functionalities */
    virtual void print(ostream &os) const = 0;
    virtual ~Printable() {};
};

ostream &operator<<(ostream &os, const Printable &obj) {
    obj.print(os);
    return os;
}

class Derived : public Printable {
public:
    virtual void print(ostream &os) const override {
        os << "Print from Derived";
    }
};

// Abstract class as an Interface; Name it with and "I_" prefix (for Interface)(optional)
class I_Shape {
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    ~I_Shape() {};
};

class Circle : public I_Shape {
public:
    virtual void draw() {
        cout << "Inherited draw() from interface class" << endl;
    }
    virtual void rotate() {
        cout << "Inherited rotate() from interface class" << endl;
    }
    ~Circle() {};
};

void func1(Derived &obj) {
    cout << obj << endl; // If Derived is passed, will print Derived
}

void func2(Printable &obj) {
    cout << obj << endl; // If Derived is passed, will print Derived too
}
int main() {
    Derived *ptr = new Derived();
    cout << *ptr << endl;

    func1(*ptr);
    func2(*ptr);

    cout << "\n===========\n\n";

    I_Shape *p = new Circle();
    p->draw();
    p->rotate();

    delete ptr;
    delete p;

    return 0;
}