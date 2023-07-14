#include "inc/MacrosCalculator.hpp"
#include <iostream>
#include <iomanip>


void calculate_macros(
    MacrosData& macro_data, PersonData const& person_data, int calorie_choice)
{
    int calorie_buffer = calorie_choice;
    
    /*Set aside for each individual at least 2gr of protein/kg for optimized muscle recovery
      (and therefore growth). If more, limit calories from protein to max 35%, because
      if the person is overweight, more protein will be not be optimally utilized.*/
    if ((calorie_buffer - (person_data.weight * 2 * CALORIES_IN_PROTEIN)) < (calorie_buffer * 0.65))
        macro_data.gr_protein = (calorie_buffer * 0.35) / CALORIES_IN_PROTEIN;
    else
        macro_data.gr_protein = person_data.weight * 2;

    /*Set aside for each individual at least 1gr of fat/kg for optimized hormone secretion
      and optimized essential vitamins absorbtion. If more, limit calories from fat to max 35%,
      because if the person is overweight, these spare calories can be used for carbohydrates,
      which are used as a direct energy source -> more energetic / less lethargic person.*/ 
    if ((calorie_buffer - (person_data.weight * CALORIES_IN_FAT)) < (calorie_buffer * 0.65))

        macro_data.gr_fat = (calorie_buffer * 0.35) / CALORIES_IN_FAT;
    else
        macro_data.gr_fat = person_data.weight;

    // Subtract calories from protein and fat from the buffer
    calorie_buffer -= macro_data.gr_protein * CALORIES_IN_PROTEIN;
    calorie_buffer -= macro_data.gr_fat * CALORIES_IN_FAT;

    // Distribute the remaining calories for carbohydrates.
    macro_data.gr_carbs = calorie_buffer / CALORIES_IN_CARBS;
}

void print_macros(MacrosData const& macro_data)
{
    std::cout << std::setfill('-') << std::setw(FORMAT_SIZE + 4) << "";
    std::cout << "\nGrams of protein: " << std::setfill(' ') << std::setw(8) << macro_data.gr_protein << std::endl;
    std::cout << "Grams of carbohydrate: " << std::setw(2) << macro_data.gr_carbs << std::endl;
    std::cout << "Grams of fat: " << std::setw(11) << macro_data.gr_fat << std::endl;
    std::cout << std::endl;
}

void create_meal_plan(MealPlan& meal_plan, const MacrosData& macro_data)
{

}

void print_meal_plan(const MacrosData& macro_data)
{
    char choice;
    std::cout << "Do you need an example meal plan, based on your personal macronutrients? (Y/N): ";
    std::cin >> choice;

    while (toupper(choice) == 'Y')
    {
        MealPlan meal_plan;
        create_meal_plan(meal_plan, macro_data);

        std::cout << "Here are the meals, specific for your goal. Do you need another for the following day? (Y/N): ";
        std::cin >> choice;
    }
}