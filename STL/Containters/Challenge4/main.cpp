#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>

bool is_palindrome(const std::string &s) {
    std::queue<char> q;
    std::stack<char> stk;
    for (char c: s) {
        if (std::isalpha(c)) {
            q.push(std::toupper(c));
            stk.push(std::toupper(c));
        }
    }

    while (!q.empty()) {
        if (q.front() != stk.top())
            return false;
        q.pop();
        stk.pop();
    }

    return true;
}

int main() {
    for (std::string str: {"Pesep", "Gosho", "Ivan e, navi"})
        std::cout << is_palindrome(str)<< std::endl;

    return 0;
}