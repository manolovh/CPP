#include <iostream>
#include <vector>

void PrintValue(int value)
{
    std::cout << value << std::endl;
}

void PrintDoubleValue(int value)
{
    std::cout << value * 2 << std::endl;
}

void ForEach(const std::vector<int> &vec, void(*func)(int))
{
    for (auto elem: vec)
        func(elem);
}

int main() {
    auto function = PrintValue;
    function(10);

    std::vector<int> vec {1, 10, 100, 1000};
    ForEach(vec, PrintValue);
    ForEach(vec, PrintDoubleValue);
    // both things above can be done with a simple lambda:
    ForEach(vec, [](int value) {std::cout << value * 3 << std::endl;});
}