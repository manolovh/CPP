#ifndef _CALORIE_CALCULATOR_HPP
#define _CALORIE_CALCULATOR_HPP
#include <cctype>
#include <memory>
#include <ostream>
#include "CaloriePrinter.hpp"

const int CALORIES_1_KG_FAT = 7700;
const int WEEK              = 7;
const double QUARTER_KG     = 0.25;
const double HALF_KG        = 0.5;
const int FORMAT_SIZE       = 36;

struct MacrosData;
struct FoodItem;
struct MealPlan;

class CaloriePrinter;

struct CaloriesData
{
    int bmr_calories = 0;
    int weight_maintain_calories = 0;
    int weight_gain_calories = 0;
    int weight_lose_quarter_kg_calories = 0;
    int weight_lose_half_kg_calories = 0;
};

struct PersonData
{
    char gender   = {};
    int age       = 0;
    double height = 0;
    double weight = 0;
    int activity  = 0;
    int goal      = 0;
    bool wants_macros = false;
};

class CalorieCalculator
{
public:
    CaloriesData *m_cal_data;
    MacrosData   *m_macro_data;
    PersonData   *m_person_data;
    MealPlan     *m_meal_plan;
    int m_meal_plans_created;

    CalorieCalculator();

    void collect_data();

    void calculate_calories();

    int determine_maintain_calories();

    void calculate_macros(int calorie_choice);

    void save_meal_data(
    MacrosData meals[4], MacrosData& total_macros, int& total_calories,
    FoodItem const& current_item, double portion_size_100g, int idx);

    void create_meal_plan();

    // Debugging function
    void test(MacrosData meals[4]) const;
};

void print_separator();

#endif // _CALORIE_CALCULATOR_HPP
