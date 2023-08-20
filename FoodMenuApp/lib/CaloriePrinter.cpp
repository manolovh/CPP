#include "../inc/CaloriePrinter.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

void CaloriePrinter::print_macros(CalorieCalculator& calc)
{
    std::cout << std::setfill('-') << std::setw(FORMAT_SIZE + 4) << "";
    std::cout << "\nGrams of protein: " << std::setfill(' ') << std::setw(8) << static_cast<int>(calc.m_macro_data->gr_protein) << std::endl;
    std::cout << "Grams of carbohydrate: " << std::setw(2) << static_cast<int>(calc.m_macro_data->gr_carbs) << std::endl;
    std::cout << "Grams of fat: " << std::setw(11) << static_cast<int>(calc.m_macro_data->gr_fat) << std::endl;
    std::cout << std::endl;
}

void CaloriePrinter::print_meal(Meal const& meal)
{
    std::cout << "\t# " << meal.protein << std::setw(30 - meal.protein.size()) << std::setfill(' ') << "#" << std::endl;
    std::cout << "\t# " << meal.carbs << std::setw(30 - meal.carbs.size()) << std::setfill(' ') << " #" << std::endl;
    std::cout << "\t# " << meal.fats << std::setw(30 - meal.fats.size()) << std::setfill(' ') << "#" << std::endl;
    std::cout << "\t# " << std::setw(30) << std::setfill('-') << "#" << std::endl;
    std::cout << std::setw(' ');
}

void CaloriePrinter::print_meal_plan(CalorieCalculator& calc)
{
    char choice = 'Y';

    while (toupper(choice) == 'Y')
    {
        calc.create_meal_plan();
        calc.m_meal_plans_created++;

        if (calc.m_meal_plans_created == 1)
            std::cout << "\n-----Example meals, created for your specific goal-----" << std::endl;

        std::cout << "\n\t#----------Breakfast-----------#" << std::endl;
        print_meal(calc.m_meal_plan->breakfast);

        std::cout << "\n\t#------------Lunch-------------#" << std::endl;
        print_meal(calc.m_meal_plan->lunch);

        std::cout << "\n\t#-----Afternoon Breakfast------#" << std::endl;
        print_meal(calc.m_meal_plan->afternoon_breakfast);

        std::cout << "\n\t#------------Dinner------------#" << std::endl;
        print_meal(calc.m_meal_plan->dinner);

        std::cout << "\n\t#----Fruits and Vegetables-----#" << std::endl;

        Vegetable veggies;
        Fruit fruits;
        round_quantity(calc.m_meal_plan->calories_from_fiber, 25);

        std::cout << "\n\tMake sure you include ~" << calc.m_meal_plan->calories_from_fiber
                  << "kcal from a combination of the following:\n" << veggies.twenty_kcal
                  << veggies.fifty_kcal << fruits.thirthy_kcal << fruits.fifty_kcal << std::endl;

        if (calc.m_meal_plans_created == 3)
        {
            std::cout << "\n-----You reached the maximum meals for today-----\n" << std::endl;
            break;
        }

        std::cout << "\nWant more similar meals? (Y/N): ";
        std::cin >> choice;
    }
}

void CaloriePrinter::display_info(CalorieCalculator& calc)
{
    std::cout << "\nBase Metabolic Rate (BMR): "
              << std::setw(FORMAT_SIZE - 27) << calc.m_cal_data->bmr_calories << "kcal" << std::endl;

    std::string message_choice;
    int data_choice;
    switch (calc.m_person_data->goal)
    {
        case 1:
        message_choice = "Maintain Body weight: ";
        data_choice = calc.m_cal_data->weight_maintain_calories; break;

        case 2:
        message_choice = "Lose Body weight (0,25 kg/week): ";
        data_choice = calc.m_cal_data->weight_lose_quarter_kg_calories; break;

        case 3:
        message_choice = "Lose Body weight (0.5 kg/week): ";
        data_choice = calc.m_cal_data->weight_lose_half_kg_calories; break;

        case 4:
        message_choice = "Gain Muscle: ";
        data_choice = calc.m_cal_data->weight_gain_calories; break;

        default:
        message_choice = "You did not choose a correct option. Here are calories for maintaing your body weight: ";
        data_choice = calc.m_cal_data->weight_maintain_calories; break;
    }

    std::cout << message_choice << std::setw(FORMAT_SIZE - message_choice.size()) << data_choice << "kcal" << std::endl;

    if (calc.m_person_data->wants_macros)
        calc.calculate_macros(data_choice);
}

void round_quantity(int& quantity, int selection)
{
    // Make all grams end in either 5 or 10 for more aesthetic look
    if (quantity % selection < 3)
    {
        quantity -= quantity % selection;
    }
    else
    {
        quantity += selection - (quantity % selection);
    }
}

void print_separator()
{
    std::cout << "\n------------------------------------------------\n\n";
}