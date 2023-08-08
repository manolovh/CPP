#include "inc\MacrosCalculator.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

void calculate_macros(
    MacrosData& macro_data, PersonData const& person_data, int calorie_choice)
{
    int calorie_buffer = calorie_choice;
    
    /* 1. Set aside for each individual at least 2gr of protein/kg for optimized muscle recovery
       (and therefore growth).
       2. If more, limit calories from protein to max 35%, because if the person is overweight,
       more protein will be not be optimally utilized anyway. */
    if ((calorie_buffer - (person_data.weight * 2 * CALORIES_IN_PROTEIN)) < (calorie_buffer * 0.65))
    {
        macro_data.gr_protein = (calorie_buffer * 0.35) / CALORIES_IN_PROTEIN;
    }
    else
    {
        macro_data.gr_protein = person_data.weight * 2;
    }

    /* 1. Set aside for each individual at least 1gr of fat/kg for optimized hormone secretion
       and optimized essential vitamins absorbtion.
       2.  If more, limit calories from fat to max (height - 100). That's enough for, since
       overweight people can use stored and excessive fat for processes from p.1.
       3. Save more calories for carbohydrates, so they can be used as a direct
       energy source. This leads to a more energetic and less lethargic person. */ 
    if (person_data.weight > (person_data.height - 100))
    {
        macro_data.gr_fat = person_data.height - 100;
    }
    else
    {
        macro_data.gr_fat = person_data.weight;
    }

    // Subtract calories from protein and fat from the buffer
    calorie_buffer -= macro_data.gr_protein * CALORIES_IN_PROTEIN;
    calorie_buffer -= macro_data.gr_fat * CALORIES_IN_FAT;

    // Distribute the remaining calories for carbohydrates.
    macro_data.gr_carbs = calorie_buffer / CALORIES_IN_CARBS;
}

void print_macros(MacrosData const& macro_data)
{
    std::cout << std::setfill('-') << std::setw(FORMAT_SIZE + 4) << "";
    std::cout << "\nGrams of protein: " << std::setfill(' ') << std::setw(8) << static_cast<int>(macro_data.gr_protein) << std::endl;
    std::cout << "Grams of carbohydrate: " << std::setw(2) << static_cast<int>(macro_data.gr_carbs) << std::endl;
    std::cout << "Grams of fat: " << std::setw(11) << static_cast<int>(macro_data.gr_fat) << std::endl;
    std::cout << std::endl;
}
 
void create_meal_plan(MealPlan& meal_plan, const MacrosData& macro_data)
{
    // Get 90% of protein directly from protein sources and leave 10 % for secondary ones
    const int PROTEIN_PER_MEAL = (macro_data.gr_protein * 0.9) / NR_OF_MEALS;
    int total_calories = (macro_data.gr_protein + macro_data.gr_carbs) * 4 + macro_data.gr_fat * 9;

    // leave 15 % for satiating and rich in fiber foods - fruits and vegetables
    int fiber_calories = total_calories * 0.15;
    total_calories -= fiber_calories;

    MacrosData total_macros {0};
    MacrosData meals[4] = {0};

    ProteinSource proteins;
    CarbSource carbs;
    FatSource fats;

    std::vector<FoodItem> prot_meal_1_or_3 {
        proteins.egg, proteins.yoghurt,
        proteins.cott_cheese, proteins.whey_protein
    };
    std::vector<FoodItem> prot_meal_2_or_4 {
        proteins.chicken, proteins.beef95,
        proteins.white_fish, proteins.tofu
    };

    std::vector<FoodItem> fat_sources {
        fats.olive_oil, fats.walnuts, fats.avocado,
        fats.peanut_butter, fats.almond_butter
    };

    std::vector<FoodItem> carb_sources {
        carbs.bread, carbs.cream_of_rice, carbs.oatmeal,
        carbs.pasta, carbs.potato, carbs.rice
    };

    for (int i = 1; i <= NR_OF_MEALS; i++)
    {
        size_t meals_left = NR_OF_MEALS;
        int FAT_PER_MEAL = (macro_data.gr_fat - total_macros.gr_fat) / meals_left;
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

        double portion_size_100g = 0;
        int quantity = 0;
        std::string message;
        
        // Replace everything over 5 eggs (250g.) with ham
        if ((current_item.name == "Egg"))
        {
            int max_protein_from_eggs;
            if (macro_data.gr_fat < 70)
            {
                max_protein_from_eggs = 18;
            }
            else
            {
                max_protein_from_eggs = 30;
            }

            portion_size_100g = (max_protein_from_eggs / 6) * 50;

            int needed_protein = PROTEIN_PER_MEAL - max_protein_from_eggs;
            double portion_size_ham_100g = needed_protein / proteins.ham.gr_protein;

            int quantity_ham = 100 * portion_size_ham_100g;
            round_quantity(quantity_ham);

            message = std::to_string(quantity_ham) + "g. " + proteins.ham.name + " & 250g. Egg";
            switch (i)
            {
                case 1:
                    meal_plan.breakfast.protein = message; break;
                case 2:
                    meal_plan.lunch.protein = message; break;
                case 3:
                    meal_plan.afternoon_breakfast.protein = message; break;
                case 4:
                    meal_plan.dinner.protein = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, proteins.ham, portion_size_ham_100g, i-1);
        }
        else
        {
            portion_size_100g = PROTEIN_PER_MEAL / current_item.gr_protein;
            quantity = 100 * portion_size_100g;

            round_quantity(quantity);

            message = std::to_string(quantity) + "g. " + current_item.name;
            switch (i)
            {
                case 1:
                    meal_plan.breakfast.protein = message; break;
                case 2:
                    meal_plan.lunch.protein = message; break;
                case 3:
                    meal_plan.afternoon_breakfast.protein = message; break;
                case 4:
                    meal_plan.dinner.protein = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);
        }

        random = rand() % fat_sources.size();
        current_item = fat_sources[random];

        if (FAT_PER_MEAL > meals[i-1].gr_fat)
        {
            portion_size_100g = (FAT_PER_MEAL - meals[i-1].gr_fat) / current_item.gr_fat;
        }
        else
        {
            portion_size_100g = meals[i-1].gr_fat / current_item.gr_fat;
        }

        quantity = 100 * portion_size_100g;
        round_quantity(quantity);

        if (quantity == 0)
        {
            message = "No added fats for this meal.";
        }
        else
        {
            message = std::to_string(quantity) + "g. " + current_item.name;
        }

        switch (i)
        {
            case 1:
                meal_plan.breakfast.fats = message; break;
            case 2:
                meal_plan.lunch.fats = message; break;
            case 3:
                meal_plan.afternoon_breakfast.fats = message; break;
            case 4:
                meal_plan.dinner.fats = message; break;
        }

        save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);

        const int CARBS_PER_MEAL = macro_data.gr_carbs / NR_OF_MEALS;
        random = rand() % carb_sources.size();
        current_item = carb_sources[random];

        if (meals[i-1].gr_carbs < CARBS_PER_MEAL)
        {
            portion_size_100g = (CARBS_PER_MEAL - meals[i-1].gr_carbs) / current_item.gr_carb;
            quantity = 100 * portion_size_100g;

            round_quantity(quantity);

            message = std::to_string(quantity) + "g. " + current_item.name;
            switch (i)
            {
                case 1:
                    meal_plan.breakfast.carbs = message; break;
                case 2:
                    meal_plan.lunch.carbs = message; break;
                case 3:
                    meal_plan.afternoon_breakfast.carbs = message; break;
                case 4:
                    meal_plan.dinner.carbs = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);
        }
        else
        {
            message = "No added carbs for this meal";
            switch (i)
            {
                case 1:
                    meal_plan.breakfast.carbs = message; break;
                case 2:
                    meal_plan.lunch.carbs = message; break;
                case 3:
                    meal_plan.afternoon_breakfast.carbs = message; break;
                case 4:
                    meal_plan.dinner.carbs = message; break;
            }
        }
        meals_left--;
        test(total_macros, meals);
    }
}

