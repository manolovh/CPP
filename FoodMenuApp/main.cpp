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

    print_calories_info(cal_data, person_data.goal);

    return 0;
}
