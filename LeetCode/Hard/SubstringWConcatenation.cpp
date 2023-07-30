#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> indices {};
        size_t word_length = words[0].size();

        size_t total_length = word_length * words.size();
        vector<string> words_copy = words;

        for (size_t i = 0; i < s.size(); i++)
        {
            int temp_len = 0;
            string substring = s.substr(i, total_length);

            if (substring.size() < total_length)
                break;

            while (true)
            {
                auto iter = find(words_copy.begin(), words_copy.end(), substring.substr(temp_len, word_length));
                if (iter != words_copy.end())
                {
                    words_copy.erase(find(words_copy.begin(), words_copy.end(), substring.substr(temp_len, word_length)));
                    temp_len += word_length;
                }
                else
                {
                    words_copy = words;
                    break;
                }
                if (words_copy.empty())
                {
                    indices.push_back(i);
                    words_copy = words;
                    break;
                }
            }
        }
        return indices;
    }
};

int main()
{
    Solution obj;
    vector<string> vec {"bar","foo","the"};

    vector<int> vec1 = obj.findSubstring("barfoofoobarthefoobarman", vec);
    
    cout << "[";
    for (size_t i = 0; i < vec1.size(); i++)
    {
        if (i == (vec1.size() - 1))
            cout << vec1[i];
        else
            cout << vec1[i] << ",";
    }
    cout << "]";
}