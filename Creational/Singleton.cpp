
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// What --> Prevent object construction more than once.
// Why  --> Components that needs to instantiated only once like database repo, object factory
// How  --> Idea is hide the object constructor and delete the copy constructor and assigment operator and
//      --> add get method return static instance of the object

struct SingleDataBase {
private:
    SingleDataBase() {
        cout << "initializing Database" << endl;
        ifstream ifs("/Users/hossamsamir/Projects/design_patterns/capitals.txt.txt");
        string s, s2;
        while (getline(ifs, s)) {
            getline(ifs, s2);
            auto pop = stoi(s2);
            this->Capitals[s] = pop;
        }
    }

    map<string, int> Capitals;

public:
    SingleDataBase(const SingleDataBase &other) = delete;
    void operator=(const SingleDataBase &rhs) = delete;

    static SingleDataBase &get() {
        static SingleDataBase db;
        return db;
    }

    int get_population(const string &country) { return this->Capitals[country]; }
};

int main(int argc, char const *argv[]) {
    SingleDataBase::get();
    string city = "Cairo";
    cout << city << " has population " << SingleDataBase::get().get_population(city) << endl;
    return 0;
}