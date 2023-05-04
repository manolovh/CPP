#include <iostream>
#include <utility>

// ---------------- Function Templates ----------------
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
// -------------- End Function Templates --------------

// ----------------- Class Templates ------------------
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

void func_template_ex() {
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
}

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

int main() {
    std::pair<std::string, int> pesho {"Pesho", 25};
    std::cout << pesho.first << std::endl;
    std::cout << pesho.second << std::endl;
    return 0;
}