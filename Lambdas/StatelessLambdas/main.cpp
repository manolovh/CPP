#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>


void ex1() {
    auto add = [] (int x, int y) {return x + y;};
    std::cout << add(2, 5) << std::endl;

    auto add_via_ref = [] (int *x, int *y) {return (*x) + (*y);};

    int x = 50;
    int y = 100;

    std::cout << add_via_ref(&x, &y) << std::endl;
}


void ex2() {
    auto add_points = [] (int &x, int &y, int points) {
        x += points;
        y += points;
    };

    int x = 10;
    int y = 15;

    add_points(x, y, 10);
    std::cout << x << " " << y << std::endl;
}


void ex3() {
    std::vector<int> v1 {10, 20, 30, 40};
    std::vector<double> v2 {10.1, 20.2, 30.3, 40.4};

    // auto is powerful when you want to pass multiple types as parameter
    auto add_on = [] (auto &vec, int points) {
        for (auto &score: vec)
            score += points;
    };

    add_on(v1, 10);
    add_on(v2, 15);

    for (auto elem: v1) {
        std::cout << elem << " ";
    }

    for (auto elem: v2) {
        std::cout << elem << " ";
    }
}


void print_if(std::vector<int> nums, bool (*predicate) (int)) {
    for (int i: nums)
        if (predicate(i))
            std::cout << i << " ";
    std::cout << std::endl;
}


void ex4() {
    std::vector<int> vec1 {10, 15, 20, 25, 30};
    print_if(vec1, [] (int x) {return x % 2 == 0;});
    print_if(vec1, [] (int x) {return x % 2 != 0;});

}

// std::function -> function expects a function object as argument
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func) {
    for (int i: vec) {
        if (func(i))
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

void ex5() {
    std::vector<int> vec {1, 5, 10, 15, 20, 7, 3};
    filter_vector(vec, [](int x) {return x >= 10;});
}

void ex6() {
    auto multi_lambda = [] (auto x, auto y) {
        std::cout << x << ", " << y << std::endl;
    };

    multi_lambda(10, 20);
    multi_lambda(10, 2.5);
    multi_lambda(1.1, 5.32);
    multi_lambda("Pesho", "Georgiev");

}
 
int main() {
    ex6();
    return 0;
}

