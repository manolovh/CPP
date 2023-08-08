#ifndef _CALORIE_CALCULATOR_HPP
#define _CALORIE_CALCULATOR_HPP
#include <cctype>
#include <ostream>
#include "MacrosCalculator.hpp"

const int CALORIES_1_KG_FAT = 7700;
const int WEEK = 7;
const double QUARTER_KG = 0.25;
const double HALF_KG = 0.5;
const int FORMAT_SIZE = 36;

struct MacrosData;

struct CaloriesData
{
    int bmr_calories;
    int weight_maintain_calories;
    int weight_gain_calories;
    int weight_lose_quarter_kg_calories;
    int weight_lose_half_kg_calories;
};

struct PersonData
{
    char gender;
    int age;
    double height;
    double weight;
    int activity;
    int goal;
    bool wants_macros;
};

void calculate_calories(
    CaloriesData& data, char gender, int age,
    double height, double weight, int activity
);

int determine_maintain_calories(CaloriesData const& data, int activity);

void collect_data(PersonData &data);

void display_info(
    CaloriesData const& data, MacrosData& macro_data,
    PersonData const& person_data, int weight_goal
);

void print_separator();

#endif // _CALORIE_CALCULATOR_HPP
