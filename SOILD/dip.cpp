#include <string>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct Person
{
    string name;
};

enum class RelationShip
{
    PARENT,
    CHILD,
    SLIBING
};
struct RelationShipsBrowser
{
    virtual vector<Person> find_all_child_of(const string &name) = 0;
};
struct RelationShips : RelationShipsBrowser // low level module
{
    vector<tuple<Person, RelationShip, Person>> relations;
    // API
    void add_parent_and_child(Person &parent, Person &child)
    {
        relations.push_back({parent, RelationShip::PARENT, child});
        relations.push_back({child, RelationShip::CHILD, parent});
    }
    vector<Person> find_all_child_of(const string &parent) override
    {
        vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == "Samir" && rel == RelationShip::PARENT)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research
{
    Research(RelationShipsBrowser &rs)
    {
        for (auto &child : rs.find_all_child_of("Samir"))
        {
            cout << "Samir has a child called " << child.name << endl;
        }
    };
};

int main(int argc, char const *argv[])
{
    Person parent{"Samir"};
    Person child1{"Hossam"};
    Person child2{"Mna"};

    RelationShips rs{};
    rs.add_parent_and_child(parent, child1);
    rs.add_parent_and_child(parent, child2);
    Research _(rs);

    return 0;
}
