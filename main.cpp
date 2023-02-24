#include <iostream>

using namespace std;
void numbers();
void room_width();

int main() {

    room_width();

    return 0;
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