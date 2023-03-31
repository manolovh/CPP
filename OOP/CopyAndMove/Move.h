#ifndef _MOVE_H_
#define _MOVE_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Move2 {
private:
    int *data;
    static int num_players;
public:
    static int get_num_players();
    int get_data() const; // add const in order to access const objects
    void set_data(int d) {*data = d;}
    Move2(int d); // Constr
    Move2(const Move2 &source); // Deep copy constr
    Move2(Move2 &&source) noexcept; // Move constr
    ~Move2(); // Destr
};

#endif