#ifndef _PERSON_DATA_HPP
#define _PERSON_DATA_HPP

struct InputData {
    char gender;
    int age;
    double height;
    double weight;
    int activity;
};

void collect_data(InputData &data)
{
    std::cout << "\nEnter your gender (M/F): ";
    std::cin >> data.gender;
    std::cout << "\nEnter your age: ";
    std::cin >> data.age;
    std::cout << "\nEnter your height (in centimenters): ";
    std::cin >> data.height;
    std::cout << "\nEnter your weight (in kilograms): ";
    std::cin >> data.weight;
    std::cout << "\n(1) Sedentary (little to no exercise)" \
                 "\n(2) Lightly active (Light exercise: 1-3 days/week)" \
                 "\n(3) Moderately active (Moderate exercise: 3-5 days/week)" \
                 "\n(4) Very active (Hard exercise 6-7 days/week)" \
                 "\n\nSelect your activity level: ";
    std::cin >> data.activity;
}

#endif // _PERSON_DATA_HPP