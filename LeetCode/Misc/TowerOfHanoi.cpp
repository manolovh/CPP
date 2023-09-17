#include <iostream>

void TowerOfHanoi(int n, int First, int Second, int Third)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, First, Third, Second);
        std::cout << "Move " << First << " to " << Third << std::endl;
        TowerOfHanoi(n - 1, Second, First, Third);
    }
}

int main()
{
    TowerOfHanoi(3, 1, 2, 3);
    return 0;
}