#include <iostream>
#include <cmath>
#include <typeinfo>

class Solution
{
public:
    int minSteps(int n)
    {
        int* num_arr = new int[n + 1] {0};

        // Store steps for all numbers
        for (int i = 2; i <= n; i++)
        {
            num_arr[i] = i;
            for (int j = i - 1; j > 1; j--)
            {
                // If num is divisible by already stored steps, get them
                // and multiply them with the division of both. Break, since this is the best solution.
                if (i % j == 0)
                {
                    num_arr[i] = num_arr[j] + (i / j);
                    break;
                }
            }
        }
        return num_arr[n];
    }
};

int main()
{
    Solution sol;
    std::cout << sol.minSteps(9) << std::endl;
}
