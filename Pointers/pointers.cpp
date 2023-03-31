#include <iostream> // required for cin/cout
#include <climits>
#include <vector> // required for vectors
#include <string> // required for string
#include <algorithm> // required for reverse()
#include <cstdlib> // required for rand()
#include <ctime>

using namespace std;

void pointer_basic();
void memory_alloc();
void pointer_arithmetic();
void pointer_function(int *int_ptr);
void swap_by_pointers(int *a, int *b);
void vect_pointer(const vector <int> *const v);
int *return_pointer(int *a, int *b);
void references();
int *apply_all(int arr1[], int arr2[], int size1, int size2);
void main_challenge();
void print(const int *const result, int count);

int main() {
    main_challenge();

    return 0;
}

int *apply_all(int arr1[], int arr2[], int size1, int size2) {
    int size_3 {size1 * size2};
    int *arr_pointer {nullptr};
    arr_pointer = new int[size_3];

    for (int i {0}; i < size2; ++i) {
        for (int j {0}; j < size1; ++j)
            arr_pointer[(i * 5) + j] = arr1[j] * arr2[i];
    }
    return arr_pointer;
}

void print(const int *const result, int count) {
    for (int i {0}; i < count; ++i)
        cout << result[i] << endl;
}

void main_challenge() {
    int arr1[] {1, 2, 3, 4, 5};
    int arr2[] {10, 20, 30};
    int len1 {5};
    int len2 {3};

    int *results = apply_all(arr1, arr2, len1, len2);
    print(results, 15);

    delete [] results;
}

void references() {
    int nums[] {100, 110, 120, 130, 140, 150};
    int &nums_reference {*nums};
    cout << nums[3] << endl;
    cout << nums_reference << endl;

    vector <int> numbers {100, 20, 30, 400};
    for (auto &num: numbers)
        num = 5;

    // use references(&var), not a copies (because copies use more memory)
    for (auto const &num: numbers)
        cout << num << endl;
}

int *return_pointer(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}

void vect_pointer(const vector <int> *const v){
    // (*v).at(0) = 1000; // not allowed
    // v = nullptr; // not allowed
    for(auto num: *v)
        cout << num << endl;
}

void swap_by_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pointer_function(int *int_ptr) {
    *int_ptr *= 2;
    cout << "New number: " << *int_ptr << endl;
}

void pointer_arithmetic() {
    int nums[] {10, 20, 30, 40, 50};
    int *ptr1 {nums};
    int *(ptr2) {(nums + 4)};

    cout << *ptr1 << endl;
    cout << *ptr2 << endl;

    int n = ptr2 - ptr1;
    cout << n << endl;

    cout << "------------" << endl;
    while (*ptr1 != 50) {
        cout << *ptr1++ << endl; // dereference ptr1 and increment it after we use it
    }
}

void memory_alloc() {
    int *int_ptr {nullptr};
    int_ptr = new int;
    cout << int_ptr << endl; // pointer memory address
    cout << *int_ptr << endl; // garbage value
    *int_ptr = 200;
    cout << *int_ptr << endl; // 200
    int num {*int_ptr};
    cout << num << endl;
    num = 123;
    cout << num << endl;

    delete int_ptr;
    cout << num << endl;

    // initialize a pointer by an array
    int scores[] {100, 95, 90};
    cout << scores << endl;
    cout << *scores << endl;

    int *score_ptr {scores};
    cout << *score_ptr << endl; 
    cout << *(score_ptr + 1) << endl;
    cout << score_ptr[2] << endl;

}

void pointer_basic() {
    int score {10};
    int *score_ptr {nullptr};
    score_ptr = &score;
    *score_ptr = 200;
    cout << "variable adress: " << score_ptr << endl; // what the pointer is pointing to
    cout << "pointer address: " << &score_ptr << endl; // pointer address
    cout << "variable value: " << *score_ptr << endl; // value of what the pointer is pointing to
    cout << "New score: " << score << endl; // accessing the original variable (which is now modified)
    score = 100; // modifying the original variable changes dereferenced pointer returns
    cout << "New score: " << *score_ptr << endl;
}