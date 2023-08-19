#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        for (auto& vec: isWater)
        {
            std::replace(vec.begin(), vec.end(), 1, 2);
            std::replace(vec.begin(), vec.end(), 0, 1);
            std::replace(vec.begin(), vec.end(), 2, 0);
        }
        size_t total_size = isWater.size();
        size_t elements_size = isWater[0].size();
        size_t total_elements = total_size * elements_size;

        for (int a = 0; a < total_elements; ++a)
        {
            for (int i = 0; i < total_size; ++i)
            {
                for (int j = 0; j < elements_size; ++j)
                {
                    if (isWater[i][j] != 0)
                    {
                        bool can_add = true;
                        while (can_add)
                            add_on(isWater, i, j, can_add);
                    }
                }
            }
        }
        return isWater;
    }

    void add_on(vector<vector<int>>& isWater, int i, int j, bool& can_add)
    {
        if (i > 0)
        {
            // Check previous sub-matrix
            can_add = isWater[i - 1][j] != 0;
            if (can_add)
                can_add = ( (isWater[i][j] + 1) - (isWater[i - 1][j]) ) < 2;
        }
        if (i < (isWater.size() - 1))
        {
           // Check next sub-matrix
            if (can_add)
                can_add = isWater[i + 1][j] != 0;

            if (can_add)
                can_add = ( (isWater[i][j] + 1) - (isWater[i + 1][j]) ) < 2;
        }
        if (j > 0)
        {
            // Check previous element in vector
            if (can_add)
                can_add = isWater[i][j - 1] != 0;

            if (can_add)
                can_add = ( (isWater[i][j] + 1) - (isWater[i][j - 1]) ) < 2;
        }
        if (j < (isWater[i].size() - 1))
        {
            // Check next element in vector
            if (can_add)
                can_add = isWater[i][j + 1] != 0;

            if (can_add)
                can_add = ( (isWater[i][j] + 1) - (isWater[i][j + 1]) ) < 2;
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

    std::vector<int> v{0, 0};
    vec.push_back(v);
    v = {1, 1};
    vec.push_back(v);
    v = {1, 0};
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
