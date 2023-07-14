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

struct Meal
{
    std::string protein_source;
    std::string carb_source;
    std:string fat_source;
};

struct MealPlan
{
    Meal breakfast;
    Meal lunch;
    Meal afternoon_breakfast;
    Meal dinner;
};

void calculate_macros(MacrosData& macro_data, PersonData const& person_data, int calorie_choice);

void print_macros(MacrosData const& macro_data);

void print_meal_plan();

void create_meal_plan(MealPlan& meal_plan);

#endif //  _MACROS_CALCULATOR_HPP
