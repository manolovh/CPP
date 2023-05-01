#include <iostream>
#include <iomanip>

void bool_formatting() {
    std::cout << std::boolalpha;
    std::cout << (9 < 11) << std::endl;

    // same as std::resetiosflags(std::ios::boolalpha)
    std::cout << std::noboolalpha;
    std::cout << (9 < 11) << std::endl;
}

void integer_formatting() {
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << 255 << std::endl; // FF
    std::cout << std::oct << 255 << std::endl; // 377
    std::cout << std::dec << 255 << std::endl; // 255
    
    // used to show hexadecimal or octal
    std::cout << std::noshowbase << std::nouppercase;;
    
    std::cout << std::showpos;
    std::cout << -10 << std::endl;
    std::cout << 10 << std::endl;

    std::cout << std::noshowpos;
}

void float_formatting() {
    std::cout << std::setprecision(6); // 6 digits total and rounding
    std::cout << 10.0291912321213 << std::endl; // 10.0292

    std::cout << std::fixed; // fixed (no rounding), 6 digits from the decimal
    std::cout << 10.992929929 << std::endl; // 10.992930

    std::cout << std::setprecision(3) << std::scientific;
    std::cout << 100101.100101001 << std::endl; // 1.001e+005

    std::cout << std::showpos;
    std::cout << 11.2344 << std::endl; // +1.123e+001

    // reset most manipulators with std::resetiosflags
    std::cout << std::resetiosflags(std::ios::scientific)
              << std::resetiosflags(std::ios::fixed)
              << std::resetiosflags(std::ios::showpos);
    std::cout << std::showpoint << std::setprecision(6);

    std::cout << 12.34 << std::endl; // +12.3400
    std::cout << 12.34 << std::endl; // +12.3400
}

void width_align_fill() {
    /* right justifies the first element 10 width
       setw(n) applies only to the next element after it */
    std::cout << std::setw(10) << 1515
              << std::setw(10) << 2020 << std::endl;

    std::cout << std::setw(10)
              // left justifies to the left and sets spaces to dots(.)
              << std::left << std::setfill('.')
              << 12345 << 12345 << std::endl;
}

int main() {
    width_align_fill();
    return 0;
}
