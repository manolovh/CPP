#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "MyString.h"

using namespace std;

// no-arg constr
MyString::MyString()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

// arg constr
MyString::MyString(const char *s)
    : str {nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        }
         else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
         }       
    }

// copy constr
MyString::MyString(const MyString &source)
    : str{nullptr} {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        cout << "Deep copy" << endl;
    }

// move constr
MyString::MyString(MyString &&source)
    : str(source.str) {
        source.str = nullptr;
        cout << "Move constructor" << endl;
    }

// destructor
MyString::~MyString() {
    delete [] str;
}

// overload copy assignment
MyString &MyString::operator=(const MyString &rhs) {
    cout << "Copy assignment" << endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);

    return *this;
}

// overload move assignment
MyString &MyString::operator=(MyString &&rhs) {
    cout << "Move assignment" << endl;
    if (this == &rhs)
        return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

// overload -
MyString MyString::operator-() const {
    MyString temp {(this->str)};
    for (size_t i = 0; i < strlen(temp.str); i++)
        temp.str[i] = tolower(temp.str[i]);
    return temp;
}

// overload ==
bool MyString::operator==(const MyString &rhs) const {
    return (strcmp(str, rhs.str) == 0);
}

// overload !=
bool MyString::operator!=(const MyString &rhs) const {
    return !(strcmp(str, rhs.str) == 0);
}

// overload <
bool MyString::operator<(const MyString &rhs) {
    return (strcmp(str, rhs.str) < 0);
}

// overload >
bool MyString::operator>(const MyString &rhs) {
    return (strcmp(str, rhs.str) > 0);
}

// overload +
MyString MyString::operator+(const MyString &rhs) {
    char *buff = new char[strlen(this->str) + strlen(rhs.str) + 1];
    strcpy(buff, this->str);
    strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}

//overload +=
MyString MyString::operator+=(const MyString &rhs) {
    *this = *this + rhs;
    return *this;
}

// overload *
MyString MyString::operator*(int times) {
    char *buff = new char[(strlen(this->str) * times) + 1];
    for (int i {0}; i < times; i++) {
        if (i == 0)
            strcpy(buff, this->str);
        else
            strcat(buff, this->str);
    }
    MyString temp {buff};
    delete [] buff;
    return temp;
}

// overload *=
MyString MyString::operator*=(int times) {
    *this = *this * times;
    return *this;
}

// overload pre-increment ++var;
MyString &MyString::operator++() {
    char *message = new char[7];
    strcpy(message, "Top G ");
    char *buff = new char [strlen(message) + strlen(this->str) + 1];
    strcpy(buff, message);
    strcat(buff, this->str);
    *this = MyString {buff};
    delete [] message;
    delete [] buff;
    return *this;
}

// overload pre-increment ++var;
MyString MyString::operator++(int) {
    MyString temp (*this);
    operator++();
    return temp;
}

// overload <<
ostream &operator<<(ostream &os, const MyString &obj) {
    // os << obj.str; // if ostream is a friend function to the class
    os << obj.get_str(); // if ostream is not a friend function
    return os;
}

// overload >>
istream &operator>>(istream &is, MyString &obj) {
    char *buff = new char[1000];
    is >> buff;
    obj = MyString(buff); // if you have Copy or Move assignment
    delete [] buff;
    return is;
}

int MyString::get_length() const { return strlen(str); }

const char *MyString::get_str() const { return str; }


int main() {
    MyString a{"Gosho"};
    MyString b{"Pesho"};

    cout << boolalpha;
    cout << -a << endl; // - overload
    cout << (a == b) << endl; // == overload
    cout << (a != b) << endl; // != overload
    cout << (a < b) << endl; // < overload
    cout << (a > b) << endl; // > overload

    MyString c;
    c = a + b;
    c += a;

    c = b * 3;
    
    cout << c++ << endl;
    cout << c << endl;
    cout << ++c << endl;
    
    // cout << a << endl; // overloaded extraction operator
    // cin >> a; // overloaded insertion operator
    a *= 3;
    cout << a << endl;

    return 0;
}
