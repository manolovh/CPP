#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements)
    {
        int max_good_people = 0;
        int current_max = 0;
        size_t size = statements[0].size();

        vector<vector<int>> people(size, vector<int>(size, 2));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (statements[i][j] == 0)
                {
                    people[i][j] = statements[i][j];
                }
            }
        }


        for (int i = 0; i < size; i++)
        {
            if (people[0][i] == 1)
                current_max += 1;

            if (current_max > max_good_people)
                max_good_people = current_max;
        }

        current_max = 0;
        for (int i = 0; i < size; i++)
        {
            if (people[0][i] == 0)
                current_max += 1;

            if (current_max > max_good_people)
                max_good_people = current_max;
        }

        return max_good_people;
    }
};

int main()
{
    vector<vector<int>> vec = {{2,1,2}, {1,2,2}, {2,0,2}};
    Solution sol;

    std::cout << sol.maximumGood(vec) << std::endl;
}