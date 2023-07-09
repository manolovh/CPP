#ifndef _MACROS_CALCULATOR_HPP
#define _MACROS_CALCULATOR_HPP

#include "CalorieCalculator.hpp"

const int CALORIES_IN_PROTEIN = 4;
const int CALORIES_IN_CARBS = 4;
const int CALORIES_IN_FAT = 9;

struct PersonData;

struct MacrosData
{
    int gr_protein;
    int gr_fat;
    int gr_carbs;
    double water_intake;
};

void calculate_macros(MacrosData& macro_data, PersonData const& person_data, int calorie_choice);

void print_macros(MacrosData const& macro_data);

#endif //  _MACROS_CALCULATOR_HPP