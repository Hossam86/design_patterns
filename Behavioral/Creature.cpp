
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

// chain of responsibility pattern:  different elements of system who can process message one after another
// example we have a computer game where each creature has a name and two characteristics value as following:

struct Creature {
    string name;
    int attack, defense;

    Creature(const string &name, int attack, int defense) : name(name), attack(attack), defense(defense) {}

    friend ostream &operator<<(ostream &os, const Creature &creature) {
        os << "name: " << creature.name << " attack: " << creature.attack << " defense: " << creature.defense;
        return os;
    }
};

// Now, as the creature progresses through the game, it might come up to an item (e.g., a magic sword), or it might end
// up getting enchanted. In either case, its attack and defense values will be modified by something we’ll call
// a CreatureModifier. Furthermore, situations where several modifiers are applied are not uncommon, so we need to be
// able to stack modifiers on top of a creature, allowing them to be applied in the order they were attached.
// Let’s see how we can implement this

// Classic chain of responsibility [COR]


struct CreatureModifier {
private:
    CreatureModifier *next;
protected:
    Creature &creature;
public:

    void add(CreatureModifier *m) {
        if (next != nullptr)
            next->add(m);
        else
            next = m;
    }

    virtual void handle() {
        if (next)
            next->handle();
    }

    CreatureModifier(Creature &creature) : creature(creature) {
        next = nullptr;
    }
};

// So far, all we have is an implementation of append-only singly linked list.
// But when we start inheriting from it, things will hopefully become clearer.
// For example, here is how you would make a modifier that would double the creature’s attack value:

struct DoubleAttackModifier : CreatureModifier {
    DoubleAttackModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        creature.attack *= 2;
        CreatureModifier::handle();
    }
};


struct IncreaseDenseModifier : CreatureModifier {
    IncreaseDenseModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        if (creature.attack <= 2) {
            creature.defense += 1;
            CreatureModifier::handle();
        }
    }
};

int main() {
    Creature goblin{" goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r2{goblin};
    IncreaseDenseModifier r3{goblin};


    root.add(&r1);
    root.add(&r2);
    root.add(&r3);

    root.handle();

    std::cout << goblin << std::endl;
}
