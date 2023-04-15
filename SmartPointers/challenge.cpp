#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0} { cout << "\tTest constructor (" << data << ")" << endl; }
    Test(int data) : data{data} { cout << "\tTest constructor (" << data << ")" << endl; }
    int get_data() const { return data; }
    ~Test() { cout << "Test destructor (" << data << ")" << endl; }
};

// unique_ptr<vector<shared_ptr<Test>>> make() {
auto make() {
    // unique_ptr<vector<shared_ptr<Test>>> unique_pointer = make_unique<vector<shared_ptr<Test>>>();
    // return unique_pointer;
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    int current_num;
    for (int i = 1; i <= num; i++) {
        cout << "Please enter number " << i << ": ";
        cin >> current_num;
        vec.push_back(make_shared<Test>(current_num));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    cout << "\nYou entered: [ ";
    for (auto elem: vec)
        cout << elem->get_data() << " ";
    cout << "]\n" << endl;
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}


// unique pointer that points to a vector of shared pointers to Test object; no new's or delete's ( make_shared )