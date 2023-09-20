#ifndef CUSTOM_ARRAY_HPP
#define CUSTOM_ARRAY_HPP

typedef struct
{
    int array[50];
    size_t size;
    size_t length;
} ArrayStruct;

class Array
{
private:
    int *array;
    size_t size;
    size_t length;

public:
    Array(int array[50], size_t size, size_t length);

    int get(int idx);

    void set(int idx, int value);

    double avg();

    int sum();

    int max();

    int min();

    void reverse();

    void display();

    void insert(int x);

    bool is_sorted();

    void rearrange();
};

#endif