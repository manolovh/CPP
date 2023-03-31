#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "MyString.h"

using namespace std;

// overload -
MyString operator-(const MyString &lhs) const {
    MyString temp {lhs.str};
    for (size_t i = 0; i < strlen(temp.str); i++)
        temp.str[i] = tolower(temp.str[i]);
    return temp;
}

// overload ==
bool operator==(const MyString &lhs, const MyString &rhs) const {
    return (strcmp(lhs.str, rhs.str) == 0);
}

// overload !=
bool operator!=(const MyString &lhs, const MyString &rhs) const {
    return !(strcmp(lhs.str, rhs.str) == 0);
}

// overload <
bool operator<(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) < 0);
}

// overload >
bool operator>(const MyString &lhs, const MyString &rhs) {
    return (strcmp(lhs.str, rhs.str) > 0);
}

// overload +
MyString operator+(const MyString &lhs, const MyString &rhs) {
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}

//overload +=
MyString operator+=(const MyString &lhs, const MyString &rhs) {
    lhs = lhs + rhs;
    return *this;
}

// overload *
MyString operator*(const MyString &lhs, int times) {
    char *buff = new char[(strlen(lhs.str) * times) + 1];
    for (int i {0}; i < times; i++) {
        if (i == 0)
            strcpy(buff, lhs.str);
        else
            strcat(buff, lhs.str);
    }
    MyString temp {buff};
    delete [] buff;
    return temp;
}

// overload *=
MyString operator*=(const MyString &lhs, int times) {
    lhs = lhs * times;
    return lhs;
}

// overload pre-increment ++var;
MyString &operator++(const MyString &lhs) {
    char *message = new char[7];
    strcpy(message, "Top G ");
    char *buff = new char [strlen(message) + strlen(lhs.str) + 1];
    strcpy(buff, message);
    strcat(buff, lhs.str);
    *this = MyString {buff};
    delete [] message;
    delete [] buff;
    return lhs;
}

// overload pre-increment ++var;
MyString operator++(const MyString &rhs, int) {
    MyString temp{rhs};
    ++rhs();
    return temp;
}


int main() {
    MyString a{"Gosho"};
    MyString b{"Pesho"};
    MyString c;
    c = a + b;
    c = b * 3;

    a *= 3;
    cout << a << endl;
    cout << c << endl;

    return 0;
}
