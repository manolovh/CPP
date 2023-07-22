#include <iostream>
#include <string>

using namespace std;
int sum_of_digits(int n) {
    // Write your code below this line
    string str = to_string(n);
    char curr_string = str[0];
    int sum = stoi(string(1, curr_string));
    str.erase(0, 1);
    
    if (str.size())
        sum += sum_of_digits(stoi(str));
    return sum;
}

typedef int GOSHO[500];

void t1() {
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
}

int main() {
    std::cout << sum_of_digits(1234);
    return 0;
}