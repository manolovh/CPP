#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int current_idx = 0;
        vector<int> indices {};
        size_t word_length = words[0].size();

        auto iter = s.begin();
        vector<string> words_copy(words);
        int temp_idx = 0;

        while (iter != s.end())
        {
            string curr_str = "";
            bool substr_in_vect = false;

            for (size_t j = 0; j < word_length; j++)
            {
                if (iter != s.end())
                {
                    curr_str += (*iter);
                    iter++;
                    temp_idx++;
                }
                auto vect_iter = words_copy.begin();

                while (vect_iter != words_copy.end())
                {
                    size_t found = (*vect_iter).find(curr_str);
                    substr_in_vect = found != string::npos;
                    
                    if (substr_in_vect)
                        break;

                    vect_iter++;
                }
            }

            if (find(words_copy.begin(), words_copy.end(), curr_str) != words_copy.end())
            {
                words_copy.erase(
                    std::find(words_copy.begin(), words_copy.end(), curr_str)
                );
            }
            else if ((find(words_copy.begin(), words_copy.end(), curr_str) == words_copy.end()) && !words_copy.empty())
            {
                words_copy = words;
                for (size_t i = 0; i < curr_str.size(); i++)
                    iter--;
            }
            else if (words_copy.empty())
            {
                indices.push_back(current_idx);
                current_idx = temp_idx;
                words_copy = words;
            }
            curr_str = "";
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
    for (auto elem: vec1)
        cout << elem << ",";
    cout << "]";
}