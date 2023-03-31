#include <iostream> // required for cin/cout
#include <climits>
#include <vector> // required for vectors
#include <string> // required for string
#include <algorithm> // required for reverse()
#include <cstdlib> // required for rand()
#include <ctime>

using namespace std;

void c_string();
void c_str();
void cpp_str();
void encrypted();
void pyramid();
void func();
int add(int, int);
double add(double, double);
void print_array(const int numbers[], size_t size);
void pass_by_ref(int &num);
void print(vector<int> &v); // const ensures data not modified; &v doesn't make a copy - more performance
void static_example();
unsigned long long fibonacci(unsigned long long n);
unsigned long long factorial(unsigned long long n);
double a_penny_doubled_everyday(int n, double amount);
void loop_challenge();
void print_numbersconst vector <int> &vect);
void add_num(vector <int> &vec);
void calculcate_average(const vector <int> &vect);
void print_smallest(const vector <int> &vect);
void print_largest(const vector <int> &vect);
void clear_vector(vector <int> &vec);
void display_menu();

int main() {
    loop_challenge();
    return 0;
}

void loop_challenge(){
    vector <int> numbers {1, 2, 3};
    char choice {};
    
    do {
        display_menu();
        cin >> choice;

        switch (choice) {
            case 'P':
            case 'p': print_numbers(numbers); break;
            case 'A':
            case 'a': add_num(numbers); break;
            case 'M':
            case 'm': calculcate_average(numbers); break;
            case 'S':
            case 's': print_smallest(numbers); break;
            case 'L':
            case 'l': print_largest(numbers); break;
            case 'C':
            case 'c': clear_vector(numbers); break;
            case 'q':
            case 'Q': cout << "Exiting..." << endl; break;
            default: cout << "Unknown selection, please try again" << endl; break;
        }
    } while (choice != 'Q' && choice != 'q');
}

