// Flyweight: Space Optimization Technique that lets us use less memory
// by storing externally the data associated with similar objects
// Note - not completed because it needs boost lib for bidirectional map

#include <iostream>
#include <map>

typedef uint8_t key;

struct User {
private:
    key first_name, second_name;
    static std::map<key, std::string> names;
    static key seed;

    static key add(const std::string &name) {
        auto it = names.righ(name);
    }
};

int main() {
    return 0;
}