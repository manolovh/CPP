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

unique_ptr<vector<shared_ptr<Test>>> make() {
    unique_ptr<vector<shared_ptr<Test>>> unique_pointer = make_unique<vector<shared_ptr<Test>>>();
    return unique_pointer;
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    for (int i = 0; i < num; i++) {
        int current_num {0};
        cout << "Please enter number " << i + 1 << ": ";
        cin >> current_num;
        vec.push_back(make_shared<Test>(current_num));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    for (auto elem: vec)
        cout << elem->get_data() << endl;
}

int main() {
    
}


// unique pointer that points to a vector of shared pointers to Test object; no new's or delete's ( make_shared )