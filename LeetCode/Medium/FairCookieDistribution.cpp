#include <iostream>
#include <vector>

using std::vector;

class Solution
{
public:
    int distributeCookies(vector<int>& cookies, int k)
    {
        int total_cookies = 0;
        for (auto count : cookies) {
            total_cookies += count;
        }

        int cookies_left = total_cookies % k;

        return total_cookies / k + cookies_left;
    }
};


int main()
{
    Solution sol;
    vector<int> cookies {6, 1, 3, 2, 2, 4, 1, 2};
    int k = 3;

    int distribution = sol.distributeCookies(cookies, k);
    std::cout << distribution << std::endl;
}