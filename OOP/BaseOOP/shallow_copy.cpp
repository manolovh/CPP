#include <iostream> // cin/cout
#include <string> // string

using namespace std;

class Shallow {
public:
    int *data;

    void set_data(int d) {*data = d;}
    int get_data() {return *data;}

    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    : data(source.data) {
    }

Shallow::~Shallow() {
    delete data;
}

void display_shallow(Shallow obj) {
    cout << obj.get_data() << endl;
}

int main() {
    Shallow obj1 {10};
    display_shallow(obj1);
    
    Shallow obj2 {obj1};
    obj2.set_data(200);
    return 0;
}