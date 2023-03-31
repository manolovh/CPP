#ifndef _MYSTRING_H_
#define _MYSTRING_H_


class MyString {
    // all below, implemented by friend functions
    // friend MyString operator++(const MyString &obj, int);
    // friend MyString &operator++(const MyString &obj);
    // friend MyString operator*=(const MyString &lhs, int times);
    // friend MyString operator*(const MyString &lhs, int times);
    // friend MyString operator+=(const MyString &lhs, const MyString &rhs);
    // friend MyString operator+(const MyString &lhs, const MyString &rhs);
    // friend bool operator>(const MyString &lhs, const MyString &rhs);
    // friend bool operator<(const MyString &lhs, const MyString &rhs);
    // friend bool operator!=(const MyString &lhs, const MyString &rhs) const;
    // friend bool operator==(const MyString &lhs, const MyString &rhs) const;
    // friend MyString operator-(const MyString &lhs) const;
    // friend istream &operator>>(istream &is, MyString &obj);
    // friend ostream &operator<<(ostream &os, const MyString &obj);
    
private:
    char *str; // C-style string

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();

    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);

    bool operator==(const MyString &rhs) const;
    MyString operator+(const MyString &rhs) const;
    MyString operator-() const;
    bool operator!=(const MyString &rhs) const;
    bool operator<(const MyString &rhs);
    bool operator>(const MyString &rhs);
    MyString operator+(const MyString &rhs);
    MyString operator+=(const MyString &rhs);
    MyString operator*(int times);
    MyString operator*=(int times);
    MyString &operator++();
    MyString operator++(int);

    int get_length() const;
    const char *get_str() const;
};

#endif