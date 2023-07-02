#include "../inc/CalorieCalculator.hpp"

CaloriesData Calculator::(CaloriesData data, char gender, int age, double height,
                       double weight, int activity)
{
    if (toupper(gender) == 'M') {
        data.bmr_calories = (10 * weight) + (6.25 * height) - (5 * age) + 5;
        data.weight_maintain_calories = Calculator::determine_maintain_calories(data, activity);
        data.weight_gain_calories = data.weight_maintain_calories + 300;
        data.weight_lose_calories = data.weight_gain_calories - 300;
    }
    else if (toupper(gender) == 'F') {
        data.bmr_calories = (10 * weight) + (6.25 * height) - (5 * age) - 161;
        data.weight_maintain_calories = Calculator::determine_maintain_calories(data, activity);
        data.weight_gain_calories = data.weight_maintain_calories + 250;
        data.weight_lose_calories = data.weight_gain_calories - 250;
    }
    return data;
}

int Calculator::determine_maintain_calories(const CaloriesData &data, const int &activity) {
    /* Calculate the total calories required for maintaining body weight.
       More activity - more calories. */
    switch (activity) {
        case 1: return data.bmr_calories * 1.2;
        case 2: return data.bmr_calories * 1.375;
        case 3: return data.bmr_calories * 1.55;
        case 4: return data.bmr_calories * 1.725;
        case 5: return data.bmr_calories * 1.9;
    }
}