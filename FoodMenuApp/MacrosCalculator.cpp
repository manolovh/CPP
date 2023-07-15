#include "inc/MacrosCalculator.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>


void calculate_macros(
    MacrosData& macro_data, PersonData const& person_data, int calorie_choice)
{
    int calorie_buffer = calorie_choice;
    
    /* 1. Set aside for each individual at least 2gr of protein/kg for optimized muscle recovery
       (and therefore growth).
       2. If more, limit calories from protein to max 35%, because if the person is overweight,
       more protein will be not be optimally utilized anyway. */
    if ((calorie_buffer - (person_data.weight * 2 * CALORIES_IN_PROTEIN)) < (calorie_buffer * 0.65))
        macro_data.gr_protein = (calorie_buffer * 0.35) / CALORIES_IN_PROTEIN;
    else
        macro_data.gr_protein = person_data.weight * 2;

    /* 1. Set aside for each individual at least 1gr of fat/kg for optimized hormone secretion
       and optimized essential vitamins absorbtion.
       2.  If more, limit calories from fat to max (height - 100). That's enough for, since
       overweight people can use stored and excessive fat for processes from p.1.
       3. Save more calories for carbohydrates, so they can be used as a direct
       energy source. This leads to a more energetic and less lethargic person. */ 
    if (person_data.weight > (person_data.height - 100))
        macro_data.gr_fat = person_data.height - 100;
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

void create_meal(MealPlan& meal_plan, const MacrosData& macro_data)
{

}
 
void create_meal_plan(MealPlan& meal_plan, const MacrosData& macro_data)
{
    const int PROTEIN_PER_MEAL = (macro_data.gr_protein * 0.9) / NR_OF_MEALS;
    int total_calories = (macro_data.gr_protein + macro_data.gr_carbs) * 4 + macro_data.gr_fat * 9;
    MacrosData total_macros;

    ProteinSource proteins;
    CarbSource carbs;
    FatSource fats;

    std::vector<FoodItem> prot_meal_1_or_3 {
        proteins.egg_l, proteins.yoghurt,
        proteins.cott_cheese, proteins.whey_protein
    };
    std::vector<FoodItem> prot_meal_2_or_4 {
        proteins.chicken, proteins.beef95,
        proteins.white_fish, proteins.beans
    };

    for (int i = 1; i <= NR_OF_MEALS; i++)
    {
        int random;
        FoodItem current_item;
        if (i % 2 == 1)
        {
            random = rand() % prot_meal_1_or_3.size();
            current_item = prot_meal_1_or_3[random];
            prot_meal_1_or_3.erase(prot_meal_1_or_3.begin() + random);
        }
        else
        {
            random = rand() % prot_meal_2_or_4.size();
            current_item = prot_meal_2_or_4[random];
            prot_meal_2_or_4.erase(prot_meal_2_or_4.begin() + random);
        }

        switch (i)
        {
            case 1:
            {
                int breakfast_protein = 100 * (PROTEIN_PER_MEAL / current_item.gr_protein);
                meal_plan.breakfast.protein = std::to_string(breakfast_protein) + "g. " + current_item.name;

                total_macros.gr_protein = breakfast_protein;
                total_calories -= PROTEIN_PER_MEAL * CALORIES_IN_PROTEIN;
            }
            break;

            case 2:
            {
                int lunch_protein = 100 * (PROTEIN_PER_MEAL / current_item.gr_protein);
                meal_plan.lunch.protein = std::to_string(lunch_protein) + "g. " + current_item.name;

                total_macros.gr_protein += lunch_protein;
                total_calories -= PROTEIN_PER_MEAL * CALORIES_IN_PROTEIN;
            }
            break;

            case 3:
            {
                int afternoon_breakfast_protein = 100 * (PROTEIN_PER_MEAL / current_item.gr_protein);
                meal_plan.afternoon_breakfast.protein = std::to_string(afternoon_breakfast_protein) + "g. " + current_item.name;

                total_macros.gr_protein += afternoon_breakfast_protein;
                total_calories -= PROTEIN_PER_MEAL * CALORIES_IN_PROTEIN;
            }
            break;

            case 4:
            {
                int dinner_protein = 100 * (PROTEIN_PER_MEAL / current_item.gr_protein);
                meal_plan.dinner.protein = std::to_string(dinner_protein) + "g. " + current_item.name;

                total_macros.gr_protein += dinner_protein;
                total_calories -= PROTEIN_PER_MEAL * CALORIES_IN_PROTEIN;
            }
            break;
        }
    }
}

void print_meal(Meal const& meal)
{
    std::cout << meal.protein << std::endl;
    std::cout << meal.carbs << std::endl;
    std::cout << meal.fats << std::endl;
}

void print_meal_plan(const MacrosData& macro_data)
{
    char choice = 'Y';
    int meal_plans_created = 0;

    while (toupper(choice) == 'Y')
    {
        meal_plans_created++;
        MealPlan meal_plan;
        create_meal_plan(meal_plan, macro_data);

        if (meal_plans_created == 1)
            std::cout << "\n\tExample meals, created for your specific goal: " << std::endl;

        std::cout << "\nBreakfast: " << std::endl;
        print_meal(meal_plan.breakfast);

        std::cout << "Lunch: " << std::endl;
        print_meal(meal_plan.lunch);

        std::cout << "Afternoon Breakfast: " << std::endl;
        print_meal(meal_plan.afternoon_breakfast);

        std::cout << "Dinner: " << std::endl;
        print_meal(meal_plan.dinner);

        if (meal_plans_created == 3)
        {
            std::cout << "\n-----You reached the maximum meals for today-----\n" << std::endl;
            break;
        }

        std::cout << "\nWant more similar meals? (Y/N): ";
        std::cin >> choice;
    }
}