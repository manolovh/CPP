#include <iostream>
#include <fstream>

int main() {
    std::fstream in_file;
    std::string selected_word;
    int total_words {};
    int times_found {};

    in_file.open("./romeoandjulliet.txt");
    if (!in_file) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::cout << "Enter the substring to search for: ";
    std::cin >> selected_word;

    while (!in_file.eof()) {
        std::string current_word {};
        in_file >> current_word;
        if (current_word.find(selected_word) != std::string::npos)
            times_found++;
        total_words++;
    }

    std::cout << total_words << " words were searched..." << std::endl;
    std::cout << "The substring " << selected_word << " was found "
              << times_found << " times" << std::endl;

    return 0;
}