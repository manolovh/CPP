#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mut;
int sum = 0;

void printer()
{
    mut.lock();
    cout << sum << " + 1 -> ";
    sum++;
    cout << sum << endl;
    mut.unlock();
}

void adder()
{
    mut.lock();
    cout << sum << " + 5 -> ";
    sum += 5;
    cout << sum << endl;
    mut.unlock();
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        thread t1(printer);
        thread t2(adder);
        t1.join();
        t2.join();
    }
    return 0;
}