#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

void iterator_ex() {
    std::vector<int> vec {1, 5, 10};
    std::vector<int>::iterator it;

    it = vec.begin();
    while (it != vec.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    std::vector<int>::reverse_iterator reverse_it = vec.rbegin();
    while (reverse_it != vec.rend()) {
        std::cout << *reverse_it << std::endl;
        ++reverse_it;
    }
}

void subset_looping() {
    std::vector<int> vec {1, 5, 10, 20, 50, 100};
    auto start = vec.begin() + 1;
    auto end = vec.end() - 1;

    // will print elements from the second to the last(exclusive)
    while (start != end) {
        std::cout << *start << std::endl;
        ++start;
    }
}

void count_if_ex() {
    std::vector<int> vec {1, 5, 1, 20, 50, 1};
    int even_nums = std::count_if(std::begin(vec), std::end(vec), [](int num) {return num % 2 == 0;});
    int odd_nums = std::count_if(std::begin(vec), std::end(vec), [](int num) {return num % 2 != 0;});

    std::cout << "Odd: " << odd_nums << " | Even: " << even_nums << std::endl;
    
    std::replace(vec.begin(), vec.end(), 1, 33);
    for (auto elem: vec)
        std::cout << elem << " ";
}

void all_any_of_ex() {
    std::vector<int> vec {1, 5, 10, 15, 20, 10, 25, 5};
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 10;}))
        std::cout << "All elements are greater than 10" << std::endl;
    else
        std::cout << "Not all elements are greater than 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x < 50;}))
        std::cout << "All elements are less than 50" << std::endl;
    else
        std::cout << "Not all elements are less than 50" << std::endl;

    if (std::any_of(vec.begin(), vec.end(), [] (int x) { return x == 25;}))
        std::cout << "At least one element is equal to 25" << std::endl;
    else
        std::cout << "There's no element equal to 25" << std::endl;    
}

void transform_ex() {
    std::string str {"Gosho goes hunting."};
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // `::` for global scope
    std::cout << str << std::endl;
}

int main() {
    transform_ex();
    return 0;
} 