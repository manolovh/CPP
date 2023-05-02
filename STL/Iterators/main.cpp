#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
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

    return 0;
}