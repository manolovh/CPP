#include <iostream>

typedef int GOSHO[500];

int main() {
    GOSHO data[28]; // 28 GOSHO's of 500 doubles

    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 500; ++j)
            data[i][j] = j;
    }

    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 500; ++j)
            std::cout << data[i][j] << " ";
        std::cout << "\n\n";
    }
    return 0;
}