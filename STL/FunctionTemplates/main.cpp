#include <iostream>

template <typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}

template <typename T, typename N>
void print(T a, N b) {
    std::cout << a << " and " << b << std::endl;
}

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

struct Person {
    std::string name;
    int age;
    bool operator>(const Person &rhs) const {
        return this->age > rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name;
    return os; 
}


int main() {
    std::cout << max<int>(12, 10) << std::endl;
    std::cout << max<double>(10.0, 12.0) << std::endl;
    std::cout << max<char>('a', 'c') << std::endl;
    std::cout << max<long>(1001l, 1000l) << std::endl;
    std::cout << max<float>(6.99f, 6.9f) << std::endl;

    print<int, std::string>(10, "Pesho");

    Person pesho {"Pesho", 25};
    Person gosho {"Gosho", 20};
    Person who = max(gosho, pesho);
    std::cout << who.name << " is older." << std::endl;

    print(pesho, gosho);

    int a = 10;
    int b = 20;
    swap(a, b);

    std::cout << a << " " << b << std::endl;
    return 0;
}