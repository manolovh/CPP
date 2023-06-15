#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
class Printer {
public:
    void operator()(const T &printee) {
        std::cout << printee << std::endl;
    }
};


void lambda_ex_1() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::vector<int> vec2 {5, 10, 15, 20, 25};
    Printer<int> p1;

    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << std::endl;});
    std::for_each(vec2.begin(), vec2.end(), p1);
}

void lambda_ex_2() {
    [](int x) {std::cout << x << std::endl;}(5); // calls the lambda and passes 5. Facsinating!
    auto lamb = [] (int x) { std::cout << "You chose: " << x << std::endl;};
    lamb(102);

    auto square = [] (int y) -> int { return y * y;};
    std::cout << square(5) << std::endl;
}

int main() {
    lambda_ex_2();
}