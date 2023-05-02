#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::ofstream out_file;
    std::string line {};
    int counter {1};

    in_file.open("./original.txt");
    out_file.open("./copy.txt");

    if (!in_file && !out_file) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    while (!in_file.eof()) {
        std::getline(in_file, line);
        if (line != "") {
            out_file << counter << "\t" << line << std::endl;
            counter++;
        }
        else {
            out_file << line << std::endl;
        }
    }

    std::cout << "Copied file successfully" << std::endl;
    in_file.close();
    out_file.close();

    return 0;
}