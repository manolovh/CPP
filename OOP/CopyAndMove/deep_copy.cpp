#include <iostream> // cin/cout
#include <string> // string

using namespace std;

class Deep {
private:
    int *data;
public:
    Deep(int d); // Constructor
    Deep(const Deep &source); // Copy Constructor
    Deep(Deep &&source); // Move Constructor
    ~Deep(); // Destructor
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// Copy constructor(for l-values)
Deep::Deep(const Deep &source)
    // Calls the int constructor
    : Deep(*source.data) {}
/*
// Same as the example above
Deep::Deep(const Deep &source) {
    // here we create a new instance in memory,
    // we then copy the source's data in the new instance,
    // this way, when we free the dynamically allocated object,
    // the original object is untouched and still valid. 
    data = new int;
    *data = *source.data;
}*/

// Move constructor (for r-values)
Deep::Deep(Deep &&source)
// 'Steals' the data from the source and then nulls out the source pointer
    : data(source.data) {
        source.data = nullptr;
    }

Deep::~Deep() {
    delete data; // free allocated storage
}

string func(int &num) {return "Var passed";};
string func(int &&num) {return "Num passed";};

void r_l_values2() {
    int x {100};

    cout << func(x) << endl;
    cout << func(200) << endl;
    cout << func(200) << endl;
    cout << func(x) << endl;
}

void r_l_values() {
    int x {100};
    int &l_reference = x;
    l_reference = 10;
    cout << x << endl;
    cout << l_reference << endl;

    int &&r_reference = 100;
    r_reference = 200;
    cout << x << endl;
    cout << r_reference << endl;
}

void pointer_copy(){ 
    // initialize a variable
    int d {7};
    // initialize the pointer
    int *data;
    // allocate memory on the heap
    data = new int;
    cout << data << endl;
    // modify what the pointer is pointing to: address ex. 0x6517x0 becomes 7
    *data = d;
    cout << *data << endl;
}

int main() {
    r_l_values2();
    const int &x {100};
    cout << &x << endl;

    string s1 {"Hello, "};
    string s2 {"World"};
    string &&str_ref {s1 + s2};
    str_ref += "!"; // modify the existing str_ref without creating a new object
    cout << str_ref << endl;
}