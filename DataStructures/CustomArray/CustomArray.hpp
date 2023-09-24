#ifndef CUSTOM_ARRAY_HPP
#define CUSTOM_ARRAY_HPP

class Array
{
private:
    int *m_array;
    size_t size;
    size_t length;

public:
    Array(size_t size, size_t length);
    Array(int *array, size_t size, size_t length);

    int get(int idx);
    void set(int idx, int value);

    double avg();
    int sum();

    int min();
    int max();

    void insert(int idx);
    void remove(int idx);

    Array* merge(Array* arr);
    void display();

    void reverse();
    void rearrange();

    int& operator[](int idx);

    int binary_search(int num);
    int linear_search_1(int num);
    int linear_search_2(int num);

    bool is_sorted();
    int get_length();

    Array* make_union(Array* arr);

    ~Array();
};

#endif