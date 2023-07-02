#include <iostream>
#include <string>
#include "./inc/CalorieCalculator.hpp"
#include "./inc/MacrosCalculator.hpp"
#include "./inc/PersonData.hpp"

int main()
{
    Calculator::CaloriesData data;
    data = Calculator::calculate_calories(data, 'M', 20, 180.0, 84.5, 3);
    std::cout << "BMR: " << data.bmr_calories << std::endl;
    std::cout << "Maintain: " << data.weight_maintain_calories << std::endl;
    std::cout << "Lose: " << data.weight_lose_calories << std::endl;
    std::cout << "Gain: " << data.weight_gain_calories << std::endl;
    return 0;

    // Fix build issue
}