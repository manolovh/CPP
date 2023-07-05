#include <iostream>
#include <iomanip>
#include <string>
#include "inc/CalorieCalculator.hpp"
#include "inc/MacrosCalculator.hpp"
#include "inc/PersonData.hpp"

int main()
{
    CaloriesData data;
    InputData person_data;

    collect_data(person_data);
    
    data = calculate_calories(data, person_data.gender, person_data.age,
                person_data.height, person_data.weight, person_data.activity);
                
    std::cout << "\n\tBase Metabolic Rate (BMR) Calories: "
              << std::setw(12) << data.bmr_calories << "kcal" << std::endl;
    std::cout << "\tCalories to Maintain bodyweight: "
              << std::setw(15) << data.weight_maintain_calories << "kcal" << std::endl;
    std::cout << "\tCalories to Lose bodyweight (0,5 kg/week): "
              << std::setw(5) << data.weight_lose_half_kg_calories << "kcal" << std::endl;
    std::cout << "\tCalories to Lose bodyweight (1 kg/week): "
              << std::setw(7) << data.weight_lose_one_kg_calories << "kcal" << std::endl;
    std::cout << "\tCalories to Slightly Gain Bodyweight: "
              << std::setw(10) << data.weight_gain_calories << "kcal\n" << std::endl;
    return 0;
}
