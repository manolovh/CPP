#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct IdxData
{
    int first_idx = 0;
    int last_idx = 0;
    size_t length = 0;

    IdxData()
    {
        first_idx = 0;
        last_idx = 0;
        length = 0;
    }
};

typedef struct IdxData IdxData;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        if (prizePositions.size() < 2 && k == 0)
            return prizePositions.size();
        else if (prizePositions.size() > 2 && k == 0)
            return 2;

        int max_positions = 0;

        IdxData *data = find_max(prizePositions, 1);
        max_positions += data->length;

        if (data->first_idx == 1)
        {
            prizePositions.erase(prizePositions.begin(), prizePositions.begin() + data->last_idx);
        }
        else if (data->last_idx + 1 == prizePositions.size() - 1)
        {
            prizePositions.erase(prizePositions.begin() + data->first_idx, prizePositions.end());
        }
        else
        {
            prizePositions.erase(prizePositions.begin() + data->first_idx, prizePositions.begin() + data->last_idx + 1);
        }

        delete data;

        data = find_max(prizePositions, 2);
        max_positions += data->length;

        delete data;

        return max_positions;
    }

    IdxData* find_max(vector<int>& prizePositions, int iter)
    {
        IdxData *data = new IdxData();

        for (int i = 0; i < prizePositions.size(); ++i)
        {
            auto it = std::find(prizePositions.begin() + i, prizePositions.end(), prizePositions[i] + 2);

            if (it != prizePositions.end())
            {
                int idx = std::distance(prizePositions.begin(), it);
                if ((idx + 1 - i) > data->length)
                {
                    data->first_idx = i;
                    data->last_idx = idx;
                    data->length = (data->last_idx + 1) - data->first_idx;

                    if (data->length == prizePositions.size())
                        break;
                }
            }
            else if (it == prizePositions.end() && iter == 2)
            {
                data->first_idx = i;
                data->last_idx = data->first_idx;
                data->length = 1;
            }
        }
        return data;
    }
};

int main()
{
    vector<int> vec {1, 1, 2, 2, 3, 3, 5};
    Solution sol;

    std::cout << sol.maximizeWin(vec, 2) << std::endl;
}