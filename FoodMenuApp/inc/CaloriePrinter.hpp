#ifndef _CALORIE_PRINTER_HPP
#define _CALORIE_PRINTER_HPP

#include <vector>
#include "CalorieCalculator.hpp"

class CalorieCalculator;

const int CALORIES_IN_PROTEIN = 4;
const int CALORIES_IN_CARBS   = 4;
const int CALORIES_IN_FAT     = 9;
const int NR_OF_MEALS         = 4;

struct PersonData;
struct FoodItem;
struct MealPlan;

struct MacrosData
{
    double gr_protein = 0;
    double gr_fat = 0;
    double gr_carbs = 0;
    double water_intake = 0;
};

struct Meal
{
    std::string protein = "";
    std::string carbs = "";
    std::string fats = "";
};

struct FoodItem
{
    std::string name = "";
    int total_calories = 0;
    double gr_protein = 0;
    double gr_carb = 0;
    double gr_fat = 0;
};

struct ProteinSource
{
    FoodItem chicken      = {"Chicken", 135, 27, 0, 3};
    FoodItem beef95       = {"Beef 95%", 133, 22, 0, 5};
    FoodItem egg          = {"Egg", 155, 13, 1, 11};
    FoodItem yoghurt      = {"Greek Yoghurt", 65, 10, 4, 1};
    FoodItem white_fish   = {"White Fish", 172, 24, 0, 8};
    FoodItem tofu         = {"Tofu", 84, 10, 1, 5};
    FoodItem whey_protein = {"Whey Protein", 379, 73, 6, 7};
    FoodItem cott_cheese  = {"Cottage Cheese", 100, 11, 4, 4};
    FoodItem ham          = {"Ham", 145, 21, 2, 6};
};

struct CarbSource
{
    FoodItem rice          = {"Rice", 365, 7, 80, 1};
    FoodItem bread         = {"Bread", 259, 9, 49, 3};
    FoodItem potato        = {"Potato", 77, 2, 17, 0};
    FoodItem oatmeal       = {"Oatmeal", 362, 11, 66, 6};
    FoodItem pasta         = {"Pasta", 311, 11, 63, 1};
    FoodItem cream_of_rice = {"Cream of Rice", 370, 6, 83, 1};
};

struct FatSource
{
    FoodItem olive_oil     = {"Olive Oil", 884, 0, 0, 99};
    FoodItem walnuts       = {"Walnuts", 654, 15, 14, 65};
    FoodItem avocado       = {"Avocado", 175, 2, 8, 15};
    FoodItem peanut_butter = {"Peanut Butter", 588, 25, 20, 50};
    FoodItem almond_butter = {"Almond Butter", 614, 21, 19, 56};
};

struct Fruit
{
    std::string descr_fruit_20_kcal = "[Fruits (20kcal/100g)]";
    std::vector<std::string> fruits_20_kcal = {
        "Strawberries",
        "Blueberries",
        "Watermelon",
        "Cantaloupe",
        "Peach"
    };

    std::string descr_fruit_50_kcal = "[Fruits (50kcal/100g)]";
    std::vector<std::string> fruits_50_kcal = {
        "Pineapple",
        "Apple",
        "Orange",
        "Nectarine",
        "Pear"
    };
};

struct Vegetable
{
    std::string descr_veg_20_kcal = "[Vegetables (20kcal/100g)]";
    std::vector<std::string> vegetables_20_kcal = {
        "Tomato",
        "Cucumber",
        "Asparagus",
        "Green Pepper",
        "Lettuce",
        "Zucchini"
    };

    std::string descr_veg_50_kcal = "[Vegetables (50kcal/100g)]";
    std::vector<std::string> vegetables_50_kcal = {
        "Beetroot",
        "Carrot",
        "Kale",
        "Onion",
        "Green Beans"
    };
};

struct MealPlan
{
    Meal breakfast           = {};
    Meal lunch               = {};
    Meal afternoon_breakfast = {};
    Meal dinner              = {};
    int calories_from_fiber  = 0;
};

class CaloriePrinter
{
public:
    CaloriePrinter() = default;

    void print_macros(CalorieCalculator& calc);

    void print_meal(Meal const& meal);

    void print_meal_plan(CalorieCalculator& calc);

    void display_info(CalorieCalculator& calc);
};

void round_quantity(int& quantity, int selection);

void print_separator();

void print_fiber_source(std::vector<std::string>& sources, std::string description);

#endif //  _MACROS_CALCULATOR_HPP
