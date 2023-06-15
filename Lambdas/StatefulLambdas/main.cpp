#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p) = default;
    ~Person() = default;
    std::string get_name() const {return name;}
    void set_name(std::string name) {this->name = name;}
    int get_age() const {return age;}
    void set_age(int age) {this->age = age;}

    // All captures below capture by reference 
    auto change_obj1() {return [this] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
    auto change_obj2() {return [=] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
    auto change_obj3() {return [&] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << "Person: " << p.name << " | Age: " << p.age;
    return os;
}

void ex1() {
    int y {20};

    auto stateful_l = [y] (int x) {std::cout << x + y;};

    stateful_l(5);
}

// Using the above lambda, the compiler generates a closure:
class CompilerName {
private:
    int y;
public:
    CompilerName(int y) : y{y} {};

    void operator() (int x) const {
        std::cout << x + y;
    }
};


void ex2() {
    int x{10};
    int y{20};

    // Capture by value, read-only by default
    auto capt_value = [x] () {std::cout << x << std::endl;};

    // Capture by value, modifiable
    auto capt_mod_value = [x] () mutable {
        x += 10;
        std::cout << x << std::endl;
    };

    // Capture by reference
    auto capt_ref = [&x] () {
        x = 50;
    };

    // Default captures
    auto default_capt1 = [=] () {std::cout << "Default 1: " << x << std::endl;}; // Capture all by value
    auto default_capt2 = [&] () {std::cout << "Default 2: " << x << std::endl;}; // Capture all by reference

    // Mixed (default and explicit) capture
    auto mixed_capt = [&, x] () {y = 30; std::cout << x << " " << y << std::endl;}; // Default capture by ref, but x by value

    capt_value();
    capt_mod_value();
    capt_ref();

    capt_value();

    default_capt1();
    default_capt2();

    mixed_capt();
}

void ex3() {
    Person gosho("Gosho", 20);
    std::cout << gosho << std::endl;

    auto change_gosho = gosho.change_obj1();
    change_gosho("Georgi", 25);
    std::cout << gosho << std::endl;
}

void ex4() {
    std::vector<int> vec {1, 2, 3, 4, 5};

    // Push back all even numbers and get an iterator to the first
    auto it = std::remove_if(vec.begin(), vec.end(), [] (int num) {
        return num % 2 == 0;
    });

    // Erase numbers from the first even to the end (all even)
    vec.erase(it, vec.end());

    for (auto num: vec)
        std::cout << num << std::endl;
}

int main() {
    ex4();
    return 0;
}