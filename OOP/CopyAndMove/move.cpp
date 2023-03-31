#include <iostream>
#include <string>
#include <vector>
#include "Move.h"

using namespace std;

int Move2::num_players = 0;

int Move2::get_num_players() {
    return num_players;
}

Move2::get_data() const {
    return *data;
}

Move2::Move2(int d) {
    data = new int;
    *data = d;
    ++num_players;
    cout << "Constructor called" << endl;
    }

Move2::Move2(const Move2 &source)
    : Move2(*source.data) {
        cout << "Deep copy constructor called" << endl;
    }

Move2::Move2(Move2 &&source) noexcept
    : data{source.data} {
        source.data = nullptr;
        cout << "Move constructor called" << endl;
    }

Move2::~Move2() {
    if (this->data != nullptr)
        --num_players;
    delete data;
    cout << "Destructor called" << endl;
}

int main() {
    vector<Move2> vec;

    vec.push_back(Move2{1});
    vec.push_back(Move2{2});
    vec.push_back(Move2{3});
    vec.push_back(Move2{4});
    vec.push_back(Move2{5});
    vec.push_back(Move2{6});

    cout << "Object count: " << Move2::get_num_players() << endl;

    const Move2 move{2};
    cout << move.get_data() << endl;
}