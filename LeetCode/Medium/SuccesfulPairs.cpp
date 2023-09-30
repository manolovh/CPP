#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> successful (spells.size(), 0);
        success = success - 1;
        std::sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++)
        {
            int beggining = 0, end = potions.size() - 1;
            while (beggining <= end)
            {
                int middle = (beggining + end) / 2;
                if (static_cast<long>(spells[i]) * potions[middle] > success)
                {
                    end = middle - 1;
                }
                else
                {
                    beggining = middle + 1;
                }
            }
            successful[i] = potions.size() - beggining;
        }
        return successful;
    }
};


int main()
{
    vector<int> spells {3, 1, 2};
    vector<int> potions {8, 5, 8};
    long long success = 16;
    Solution sol;

    vector<int> v = sol.successfulPairs(spells, potions, success);

    for (auto elem : v)
    {
        std::cout << elem << " ";
    }
}