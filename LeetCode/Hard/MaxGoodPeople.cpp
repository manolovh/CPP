#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements)
    {
        size_t size = statements[0].size();
        int max_good_people_1;
        int max_good_people_2;
        int total_good_people;

        int max_good_people;
        // vector<int> all_scores;

        for (int i = 0; i < size; i++)
        {
            // Person `i` is a good person and tells the truth
            max_good_people_1 = size;
            for (int j = 0; j < size; j++)
            {
                if (statements[i][j] == 0)
                {
                    max_good_people_1--;
                    int k = 0;
                    while (k < size)
                    {
                        if (statements[j][k] == 1)
                        {
                            max_good_people_1--;
                        }
                        k++;
                    }
                }
                else if (statements[i][j] == 2)
                {
                    int k = 0;
                    while (k < size)
                    {
                        if (statements[k][j] == 0)
                        {
                            max_good_people_1--;
                            break;
                        }
                        k++;
                    }
                }
            }

            // Person `i` is a bad person and lies
            max_good_people_2 = size - 1;
            for (int j = 0; j < size; j++)
            {
                if (statements[i][j] == 1)
                {
                    max_good_people_2--;
                }
            }

            total_good_people = (max_good_people_1 > max_good_people_2) ? max_good_people_1 : max_good_people_2;
            if (total_good_people < max_good_people)
                max_good_people = total_good_people;
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