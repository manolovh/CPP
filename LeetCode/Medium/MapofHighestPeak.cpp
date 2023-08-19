#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        size_t total_size = isWater.size();
        for (int i = 0; i < total_size; ++i)
        {
            size_t current_size = isWater[i].size();
            for (int j = 0; j < current_size; ++j)
            {
                if ((isWater[i][j]) == 1)
                {
                    isWater[i][j] = 0;
                }
                else
                {
                    isWater[i][j] = 1;
                }
            }

            for (int j = 0; j < current_size; ++j)
            {
                if (isWater[i][j] != 0)
                {
                    add_on(isWater, i, j);
                }
            }
        }
        return isWater;
    }

    void add_on(vector<vector<int>>& isWater, int i, int j)
    {
        bool can_add;
        if (i > 0)
        {
            // Check previous sub-matrix
            can_add = isWater[i - 1][j] != 0;
            if (can_add)
            {
                can_add = ( abs((isWater[i][j] + 1) - (isWater[i - 1][j])) ) < 2;
            }
        }
        if (i < (isWater.size() - 1))
        {
           // Check next sub-matrix
            can_add = isWater[i - 1][j] != 0;
            if (can_add)
            {
                can_add = ( abs((isWater[i][j] + 1) - (isWater[i + 1][j])) ) < 2;
            }
        }
        if (j > 0)
        {
            // Check previous element in vector
            can_add = isWater[i - 1][j] != 0;
            if (can_add)
            {
                can_add = ( (isWater[i][j] + 1) - (isWater[i][j - 1]) ) < 2;
            }
        }
        if (j < (isWater[i].size() - 1))
        {
            // Check next element in vector
            can_add = isWater[i - 1][j] != 0;
            if (can_add)
            {
                can_add = ( (isWater[i][j] + 1) - (isWater[i][j + 1]) ) < 2;
            }
        }

        if (can_add)
        {
            isWater[i][j] += 1;
        }
    }
};


int main()
{
    Solution sol;
    std::vector<std::vector<int>> vec;

    std::vector<int> v{0, 1};
    vec.push_back(v);
    v = {0, 0};
    vec.push_back(v);

    vec = sol.highestPeak(vec);

    for (auto& elem: vec)
    {
        for (auto& elem2: elem)
        {
            std::cout << elem2 << " ";
        }
        std::cout << std::endl;
    }
}