void print_meal(Meal const& meal)
{
    std::cout << "\t# " << meal.protein << std::setw(30 - meal.protein.size()) << std::setfill(' ') << "#" << std::endl;
    std::cout << "\t# " << meal.carbs << std::setw(30 - meal.carbs.size()) << std::setfill(' ') << " #" << std::endl;
    std::cout << "\t# " << meal.fats << std::setw(30 - meal.fats.size()) << std::setfill(' ') << "#" << std::endl;
    std::cout << "\t# " << std::setw(30) << std::setfill('-') << "#" << std::endl;
    std::cout << std::setw(' ');
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
        {
            std::cout << "\n-----Example meals, created for your specific goal-----" << std::endl;
        }

        std::cout << "\n\t#----------Breakfast-----------#" << std::endl;
        print_meal(meal_plan.breakfast);

        std::cout << "\n\t#------------Lunch-------------#" << std::endl;
        print_meal(meal_plan.lunch);

        std::cout << "\n\t#-----Afternoon Breakfast------#" << std::endl;
        print_meal(meal_plan.afternoon_breakfast);

        std::cout << "\n\t#------------Dinner------------#" << std::endl;
        print_meal(meal_plan.dinner);

        std::cout << "\n\t#----Fruits and Vegetables-----#" << std::endl;

        if (meal_plans_created == 3)
        {
            std::cout << "\n-----You reached the maximum meals for today-----\n" << std::endl;
            break;
        }

        std::cout << "\nWant more similar meals? (Y/N): ";
        std::cin >> choice;
    }
}

void save_meal_data(
    MacrosData meals[4], MacrosData& total_macros, int& total_calories,
    FoodItem const& current_item, double portion_size_100g, int idx)
{
    meals[idx].gr_protein += current_item.gr_protein * portion_size_100g;
    meals[idx].gr_carbs += current_item.gr_carb * portion_size_100g;
    meals[idx].gr_fat += current_item.gr_fat * portion_size_100g;

    total_macros.gr_protein += current_item.gr_protein * portion_size_100g;
    total_macros.gr_fat += current_item.gr_fat * portion_size_100g;
    total_calories -= (meals[idx].gr_protein * CALORIES_IN_PROTEIN) + \
                        (current_item.gr_fat * portion_size_100g * CALORIES_IN_FAT);
}

void test(const MacrosData& total_macros, MacrosData meals[4])
{
    std::cout << "FATS: " << total_macros.gr_fat << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "P " << meals[i].gr_protein << std::endl;
        std::cout << "G " << meals[i].gr_carbs << std::endl;
        std::cout << "F " << meals[i].gr_fat << std::endl;
        std::cout << "--------------" << std::endl;
    }
}

void round_quantity(int& quantity)
{
    // Make all grams end in either 5 or 10 for more aesthetic look
    if (quantity % 5 < 3)
    {
        quantity -= quantity % 5;
    }
    else
    {
        quantity += 5 - quantity % 5;
    }
}
