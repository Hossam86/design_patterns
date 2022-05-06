
#include <iostream>
#include <map>
using namespace std;
// suppose you are working at a café that serves tea and coffee.
// These two hot beverages are made through entirely different apparatus that we can both model as factories, of sorts.Tea and coffee can actually be served both hot or hold, but let’s focus on the hot variety
struct HotDrink
{
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << endl;
    }
};
struct Coffe : HotDrink
{
    void prepare(int volume) override
    {
        cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << endl;
    }
};

unique_ptr<HotDrink> make_drink(string type)
{
    unique_ptr<HotDrink> drink;
    if (type == "tea")
    {
        drink = make_unique<Tea>();
        drink->prepare(200);
    }
    else
    {
        drink = make_unique<Coffe>();
        drink->prepare(200);
    }
    return drink;
}

// Now, remember, different drinks are made by different machinery.
struct HotDrinkFactory
{
    virtual unique_ptr<HotDrink> make() const = 0;
};
struct TeaFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Coffe>();
    }
};
struct CoffeFactory : HotDrinkFactory
{
    unique_ptr<HotDrink> make() const override
    {
        return make_unique<Tea>();
    }
};

// Now, suppose we want to define a higher level interface for making
// different drinks, hot or cold. We could make a type called DrinkFactory
// that would itself contain references to the various factories
// that are available:
class DrinkFactory
{
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory()
    {
        hot_factories["coffee"] = make_unique<CoffeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string &name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
