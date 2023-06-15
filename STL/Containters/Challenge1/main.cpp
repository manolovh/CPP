#include <iostream>
#include <algorithm>
#include <cctype>
#include <deque>

bool is_palindrome(const std::string &str) {
    std::string str_cpy {};
    for (size_t i {0}; i < str.size(); i++) {
        if (isalpha(str[i]))
            str_cpy += toupper(str[i]);
    }

    std::deque<char> d;
    std::copy(str_cpy.begin(), str_cpy.end(), std::front_inserter(d));
    for (size_t i {0}; i < d.size(); ++i) {
        if (!(d[i] == d[d.size() - (i + 1)]))
            return false;
    }
    return true;
}

bool is_palindrome2(const std::string &str) {
    std::deque<char> d;

    for (char c: s) {
        if (std::isalpha(c))
            d.push_back(std::toupper(c));
    }
    
    char c1{};
    char c2{};
    while (d.size() > 1) {
        c1 = d.front();
        c2 = d.back();
        d.pop_front();
        d.pop_back();
        if (c1 != c2)
            return false;
    }
    return true;
}

int main() {
    std::cout << is_palindrome("red rum, sir, is murder") << std::endl;
    std::cout << is_palindrome("Hello") << std::endl;
    std::cout << is_palindrome("A Santa at Nasa") << std::endl;
}