#include <iostream>
#include <string>
#include "../inc/CalorieCalculator.hpp"
#include "../inc/CaloriePrinter.hpp"

int main()
{
    CalorieCalculator calculator = CalorieCalculator();
    CaloriePrinter printer = CaloriePrinter();

    calculator.collect_data();

    calculator.calculate_calories();

    printer.display_info(calculator);

    if (calculator.m_person_data->wants_macros)
    {
        printer.print_macros(calculator);
    }

    char choice;
    std::cout << "Want an example meal plan, based on your goal? (Y/N): ";
    std::cin >> choice;

    if (toupper(choice) == 'Y')
    {
        printer.print_meal_plan(calculator);
    }

    return 0;
}
