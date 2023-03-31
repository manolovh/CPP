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
void cond_statement();
void forloop();
void while_loop();
void dowhile_loop();
void nested_loop();
void loop_exercise();
void loop_challenge();

int main() {

    loop_challenge();
    return 0;
}

void loop_challenge(){
    vector <int> numbers {};
    char choice {'A'};
    
    while (true){
        cout << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 'Q' || choice == 'q')
            break;

        else if (choice == 'P' || choice == 'p') {
            if (numbers.size() == 0)
                cout << "[] - the list is empty";
            else {
                cout << "[ ";
                for (auto elem: numbers){
                    cout << elem << " ";
                }
                cout << "]" << endl;
            }
        }

        else if (choice == 'A' || choice == 'a') {
            int num {};
            cout << "Enter the number to add: ";
            cin >> num;
            numbers.push_back(num);
            cout << num << " added" << endl;
        }

        else if (choice == 'M' || choice == 'm') {
            if (numbers.size() == 0)
                cout << "Unable to calculate the average - no data";
            else {
                int total {};
                for (auto elem: numbers)
                    total += elem;
                cout << "Average: " << static_cast<double>(total) / numbers.size() << endl;
            }
        }

        else if (choice == 'S' || choice == 's') {
            if (numbers.size() == 0)
                cout << "Unable to determine the smallest number - the list is empty";
            else {
                int smallest {numbers[0]};
                for (auto elem: numbers) {
                    if (elem < smallest)
                        smallest = elem;
                }
                cout << "The smallest number is " << smallest << endl;
            }
        }

        else if (choice == 'L' || choice == 'l') {
            if (numbers.size() == 0)
                cout << "Unable to determine the largest number - the list is empty";
            else {
                int largest {numbers[0]};
                for (auto elem: numbers) {
                    if (elem > largest)
                        largest = elem;
                }
                cout << "The largest number is " << largest << endl;
            }
        }

        else if (choice == 'C' || choice == 'c') {
            if (numbers.size() == 0)
                cout << "The list is already empty.";
            else {
                numbers.clear();
                cout << "The list has been cleared" << endl;
            }
        }

        else {
            cout << "Unknown selection, please try again" << endl;
        }
    }
}

void loop_exercise(){
    vector <int> vec {2, 4, 6, 8};

    int result {0};
    int index {1};

    for (auto elem: vec){
        int i = index;
        for (i; i < vec.size(); ++i){
            result += elem * vec[i];
        }
        index++;
    }
    cout << result;
}

void nested_loop(){
    vector <vector<int>> vect {
        {10},
        {10, 20},
        {10, 20, 30}
    };

    for (auto vec: vect){
        for (auto value: vec){
            cout << value << " ";
        }
        cout << endl;
    }

    int data_items {};
    vector <int> data {};
    
    cout << "Enter how many data items you need: ";
    cin >> data_items;
    for (int i {1}; i <= data_items; i++){
        int curr_item;
        cout << "Enter item " << i << ": ";
        cin >> curr_item;
        data.push_back(curr_item);
    }
    cout << "Here's your \"histogram\": " << endl;
    for (auto item: data){
        for (int i {1}; i < item; ++i){
            if (i % 5 == 0)
                cout << "-";
            else
                cout << "=";
        }
        cout << endl;
    }
}
void dowhile_loop(){
    // int i {10};
    // do {
    //     cout << i << endl;
    //     i++;
    // } while (i < 5);
    char selection {};
    do {
        double height {};
        double width {};
        cout << "Enter heigth and width, separated by a space: ";
        cin >> height >> width;

        double result = height * width;
        cout << "The area you chose is " << result << endl;
        cout << "Do you want to continue? (Y/N) ";
        cin >> selection;
    } while (selection == 'y' || selection == 'Y');
}

void while_loop(){
    vector <int> vec {10, 20, 30, 40, -99};
    int count {0};
    bool is_present {false};

    while (!is_present && count < vec.size()){
        if (vec[count] == -99)
            is_present = true;
         else
            count++;
    }
    cout << count << endl;
}

void forloop(){
    vector <int> nums {10, 20, 30, 40, 50};
    // int nums [] {10, 20, 30, 40, 50};

    for (int i: nums)
        // cout << i << ((i % 3 == 0) ? "\n" : " ");
        cout << i << endl;
}

void cond_statement(){
    int a {52};
    int b {7};
    // retruns "Yes" if a > b is true, returns "No" if a > b is false
    cout << ((a > b) ? "Yes" : "No") << endl;

    int num {};
    cout << "Enter an integer: ";
    cin >> num;
    cout << num << ((num % 2 == 0) ? " is even." : " is odd.") << endl;
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