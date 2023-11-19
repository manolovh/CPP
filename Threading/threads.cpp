#include <iostream>
#include <thread>

struct A
{
    void operator() () const
    {
        for (int i = 1; i < 500; i++)
        {
            std::cout << i << std::endl;
        }
    }
};
struct B
{
    void operator() () const
    {
        for (int i = 500; i < 1000; i++)
        {
            std::cout << i << std::endl;
        }
    }
};

int main()
{
    A a;
    B b;
    std::thread worker(a);
    std::thread worker2(b);

    worker.join();
    worker2.join();
}