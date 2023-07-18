#include <iostream>
#include <string>
#include "inc/CalorieCalculator.hpp"
#include "inc/MacrosCalculator.hpp"

int main()
{
    CaloriesData cal_data;
    PersonData person_data;
    MacrosData macro_data;

    collect_data(person_data);

    calculate_calories(
        cal_data, person_data.gender, person_data.age,
        person_data.height, person_data.weight, person_data.activity
    );
    
    display_info(cal_data, macro_data, person_data, person_data.goal);

    if (person_data.wants_macros)
    {
        print_macros(macro_data);
    }

    char choice;
    std::cout << "Want an example meal plan, based on your goal? (Y/N): ";
    std::cin >> choice;

    if (toupper(choice) == 'Y')
    {
        print_meal_plan(macro_data);
    }

    return 0;
}
