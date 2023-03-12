#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <algorithm> 

using namespace std;

void c_string();
void c_str();
void cpp_str();
void encrypted();
void pyramid();

int main() {

    pyramid();
    return 0;
}

void pyramid() {
    string user_input {};
    cout << "Enter a word you want to display as a pyramid: ";
    cin >> user_input;

    for (size_t i {0}; i < user_input.size(); i++) {
        size_t counter = user_input.size() - (i + 1);
        for (int j {0}; j < counter; j++)
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