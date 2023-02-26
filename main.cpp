#include <iostream>
#include <climits>

using namespace std;
void numbers();
void room_width();
void test_types();
void size_of();
void allowed_size();
void estimate_cost();


int main() {

    estimate_cost();

    return 0;
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