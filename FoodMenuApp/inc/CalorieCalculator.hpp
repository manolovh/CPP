#ifndef _CALORIE_CALCULATOR_HPP
#define _CALORIE_CALCULATOR_HPP
#include <cctype>
#include <ostream>
#include "./MacrosCalculator.hpp"

const int CALORIES_1_KG_FAT = 8000;
const int WEEK = 7;
const double HALF_PERCENT = 0.005;
const double ONE_PERCENT = 0.01;

struct MacrosData;

struct CaloriesData
{
    int bmr_calories;
    int weight_maintain_calories;
    int weight_gain_calories;
    int weight_lose_half_kg_calories;
    int weight_lose_one_kg_calories;
};

struct PersonData
{
    char gender;
    int age;
    double height;
    double weight;
    int activity;
    int goal;
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