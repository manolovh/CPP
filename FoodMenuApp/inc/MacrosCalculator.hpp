#ifndef _MACROS_CALCULATOR_HPP
#define _MACROS_CALCULATOR_HPP

#include <memory>
#include "CalorieCalculator.hpp"

const int CALORIES_IN_PROTEIN = 4;
const int CALORIES_IN_CARBS   = 4;
const int CALORIES_IN_FAT     = 9;
const int NR_OF_MEALS         = 4;

struct PersonData;

struct MacrosData
{
    double gr_protein;
    double gr_fat;
    double gr_carbs;
    double water_intake;
};

struct Meal
{
    std::string protein;
    std::string carbs;
    std::string fats;
};

struct FoodItem
{
    std::string name;
    int total_calories;
    double gr_protein;
    double gr_carb;
    double gr_fat;
};

struct ProteinSource
{
    FoodItem chicken      {"Chicken", 135, 27, 0, 3};
    FoodItem beef95       {"Beef 95%", 133, 22, 0, 5};
    FoodItem egg          {"Egg", 155, 13, 1, 11};
    FoodItem yoghurt      {"Greek Yoghurt", 65, 10, 4, 1};
    FoodItem white_fish   {"White Fish", 172, 24, 0, 8};
    FoodItem beans        {"Beans", 345, 21, 63, 1};
    FoodItem whey_protein {"Whey Protein", 379, 73, 6, 7};
    FoodItem cott_cheese  {"Cottage Cheese", 100, 11, 4, 4};
    FoodItem ham          {"Ham", 145, 21, 2, 6};
};

struct CarbSource
{
    FoodItem rice          {"Rice", 365, 7, 80, 1};
    FoodItem bread         {"Bread", 259, 9, 49, 3};
    FoodItem potato        {"Potato", 77, 2, 17, 0};
    FoodItem oatmeal       {"Oatmeal", 362, 11, 66, 6};
    FoodItem pasta         {"Pasta", 311, 11, 63, 1};
    FoodItem cream_of_rice {"Cream of Rice", 370, 6, 83, 1};
};

struct FatSource
{
    FoodItem olive_oil     {"Olive Oil", 884, 0, 0, 99};
    FoodItem walnuts       {"Walnuts", 654, 15, 14, 65};
    FoodItem avocado       {"Avocado", 175, 2, 8, 15};
    FoodItem peanut_butter {"Peanut Butter", 588, 25, 20, 50};
    FoodItem almond_butter {"Almond Butter", 614, 21, 19, 56};
};

struct Fruit
{
    std::string fifty_kcal   = "Pineapple, Apple, Orange, Nectarine or Pear";
    std::string thirthy_kcal = "Strawberries, Blueberries, Watermelon, Cantaloupe or Peach";
};

struct Vegetable
{
    std::string twenty_kcal = "Tomato, Cucumber, Asparagus, Green Pepper, Lettuce or Zucchini";
    std::string fifty_kcal  = "Beetroot, Carrot, Kale, Onion or Green Beans";
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

void print_meal(Meal const& meal);

void create_meal_plan(MealPlan& meal_plan, const MacrosData& macro_data);

void print_meal_plan(const MacrosData& macro_data);

void save_meal_data(
    MacrosData meals[4], MacrosData& total_macros, int& total_calories,
    FoodItem const& current_item, double portion_size_100g, int idx);

void test(const MacrosData& total_macros, MacrosData meals[4]);

#endif //  _MACROS_CALCULATOR_HPP
