#include <iomanip>
#include <iostream>
#include <vector>
#include "../inc/CalorieCalculator.hpp"
#include "../inc/CaloriePrinter.hpp"

CalorieCalculator::CalorieCalculator()
{
    m_cal_data    = new CaloriesData{};
    m_macro_data  = new MacrosData{};
    m_person_data = new PersonData{};
    m_meal_plan   = new MealPlan{};
    m_meal_plans_created = 0;
}

void CalorieCalculator::collect_data()
{
    std::cout << "\n[Enter your gender (M/F)] => ";
    std::cin >> m_person_data->gender;
    print_separator();

    std::cout << "[Enter your age] => ";
    std::cin >> m_person_data->age;
    print_separator();

    std::cout << "[Enter your height in CM] => ";
    std::cin >> m_person_data->height;
    print_separator();

    std::cout << "[Enter your weight in KG] => ";
    std::cin >> m_person_data->weight;
    print_separator();

    std::cout << "(1) Sedentary (little to no exercise)\n" \
                 "(2) Lightly active (Light exercise: 1-3 days/week)\n" \
                 "(3) Moderately active (Moderate exercise: 3-5 days/week)\n" \
                 "(4) Very active (Hard exercise 6-7 days/week)\n\n" \
                 "    [Choose your activity level] => ";
    std::cin >> m_person_data->activity;
    print_separator();

    std::cout << "(1) Maintain Body weight\n" \
                 "(2) Lose 0.25kg/week\n" \
                 "(3) Lose 0.5kg/week\n" \
                 "(4) Gain Muscle\n\n" \
                 "    [Choose your current goal] => ";
    std::cin >> m_person_data->goal;
    print_separator();

    char macros_choice;
    std::cout << "[Want macronutrient plan? (Y/N)] => ";
    std::cin >> macros_choice;
    
    if (toupper(macros_choice) == 'Y') {
        m_person_data->wants_macros = true;
    }
}

void CalorieCalculator::calculate_calories()
{
    if (toupper(m_person_data->gender) == 'M')
    {
        m_cal_data->bmr_calories = (10 * m_person_data->weight) + (6.25 * m_person_data->height) - (5 * m_person_data->age) + 5;

        m_cal_data->weight_maintain_calories = determine_maintain_calories();

        m_cal_data->weight_gain_calories = m_cal_data->weight_maintain_calories + 300;

        m_cal_data->weight_lose_quarter_kg_calories = \
            m_cal_data->weight_maintain_calories - (CALORIES_1_KG_FAT * QUARTER_KG / WEEK);

        m_cal_data->weight_lose_half_kg_calories = \
            m_cal_data->weight_maintain_calories - (CALORIES_1_KG_FAT * HALF_KG / WEEK);
    }
    else if (toupper(m_person_data->gender) == 'F')
    {
        m_cal_data->bmr_calories = (10 * m_person_data->weight) + (6.25 * m_person_data->height) - (5 * m_person_data->age) - 161;

        m_cal_data->weight_maintain_calories = determine_maintain_calories();

        m_cal_data->weight_gain_calories = m_cal_data->weight_maintain_calories + 250;

        m_cal_data->weight_lose_quarter_kg_calories = \
            m_cal_data->weight_maintain_calories - (CALORIES_1_KG_FAT * QUARTER_KG / WEEK);

        m_cal_data->weight_lose_half_kg_calories = \
            m_cal_data->weight_maintain_calories - (CALORIES_1_KG_FAT * HALF_KG / WEEK);
    }
}

int CalorieCalculator::determine_maintain_calories()
{
    // Calculate calories required for body weight maintaining
    switch (m_person_data->activity)
    {
        case 1: return (m_cal_data->bmr_calories * 1.2);
        case 2: return (m_cal_data->bmr_calories * 1.375);
        case 3: return (m_cal_data->bmr_calories * 1.55);
        case 4: return (m_cal_data->bmr_calories * 1.725);
    }
    return 0;
}

void CalorieCalculator::calculate_macros(int calorie_choice)
{
    int calorie_buffer = calorie_choice;
    
    /* 1. Calculate at least 2gr. protein/kg
       2. If more, limit kcal from protein to 35% of total kcal */
    if ((calorie_buffer - (m_person_data->weight * 2 * CALORIES_IN_PROTEIN)) < (calorie_buffer * 0.65)) {
        m_macro_data->gr_protein = (calorie_buffer * 0.35) / CALORIES_IN_PROTEIN;
    }
    else {
        m_macro_data->gr_protein = m_person_data->weight * 2;
    }

    /* 1. Calculate at least 1g. fat/kg
       2. If more, limit kcal from fat to height - 100 */ 
    if (m_person_data->weight > (m_person_data->height - 100)) {
        m_macro_data->gr_fat = m_person_data->height - 100;
    }
    else {
        m_macro_data->gr_fat = m_person_data->weight;
    }

    // Subtract calories from protein and fat from the buffer
    calorie_buffer -= m_macro_data->gr_protein * CALORIES_IN_PROTEIN;
    calorie_buffer -= m_macro_data->gr_fat * CALORIES_IN_FAT;

    // Distribute the remaining calories for carbohydrates
    m_macro_data->gr_carbs = calorie_buffer / CALORIES_IN_CARBS;
}

