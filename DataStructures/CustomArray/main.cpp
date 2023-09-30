#include <iostream>
#include <chrono>
#include <ctime>
#include "CustomArray.hpp"

class Timer
{
public:
    std::chrono::time_point<std::chrono::system_clock> StartTime;
    Timer()
    {
        StartTime = std::chrono::system_clock::now();
    }
    ~Timer()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime = std::chrono::system_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(endTime - StartTime).count() << std::endl;
    }
};

void f1()
{
    int a1[50] = { 2, 3, 6, 7, 8, 10 };
    int a2[50] = { 2, 4, 6, 8, 10, 11 };
    Array arr1 = { a1, 50, 6 };
    Array arr2 = { a2, 50, 6 };

    Array* arr3 = arr1.make_union(&arr2);
    Array* arr4 = arr1.get_intersection(&arr2);
    Array* arr5 = arr1.get_difference(&arr2);

    for (int i = 0; i < arr5->get_length(); i++)
    {
        std::cout << (*arr5)[i] << " ";
    }
}

void f2()
{
    int a1[50] = { 1, 2, 3, 5, 6, 7, 10, 11 };
    Array arr1 = { a1, 50, 8 };

    arr1.find_missing();

    int a2[50] = { 3, 4, 2, 5, 1, 7, 10, 9, 12 };
    Array arr2 = { a2, 50, 9 };
    arr2.find_missing_unsorted();
}

void f3()
{
    int a1[50] = { 4, 2, 1, 7, 4, 6, 2, 8 };
    Array arr1 = { a1, 50, 8 };

    int a2[50] = { 1, 3, 3, 6, 6, 6, 8, 8 };
    Array arr2 = { a2, 50, 8 };

    arr1.find_duplicates();
    arr2.find_duplicates();
}

void f4()
{
    int a1[50] = { 5, 9, 4, 3, 1, 7, 6, 2, 10, 8, 0 };
    Array arr1 = { a1, 50, 11 };

    arr1.find_pair(8);

    std::cout << "==================" << std::endl;

    int a2[50] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Array arr2 = { a2, 50, 11 };

    arr2.sorted_find_pair(8);
}

int main()
{
    Timer t;
    int a1[50] = { -5, 7, 2, 8, 0, 5, 10, 16, -9, 7, 4 };
    Array arr1 = { a1, 50, 11 };

    arr1.find_min_max();
}
