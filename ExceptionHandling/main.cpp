#include <iostream>
#include <string>
#include <vector>

double calculate_av(int sum, int total) {
    if (total == 0) {
        std::cout << "Err... error: ";
        throw 0;
    }
    if (sum < 0 || total < 0) {
        throw 1;
    }
    if (sum / total == 69) {
        std::cout << "Noice!" << std::endl;
        throw std::string{"Noice"};
    }
    std::cout << "No error!" << std::endl;
    return static_cast<double>(sum) / total;
}

void example1() {
    try {                   // Throw by value
        calculate_av(10, 10);
        calculate_av(10, 0);
    }
    catch (int &ex) {       // Catch by reference
        std::cerr << "Cannot divide by zero" << std::endl;
    }
    std::cout << "Continue like nothing happened..." << std::endl;
}

void f3() {
    std::cout << "3 Called" << std::endl;
    throw 1;
    std::cout << "3 Exited" << std::endl;
}

void f2() {
    std::cout << "2 Called" << std::endl;
    f3();
    std::cout << "2 Exited" << std::endl;
}

void f1() {
    std::cout << "1 Called" << std::endl;
    f2();
    std::cout << "1 Exited" << std::endl;
}

void stack_unwinding() {
    try {
        f1();
    }
    catch (int &ex) {
        std::cout << "Error " << ex << std::endl;
    }
}

void example2() {
    try {
        calculate_av(69, 1);
    }
    catch (int &ex) {
        if (ex == 0)
            std::cerr << "Cannot divide by zero" << std::endl;
        else if (ex == 1) {
            std::cerr << "Negative values not allowed." << std::endl;
        }
    }
    catch (...) {
        std::cerr << "Unknown exception" << std::endl;
    }
}

int main() {
    stack_unwinding();
    return 0;
}