void CalorieCalculator::create_meal_plan()
{
    // Get 90% of protein from primary protein sources and leave 10 % for secondary
    const int PROTEIN_PER_MEAL = (m_macro_data->gr_protein * 0.9) / NR_OF_MEALS;
    int total_calories = (m_macro_data->gr_protein + m_macro_data->gr_carbs) * 4 + m_macro_data->gr_fat * 9;

    // Leave 15% kcal for foods with fiber - fruits and vegetables
    m_meal_plan->calories_from_fiber = total_calories * 0.15;
    total_calories -= m_meal_plan->calories_from_fiber;

    MacrosData total_macros {};
    MacrosData meals[4] = {0};

    ProteinSource proteins = {};
    CarbSource    carbs    = {};
    FatSource     fats     = {};

    // Get different protein source in different meals
    std::vector<FoodItem> meal_1or3_prot {
        proteins.egg, proteins.yoghurt,
        proteins.cott_cheese, proteins.whey_protein
    };
    std::vector<FoodItem> meal_2or4_prot {
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
        int fat_per_meal = (m_macro_data->gr_fat - total_macros.gr_fat) / meals_left;
        int random;
        FoodItem current_item;

        if (i % 2 == 1)
        {
            random = rand() % meal_1or3_prot.size();
            current_item = meal_1or3_prot[random];
            meal_1or3_prot.erase(meal_1or3_prot.begin() + random);
        }
        else
        {
            random = rand() % meal_2or4_prot.size();
            current_item = meal_2or4_prot[random];
            meal_2or4_prot.erase(meal_2or4_prot.begin() + random);
        }

        double portion_size_100g = 0;
        int quantity = 0;
        std::string message = "";
        
        if ((current_item.name == "Egg"))
        {
            // Max 5 eggs; max 3 if total fat is below 70
            int max_protein_from_eggs;
            if (m_macro_data->gr_fat < 70) {
                max_protein_from_eggs = 18;
            }
            else {
                max_protein_from_eggs = 30;
            }

            portion_size_100g = (max_protein_from_eggs / 6) * 50;

            // Replace everything over 5 eggs (250g.) with ham
            int needed_protein = PROTEIN_PER_MEAL - max_protein_from_eggs;
            double portion_size_ham_100g = needed_protein / proteins.ham.gr_protein;

            int quantity_ham = 100 * portion_size_ham_100g;
            round_quantity(quantity_ham, 5);

            message = std::to_string(quantity_ham) + "g. " + proteins.ham.name + " & 250g. Egg";
            switch (i)
            {
                case 1: m_meal_plan->breakfast.protein = message; break;

                case 2: m_meal_plan->lunch.protein = message; break;
                
                case 3: m_meal_plan->afternoon_breakfast.protein = message; break;
                
                case 4: m_meal_plan->dinner.protein = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, proteins.ham, portion_size_ham_100g, i-1);
        }
        else
        {
            portion_size_100g = PROTEIN_PER_MEAL / current_item.gr_protein;
            quantity = 100 * portion_size_100g;

            round_quantity(quantity, 5);

            message = std::to_string(quantity) + "g. " + current_item.name;
            switch (i)
            {
                case 1: m_meal_plan->breakfast.protein = message; break;

                case 2: m_meal_plan->lunch.protein = message; break;

                case 3: m_meal_plan->afternoon_breakfast.protein = message; break;
                
                case 4: m_meal_plan->dinner.protein = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);
        }

        random = rand() % fat_sources.size();
        current_item = fat_sources[random];

        if (fat_per_meal > meals[i-1].gr_fat) {
            portion_size_100g = (fat_per_meal - meals[i-1].gr_fat) / current_item.gr_fat;
        }
        else {
            portion_size_100g = meals[i-1].gr_fat / current_item.gr_fat;
        }

        quantity = 100 * portion_size_100g;
        round_quantity(quantity, 5);

        if (quantity == 0) {
            message = "No added fats for this meal.";
        }
        else {
            message = std::to_string(quantity) + "g. " + current_item.name;
        }

        switch (i)
        {
            case 1:
                m_meal_plan->breakfast.fats = message; break;
            case 2:
                m_meal_plan->lunch.fats = message; break;
            case 3:
                m_meal_plan->afternoon_breakfast.fats = message; break;
            case 4:
                m_meal_plan->dinner.fats = message; break;
        }

        save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);

        const int CARBS_PER_MEAL = m_macro_data->gr_carbs / NR_OF_MEALS;
        random = rand() % carb_sources.size();
        current_item = carb_sources[random];

        if (meals[i-1].gr_carbs < CARBS_PER_MEAL)
        {
            portion_size_100g = (CARBS_PER_MEAL - meals[i-1].gr_carbs) / current_item.gr_carb;
            quantity = 100 * portion_size_100g;

            round_quantity(quantity, 5);

            message = std::to_string(quantity) + "g. " + current_item.name;
            switch (i)
            {
                case 1: m_meal_plan->breakfast.carbs = message; break;

                case 2: m_meal_plan->lunch.carbs = message; break;

                case 3: m_meal_plan->afternoon_breakfast.carbs = message; break;

                case 4:m_meal_plan->dinner.carbs = message; break;
            }

            save_meal_data(meals, total_macros, total_calories, current_item, portion_size_100g, i-1);
        }
        else
        {
            message = "No added carbs for this meal";
            switch (i)
            {
                case 1: m_meal_plan->breakfast.carbs = message; break;

                case 2: m_meal_plan->lunch.carbs = message; break;

                case 3: m_meal_plan->afternoon_breakfast.carbs = message; break;

                case 4: m_meal_plan->dinner.carbs = message; break;
            }
        }
        meals_left--;
        // test(total_macros, meals);
    }
}

void CalorieCalculator::save_meal_data(
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

void CalorieCalculator::test(MacrosData meals[4]) const
{
    std::cout << "FATS: " << m_macro_data->gr_fat << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "P " << meals[i].gr_protein << std::endl;
        std::cout << "G " << meals[i].gr_carbs << std::endl;
        std::cout << "F " << meals[i].gr_fat << std::endl;
        std::cout << "--------------" << std::endl;
    }
}