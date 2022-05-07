// Property Proxy
#include <iostream>

template<typename T>
struct Property {
    T value;

    Property(T value) { *this = value; }

    operator T() { return value; }

    T operator=(const T &rhs) {
        std::cout << "Assignment " << std::endl;
        return value = rhs;
    }

};

struct Creature {
    Property<int> strength{10};
    Property<int> agility{5};
};

int main() {
    Creature c;
    c.strength = 10;
    c.agility = 5;
};