void display_menu() {
    cout << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display the mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "C - Clear the list" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

void clear_vector(vector <int> &vect) {
    if (vect.size() == 0)
        cout << "The list is already empty.";
    else {
        vect.clear();
        cout << "The list has been cleared" << endl;
    }
}

void print_largest(const vector <int> &vect) {
    if (vect.size() == 0)
        cout << "Unable to determine the largest number - the list is empty";
    else {
        int largest {vect[0]};
        for (auto elem: vect) {
            if (elem > largest)
                largest = elem;
        }
        cout << "The largest number is " << largest << endl;
    }
}

void print_smallest(const vector <int> &vect) {
    if (vect.size() == 0)
        cout << "Unable to determine the smallest number - the list is empty";
    else {
        int smallest {vect[0]};
        for (auto elem: vect) {
            if (elem < smallest)
                smallest = elem;
        }
        cout << "The smallest number is " << smallest << endl;
    }
}

void calculcate_average(const vector <int> &vect) {
    if (vect.size() == 0)
        cout << "Unable to calculate the average - no data";
    else {
        int total {};
        for (auto elem: vect)
            total += elem;
        cout << "Average: " << static_cast<double>(total) / vect.size() << endl;
    }
}

void add_num(vector <int> &vect) {
    int num {};
    cout << "Enter the number to add: ";
    cin >> num;
    vect.push_back(num);
    cout << num << " added" << endl;
}

void print_numbers(const vector <int> &vect){
    if (vect.size() == 0)
        cout << "[] - the list is empty";
    else {
        cout << "[ ";
        for (auto elem: vect){
            cout << elem << " ";
            }
        cout << "]" << endl;
    }
}

double a_penny_doubled_everyday(int n, double amount) {
    if (n <= 1)
        return amount;
    return a_penny_doubled_everyday(n - 1, amount * 2);

}
unsigned long long factorial(unsigned long long n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

unsigned long long fibonacci(unsigned long long n) {
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void static_example() {
    static int number {100};
    cout << "Before modifying: " << number << endl;
    number += 50;
    cout << "After modifying: " << number << endl;
}

void print(vector<int> &v) {
    for (auto num: v){
        num = 10;
        cout << num << endl;
    }
}

void pass_by_ref(int &num) {
    num = 69;
}

void print_array(const int numbers[], size_t size) {
    for (size_t i{0}; i < size; ++i)
        cout << numbers[i] << endl;
}

int add(int a, int b) {
    int result {a + b};
    return result;
}

double add(double a, double b) {
    double result {a + b};
    return result;
}

void func() {
    int random_num{};
    int min {1};
    int max {6};

    cout << "Rand Max is " << RAND_MAX << endl;
    srand(time(nullptr)); // done in order to return unique nums every time

    for (int i {1}; i <= 10; i++) {
        random_num = rand() % max + min;
        cout << "No. " << i << ": " << random_num << endl; 
    }
}

void pyramid() {
    string user_input {};
    cout << "Enter a word you want to display as a pyramid: ";
    cin >> user_input;

    for (size_t i {0}; i < user_input.size(); i++) {
        size_t counter = user_input.size() - (i + 1);
        for (size_t j {0}; j < counter; j++)
                cout << " ";
        
        if (i == 0)
            cout << user_input[i] << endl;
        else {
            cout << user_input.substr(0, i + 1);
            string sub {user_input.substr(0, i)};
            reverse(sub.begin(), sub.end());
            cout << sub;
            cout << endl;
        }
    }
}


void encrypted() {
    string message {};
    
    cout << "Enter the message that you want to encrypt: ";
    getline(cin, message);

    string alphabet {"efghijklmnopqrstuvwxyzabcdEFGHIJKLMNOPQRSTUVWXYZABCD"};
    string key {"JKLMNOPQRSTUVWXYZABCDEFGHIjklmnopqrstuvwxyzabcdefghi"};

    string encrypted_message {message};
    for (size_t i {0}; i < message.size(); i++) 
        if (isalpha(message[i]))
            encrypted_message[i] = key[alphabet.find(message[i])];

    cout << "Here's the encrypted version: " << encrypted_message << endl;

    string original_message {encrypted_message};
    for (size_t i {0}; i < encrypted_message.size(); i++)
        if (isalpha(message[i]))
            original_message[i] = alphabet[key.find(encrypted_message[i])];

    cout << "Here's the original version: " << original_message << endl;
}

void cpp_str() {
    string s1 {"Apple is good."};
    string s2 {s1}; // Apple
    string s3 {s1, 0, 4}; // Appl
    string s4 (10, 'X'); // "XXXXXXXXXX"
    string s5;

    cout << s5 << endl; // No garbage value
    cout << s4.length() << endl;

    cout << s1.substr(0, 5) << endl; // index, length
    cout << s1.substr(6, 2) << endl; // same
    cout << s1.substr(9, 5) << endl; // same

    s1.erase(0, 5);
    cout << s1 << endl; // " is good."

    string full_name {};
    getline(cin, full_name);
    cout << full_name << endl;

    string word {};
    cout << "Find a word: ";
    cin >> word;
    cout << word << " found at index " << s1.find(word) << endl;
}

void c_string() {
    char my_name[] {"Harry"}; // C style strings
    my_name[1] = 'u';
    cout << my_name << endl;
}

void c_str() {
    char fname[20] {};
    char lname[20] {};
    char full_name[50] {};

    cout << "Enter your first name: ";
    cin >> fname;

    cout << "Enter your last name: ";
    cin >> lname;

    cout << "Hello, " << fname << lname << endl;

    strcpy(full_name, fname);
    strcat(full_name, " ");
    strcat(full_name, lname);
    cout << "Hi (again), " << full_name;

    char fullname[50] {};
    cout << "Enter you full name: ";
    cin.getline(fullname, 50); // cin reads the first 50 characters and extracts
    cout << "Hello, " << fullname << endl;
}