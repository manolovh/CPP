#include <iomanip>
#include <iostream>
#include "./inc/CalorieCalculator.hpp"
#include "./inc/MacrosCalculator.hpp"

void collect_data(PersonData &data)
{
    std::cout << "\nEnter your gender (M/F): ";
    std::cin >> data.gender;
    print_separator();

    std::cout << "Enter your age: ";
    std::cin >> data.age;
    print_separator();

    std::cout << "Enter your height (in centimenters): ";
    std::cin >> data.height;
    print_separator();

    std::cout << "Enter your weight (in kilograms): ";
    std::cin >> data.weight;
    print_separator();

    std::cout << "(1) Sedentary (little to no exercise)\n" \
                 "(2) Lightly active (Light exercise: 1-3 days/week)\n" \
                 "(3) Moderately active (Moderate exercise: 3-5 days/week)\n" \
                 "(4) Very active (Hard exercise 6-7 days/week)\n\n" \
                 "    Choose your activity level: ";
    std::cin >> data.activity;
    print_separator();

    std::cout << "(1) Maintain Body weight\n" \
                 "(2) Lose 0.5 kg/week\n" \
                 "(3) Lose 1 kg/week\n" \
                 "(4) Gain Muscle \n\n" \
                 "    Choose your current goal: ";
    std::cin >> data.goal;
    print_separator();

    char macros_choice;
    std::cout << "Want a macronutrient plan for your goal? (Y/N): ";
    std::cin >> macros_choice;
    
    if (toupper(macros_choice) == 'Y')
        data.wants_macros = true;
}

void print_separator()
{
    std::cout << "\n------------------------------------------------\n\n";
}

void calculate_calories(
    CaloriesData& data, char gender,
    int age, double height,
    double weight, int activity)
{
    if (toupper(gender) == 'M')
    {
        data.bmr_calories = (10 * weight) + (6.25 * height) - (5 * age) + 5;
        data.weight_maintain_calories = determine_maintain_calories(data, activity);
        data.weight_gain_calories = data.weight_maintain_calories + 300;
        data.weight_lose_half_kg_calories = \
            data.weight_maintain_calories - (CALORIES_1_KG_FAT * (weight * HALF_PERCENT) / WEEK);
        data.weight_lose_one_kg_calories = \
            data.weight_maintain_calories - (CALORIES_1_KG_FAT * (weight * ONE_PERCENT) / WEEK);
    }
    else if (toupper(gender) == 'F')
    {
        data.bmr_calories = (10 * weight) + (6.25 * height) - (5 * age) - 161;
        data.weight_maintain_calories = determine_maintain_calories(data, activity);
        data.weight_gain_calories = data.weight_maintain_calories + 250;
        data.weight_lose_half_kg_calories = \
            data.weight_maintain_calories - (CALORIES_1_KG_FAT * (weight * HALF_PERCENT) / WEEK);
        data.weight_lose_one_kg_calories = \
            data.weight_maintain_calories - (CALORIES_1_KG_FAT * (weight * ONE_PERCENT) / WEEK);
    }
}

int determine_maintain_calories(const CaloriesData &data, int activity)
{
    /* Calculate the total calories required for maintaining body weight.
       More activity - more calories. */
    switch (activity)
    {
        case 1: return (data.bmr_calories * 1.2);
        case 2: return (data.bmr_calories * 1.375);
        case 3: return (data.bmr_calories * 1.55);
        case 4: return (data.bmr_calories * 1.725);
    }
    return 0;
}

void display_info(
    CaloriesData const& data, MacrosData& macro_data,
    PersonData const& person_data, int weight_goal)
{
    std::cout << "\nBase Metabolic Rate (BMR): "
              << std::setw(FORMAT_SIZE - 27) << data.bmr_calories << "kcal" << std::endl;

    std::string message_choice;
    int data_choice;
    switch (weight_goal)
    {
        case 1:
        message_choice = "Maintain Body weight: ";
        data_choice = data.weight_maintain_calories; break;

        case 2:
        message_choice = "Lose Body weight (0,5 kg/week): ";
        data_choice = data.weight_lose_half_kg_calories; break;

        case 3:
        message_choice = "Lose Body weight (1 kg/week): ";
        data_choice = data.weight_lose_one_kg_calories; break;

        case 4:
        message_choice = "Gain Muscle: ";
        data_choice = data.weight_gain_calories; break;

        default:
        message_choice = "You did not choose a correct option. Here are calories for maintaing your body weight: ";
        data_choice = data.weight_maintain_calories; break;
    }
    std::cout << message_choice << std::setw(FORMAT_SIZE - message_choice.size()) << data_choice << "kcal" << std::endl;
    if (person_data.wants_macros)
        calculate_macros(macro_data, person_data, data_choice);
}
