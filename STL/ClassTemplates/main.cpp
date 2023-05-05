#include <iostream>
#include <utility>
#include <typeinfo>

template<typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value)
        : name{name}, value{value} {}
    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

template <typename T, int N>
class Array {
    int size {N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for (const auto &val: arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto &item: values)
            item = init_val;
    }
    void fill(T init_val) {
        for (auto &item: values)
            item = init_val;
    }
    int get_size() const {
        return size;
    }
    // overloaded subscript operator
    T &operator[](int index) {
        return values[index];
    }
};

void class_template_ex() {
    Item<int> milk{"Milk (gr)", 1000};
    Item<int> almonds{"Almonds (gr)", 100};
    Item<double> gold_necklace{"Gold necklace (gr)", 1.92};
    Item<std::string> book{"J.B.Peterson (book)", "Beyond order"};

    std::cout << milk.get_name() << " - " << milk.get_value() << std::endl;
    std::cout << almonds.get_name() << " - " << almonds.get_value() << std::endl;
    std::cout << gold_necklace.get_name() << " - " << gold_necklace.get_value() << std::endl;
    std::cout << book.get_name() << " - " << book.get_value() << std::endl;
}

void array_ex() {
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl; 
    std::cout << nums << std::endl; 

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl; 
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[1] = 100;
    nums[2] = 200;
    std::cout << nums << std::endl;

    Array<int, 100> nums2 {1};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl; 
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings (std::string{"Pesho"});
    std::cout << "The size of strings is: " << strings.get_size() << std::endl; 
    std::cout << strings << std::endl;

    strings[0] = std::string{"Gosho"};
    strings[1] = "Gosho"; // no difference between this and the previous one, it seems
    std::cout << strings << std::endl;
    std::cout << typeid(strings[0]).name() << std::endl;
    std::cout << typeid(strings[1]).name() << std::endl;
}

int main() {
    array_ex();
    return 0;
}