#include <iostream>

struct Data {
    int x, y;

    int* get_positions() {
        return &x;
    }
};

void implicit_conv() {
    int a = 5;
    double b = a;
    std::cout << &a << " " << &b << std::endl; // different addresses
}

void explicit_conv() {
    int a = 5;
    double b = (double) a; // C-style cast
    std::cout << &a << " " << &b << std::endl; // still different addresses
}

void address_copying() {
    int a = 5;
    double b = *(double *)&a; // dereference the pointer which points to address of `a`;
    // addresses are still not the same,
    // since you are referencing memory which was not allocated for `a`
    std::cout << &a << " " << &b << std::endl;
}

void struct_ex() {
    Data d = {10, 15};
    std::cout << d.x << ", " << d.y << std::endl;

    // the structure just has 2 elements, no other extra data
    // so we can reference it as an array

    // cast the first element of d (&d) as an int pointer (the beggining of an array)
    int *arr = (int *)&d;

    // now you can access it
    std::cout << arr[0] << ", " << arr[1] << std::endl;
}

void unnecessary_conversion() {
    Data d = {5, 8};

    /*Get the first element of d (with &d), cast it into a char* (1 byte size),
     then add + 4 (so you can access the next element). Now you have y, cast it
     back to an int*, dereference it and ... Voila - you have d.y :D */
    int y = *(int *)((char*)&d + 4);

    std::cout << y;
}

void struct_as_array() {
    Data d = {5, 10};

    int *arr = d.get_positions();

    std::cout << arr[0] << ", " << arr[1] << std::endl;
}

int main()
{
    struct_as_array();

    return 0;
}