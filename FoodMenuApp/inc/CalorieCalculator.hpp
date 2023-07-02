#ifndef _CALORIE_CALCULATOR_HPP
#define _CALORIE_CALCULATOR_HPP
#include <cctype>
#include <ostream>

struct CaloriesData {
    int bmr_calories;
    int weight_maintain_calories;
    int weight_gain_calories;
    int weight_lose_calories;
};

CaloriesData calculate_calories(
        CaloriesData data, char gender, int age,
        double height, double weight, int activity
);

int determine_maintain_calories(const CaloriesData &data, const int &activity);

#endif // _CALORIE_CALCULATOR_HPP