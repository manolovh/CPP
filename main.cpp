#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;
void numbers();
void room_width();
void test_types();
void size_of();
void allowed_size();
void estimate_cost();
void arr();
void vect();
void currency();
void grade();


int main() {

    grade();

    return 0;
}

void grade(){
    char letter_grade {};

    cout << "Enter a letter grade: ";
    cin >> letter_grade;

    switch (letter_grade) {
        case 'a':
        case 'A': cout << "You need 90 points or above." << endl; break;
        case 'b':
        case 'B': cout << "You need 80 to 89 points." << endl; break;
        case 'c':
        case 'C': cout << "You need 70 to 79 point.s" << endl; break;
        case 'd':
        case 'D': cout << "You need 60 to 69 points." << endl; break;
        case 'f':
        case 'G': cout << "You need less than 60 points, but that's not acceptable!" << endl; break;

        default: cout << "Sorry, that's not a valid grade." << endl; 

    }

    enum Direction {
        left, right, up, down
    };

    Direction heading {left};

    switch (heading){
        case left: cout << "Go left..." << endl; break;
        case right: cout << "Go right..." << endl; break;
        case up: cout << "Go up..." << endl; break;
        case down: cout << "Go down..." << endl; break;
    }
}


void currency(){
    cout << "Enter the amount in cents: ";
    int amount {};
    cin >> amount;

    int dollars {amount / 100};
    int quarters {(amount % 100) / 25};
    int dimes {amount % 100 % 25 / 10};
    int nickels {amount % 100 % 25 % 10 / 5};
    int pennies {amount % 100 % 25 % 10 % 5};
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << endl;

    cout << fixed << setprecision(2); // prints ints with .xx precision
    cout << 1.22121 << endl;
}

void vect(){

    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "Vector 1:" << endl;
    cout << "Element 1: " << vector1.at(0) << endl;
    cout << "Element 2: " << vector1.at(1) << endl;
    cout << "Size: " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nVector 2:" << endl;
    cout << "Element 1: " << vector2.at(0) << endl;
    cout << "Element 2: " << vector2.at(1) << endl;
    cout << "Size: " << vector2.size() << endl;

    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nVector 2D:" << endl;
    cout << "Vector 1 elements: " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << endl;
    cout << "Vector 2 elements: " << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;
    cout << "\nVector 2D:" << endl;
    cout << "Vector 1 elements: " << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << endl;
    cout << "Vector 2 elements: " << vector_2d.at(1).at(0) << ", " << vector_2d.at(1).at(1) << endl;

    cout << "\nVector 1 elements: " << vector1.at(0) << ", " << vector1.at(1) << endl;
}

void arr() {
    
    int arr[] {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << endl;
    }
}

void estimate_cost() {
    const float small_room_price {25};
    const float large_room_price {35};
    const float sales_tax {0.06};
    const int estimate {30};

    cout << "Please enter how many small rooms you'd like to be cleaned: ";
    int small_rooms {0};
    cin >> small_rooms;
    cout << "Please enter how many large rooms you'd like to be cleaned: ";
    int large_rooms {0};
    cin >> large_rooms;
    float total_sum {(small_rooms * small_room_price) + (large_rooms * large_room_price)};
    float total_tax {total_sum * sales_tax};

    cout << "Estimate for carpet cleaning service: " << endl;
    cout << "Number of small rooms: " << small_rooms << endl;
    cout << "Number of large rooms: " << large_rooms << endl;
    cout << "Price per small room: $" << small_room_price << endl;
    cout << "Price per large room: $" << large_room_price << endl;
    cout << "Cost: $" << total_sum << endl;
    cout << "Tax: $" << total_tax << endl;
    cout << "==============================================" << endl;
    cout << "Total estimate: $" << total_sum + total_tax << endl;
    cout << "This estimate is valid for " << estimate << " days." << endl;
}

void allowed_size() {
    cout << "Char Min " << CHAR_MIN << endl;
    cout << "Char Max " << CHAR_MAX << endl;
    cout << "Int Min " << INT_MIN << endl;
    cout << "Int Max " << INT_MAX << endl;
    cout << "Long Min " << LONG_MIN << endl;
    cout << "Long Max " << LONG_MAX << endl;
    cout << "Short Max " << SHRT_MIN << endl;
    cout << "Short Max " << SHRT_MAX << endl;
    cout << "Long Long Min " << LLONG_MIN << endl;
    cout << "Long Long Max " << LLONG_MAX << endl;
}

void size_of() {
    
    cout << "Char: " << sizeof(char) << endl;
    cout << "Int: " << sizeof(int) << endl;
    cout << "Unsigned: " << sizeof(unsigned) << endl;
    cout << "Short: " << sizeof(short) << endl;
    cout << "Long: " << sizeof(long) << endl;
    cout << "Long Long: " << sizeof(long long) << endl;
    cout << "Float: " << sizeof(float) << endl;
    cout << "Double: " << sizeof(double) << endl;
    cout << "Long Double: " << sizeof(long double) << endl;

    int age {65};
    cout << sizeof(age) << endl;

    double wage {4442.22};
    cout << sizeof(wage) << endl;

    char one {'P'};
    cout << sizeof(one) << endl;
}

void test_types() {

    char middle_name {'D'};
    cout << middle_name << endl;

    unsigned short not_signed {22};
    cout << not_signed << endl;

    long distance1 {100002222};
    cout << distance1 << endl;

    long long distance2 {100'002'222'213'123'213};
    cout << distance2 << endl;

    float payment {441.222};
    cout << payment << endl;

    double pi {3.141259291921};
    cout << pi << endl;

    long double test {2.7e120};
    cout << test << endl;

    bool is_true {true};
    cout << is_true << endl;

    short i {20000};
    short j {1000};
    int i_times_j {i * j};
    cout << i_times_j << endl;
}

void numbers(){
    int num1;
    double num2;
    cout << "Please enter 2 digits: ";
    cin >> num1 >> num2;
    cout << "You chose " << num1 << " and " << num2 << endl;
}

void room_width() {
    cout << "Please enter the width of the room: ";
    int width {0};
    cin >> width;

    cout << "Please enter the length of the room: ";
    int length {0};
    cin >> length;

    cout << "The total area of the room is " << length * width << " sq. ft." << endl;
}