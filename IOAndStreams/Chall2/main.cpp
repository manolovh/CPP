#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    std::fstream in_file;
    std::string answer_key {};
    double total_grades {};
    int total_students {};
    int formatting_size = 20;

    in_file.open("./responses.txt");

    if (!in_file)
        std::cerr << "Failed to open a file." << std::endl;

    in_file >> answer_key;

    // Output formatting
    std::cout << "Student" << std::setw(formatting_size - 7) << std::right << "Score" << std::endl;
    std::cout << std::setw(formatting_size) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    while (!in_file.eof()) {
        // While available students, display student-score pair
        std::string curr_name {};
        std::string curr_answer {};
        int curr_counter {};

        in_file >> curr_name >> curr_answer;

        // Process response
        for (size_t i = 0; i < answer_key.length(); ++i) {
            if (curr_answer[i] == answer_key[i])
                curr_counter += 1;
        }

        // Output formatting
        std::cout << std::setw(formatting_size - 1) << std::left << curr_name
                  << std::right << curr_counter << std::endl;

        total_grades += curr_counter;
        total_students++;
        curr_counter = 0;
    }

    // Output formatting
    std::cout << std::setw(formatting_size) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(formatting_size - 3) << std::left << "Average grade: "
              << total_grades / total_students << std::endl;

    in_file.close();
} 