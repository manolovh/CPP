#include "inc/MacrosCalculator.hpp"
#include <iostream>


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

void print_macros(MacrosData const& macro_data) {
    std::cout << "\nGrams of protein: " << macro_data.gr_protein << std::endl;
    std::cout << "Grams of carbohydrate: " << macro_data.gr_carbs << std::endl;
    std::cout << "Grams of fat: " << macro_data.gr_fat << std::endl;
}