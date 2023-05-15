#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void example1() {
    std::vector<int> v {7, 3, 5};

    std::sort(v.begin(), v.end());

    for (auto elem: v)
        std::cout << elem << std::endl;

    std::reverse(v.begin(), v.end());

    for (auto elem: v)
        std::cout << elem << std::endl;

    int sum {};
    sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << sum << std::endl;
}

void iter_example() {
    std::vector<int> vec {1, 3, 3, 2, 2};
    
    auto location = std::find(vec.begin(), vec.end(), 2);

    if (location != vec.end())
        std::cout << *location << std::endl;
}

struct FunctEx {
    void operator()(int x) {
        std::cout << x * x * x << std::endl; 
    }
};

void functor_example() {
    FunctEx cubic;

    std::vector<int> vec {1, 3, 5, 10};

    std::for_each(vec.begin(), vec.end(), cubic); // functor
    std::for_each(vec.begin(), vec.end(), [](int x) {
            std::cout << x * x << std::endl; // lambda
        });
}

int main() {
    functor_example();
    return 0;
}