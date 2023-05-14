#include <iostream>
#include <vector>

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
int main() {
    subset_looping();
    return 0;
} 