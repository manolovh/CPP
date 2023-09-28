#include <iostream>

using std::string;

enum Direction { North, East, South, West };

class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int positions[2] = { 0, 0 };
        Direction direction = West;
        for (int z = 0; z < 4; z++)
        {
            for (int i = 0; i < instructions.length(); i++)
            {
                if (instructions[i] == 'G')
                {
                    switch (direction)
                    {
                    case North:
                        positions[1] += 1; break;
                    case South:
                        positions[1] -= 1; break;
                    case East:
                        positions[0] += 1; break;
                    case West:
                        positions[0] -= 1; break;
                    }
                }
                else if (instructions[i] == 'L')
                {
                    if (direction == North) {
                        direction = West;
                    }
                    else if (direction == West) {
                        direction = South;
                    }
                    else if (direction == South) {
                        direction = East;
                    }
                    else if (direction == East) {
                        direction = North;
                    }
                }
                else
                {
                    if (direction == North) {
                        direction = East;
                    }
                    else if (direction == East) {
                        direction = South;
                    }
                    else if (direction == South) {
                        direction = West;
                    }
                    else if (direction == West) {
                        direction = North;
                    }
                }
            }
        }
        std::cout << positions[0] << "," << positions[1] << std::endl;

        if (positions[0] == 0 && positions[1] == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main()
{
    Solution sol;

    std::cout << sol.isRobotBounded("GGLLGG") << std::endl;
}
