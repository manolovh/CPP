#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::string;

class Solution {
public:
    void fun(
        string& digits, vector<string>& ans,
        unordered_map<int, vector<char>>& mapping,
        int ind, string temp
    )
    {
        if (ind >= digits.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < mapping[digits[ind] - '0'].size(); i++)
        {
            temp.push_back(mapping[digits[ind] - '0'][i]);
            fun(digits, ans, mapping, ind + 1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mapping;
        mapping[2] = { 'a','b','c' };
        mapping[3] = { 'd','e','f' };
        mapping[4] = { 'g','h','i' };
        mapping[5] = { 'j','k','l' };
        mapping[6] = { 'm','n','o' };
        mapping[7] = { 'p','q','r','s' };
        mapping[8] = { 't','u','v' };
        mapping[9] = { 'w','x','y','z' };
        vector<string> ans;
        if (digits.size() == 0)
        {
            return ans;
        }
        fun(digits, ans, mapping, 0, "");
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> vec = sol.letterCombinations("23");

    for (auto elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}