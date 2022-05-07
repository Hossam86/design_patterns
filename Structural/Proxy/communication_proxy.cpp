#include <string>
#include <iostream>
// this simple example but it is not sufficient so, we should experiment with rest sdk

struct Pingable {
    virtual std::string ping(const std::string &meesage) = 0;
};

struct Pong : Pingable {
    std::string ping(const std::string &meesage) override {
        return std::string(meesage + "pong \n");
    }
};

void tryit(Pingable &pp) {
    std::cout << pp.ping("ping ");
}

int main() {
    Pong pp;
    tryit(pp);
}