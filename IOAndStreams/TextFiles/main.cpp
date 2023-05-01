#include <iostream>
#include <fstream>

// ----------------- Reading from a file ---------------------
void reading_1() {
    std::fstream in_file {"./test.txt", std::ios::in};
    std::fstream in_file2 {"./test.txt", std::ios::in | std::ios::binary}; // input and binary mode
    std::ifstream in_file3 {"./test.txt"}; // mode is optional

    std::ifstream in_file4;
    std::string filename;
    std::cin >> filename;

    in_file4.open(filename);
    if (in_file4.is_open()) {
        std::string data {};
        in_file4 >> data;
        std::cout << data << std::endl;
        
        std::string line {};
        std::getline(in_file4, line);

        std::cout << line << std::endl;

    }

    in_file4.close();
}

int read_whole_file() {
    std::ifstream in_file("./test.txt");
    std::string line {};

    if (!in_file) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    while (!in_file.eof()) {
        std::getline(in_file, line);
        std::cout << line << std::endl;

        // read a file character by character
        // std::get(in_file, character);
        // std::cout << character << std::endl;
    }

    in_file.close();
    return 0;
}
// --------------- Reading from a file end -----------------


// --------------- Writing to a file end -------------------
int writing_1() {
    // std::fstream out_file("./pesho.txt", std::ios::out | std::ios::binary);
    std::ofstream out_file("./pesho.txt", std::ios::binary);

    std::ofstream out_file2;
    std::string filename;
    std::cin >> filename;

    out_file2.open(filename, std::ios::app);

    if (!out_file2) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    else {
        out_file2 << "Pesho e gotin.\n" << "Ponqkoga pesho ne e gotin." << std::endl;
    }

    out_file2.close();
    return 0;
}


int main() {
    writing_1();
}