#ifndef _MACROS_CALCULATOR_HPP
#define _MACROS_CALCULATOR_HPP

#include "CalorieCalculator.hpp"

struct MacrosData
{
    int gr_protein;
    int gr_fat;
    int gr_carbs;
    double water_intake;
};

MacrosData calculate_macros(MacrosData& macro_data, PersonData const& person_data, CaloriesData const& cal_data);

#endif //  _MACROS_CALCULATOR_HPP