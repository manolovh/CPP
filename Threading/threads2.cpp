#include <iostream>
#include <thread>
#include <mutex>

void print(int x)
{
    for (int i = 0; i < x; i++)
    {
        std::cout << "I really am threaded: " << i << std::endl;
    }
}

int main()
{
    int x = 5;
    std::mutex m;
    auto l1 = [&]()
    {
        m.lock();
        x *= 2;
        std::cout << "doubled x!" << std::endl;
        m.unlock();
    };
    auto l2 = [&]()
    {
        m.lock();
        std::cout << "X is now: " << x << std::endl;
        m.unlock();
    };
    std::thread t1(l1);
    std::thread t2(l2);

    t1.join();
    t2.join();

    return 0;
}