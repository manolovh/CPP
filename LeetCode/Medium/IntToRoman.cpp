#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string returned_str;
        
        while (num != 0)
        {
            if (num >= 1000)
            {
                returned_str += "M";
                num -= 1000;
            }
            else if (num >= 500)
            {
                if (num >= 900)
                {
                    returned_str += "CM";
                    num -= 900;
                }
                else
                {
                    returned_str += "D";
                    num -= 500;
                }
            }
            else if (num >= 100)
            {
                if (num >= 400)
                {
                    returned_str += "CD";
                    num -= 400;
                }
                else
                {
                    returned_str += "C";
                    num -= 100;
                }
            }
            else if (num >= 50)
            {
                if (num >= 90)
                {
                    returned_str += "XC";
                    num -= 90;
                }
                else
                {
                    returned_str += "L";
                    num -= 50;
                }
            }
            else if (num >= 10)
            {
                if (num >= 40)
                {
                    returned_str += "XL";
                    num -= 40;
                }
                else
                {
                    returned_str += "X";
                    num -= 10;
                }
            }
            else if (num >= 5)
            {
                if (num >= 9)
                {
                    returned_str += "IX";
                    num -= 9;
                }
                else
                {
                    returned_str += "V";
                    num -= 5;
                }
            }
            else
            {
                if (num == 4)
                {
                    returned_str += "IV";
                    num -= 4;
                }
                else
                {
                    returned_str += "I";
                    num -= 1;
                }
            }
        }
        return returned_str;
    }
};
