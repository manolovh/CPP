#include <iostream>

// unscoped enums

enum State {Engine_Failure, Inclement_Weather, Nominal}; // implicit initialization (0, 1, 2)
enum Sequence {Abort = 3, Hold = 4, Launch = 5}; // explicti initialization (3, 4, 5)
enum Names {Pesho = 0, Gosho, Pepi}; // Explicit/Implicit initialization (0, 1, 2)

void initiate(Sequence seq) {
    std::cout << "Initiated " << seq << std::endl;
}

std::ostream &operator<<(std::ostream &os, State state_elem) {
    switch (state_elem) {
        case Engine_Failure:
            os << "Engine Failure"; break;
        case Inclement_Weather:
            os << "Inclement Weather"; break;
        case Nominal:
            os << "Nominal"; break;
        default:
            os << "Invalid state";
    }
    return os;
}

void unscoped() {
    State state {Nominal};
    std::cout << state << std::endl;

    if (state == Engine_Failure)
        initiate(Abort);
    else if (state == Inclement_Weather)
        initiate(Hold);
    else if (state == Nominal)
        initiate(Launch);
}

// scoped enums

enum class Whale {Blue, Beluga, Gray};

enum class Item : long {Milk = 250, Bread = 150, Apple = 130};

void scoped() {
    Whale whale = Whale::Beluga;

    if (whale == Whale::Blue)
        std::cout << "Blue Whale" << std::endl;
    else if (whale == Whale::Beluga)
        std::cout << "Beluga Whale" << std::endl;
    else if (whale == Whale::Gray)
        std::cout << "Gray Whale" << std::endl;

    long milk_code = static_cast<long>(Item::Milk);
    int total = int(Item::Milk) + static_cast<int>(Item::Bread); // unscoped enum values are not implicitly convertable
    std::cout << sizeof total << ", " << sizeof milk_code;
}

int main() {
    scoped();

    return 0;
}