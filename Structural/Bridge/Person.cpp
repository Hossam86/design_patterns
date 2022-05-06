#include "Person.h"

class Person::PersonImp {
public:
    void greet(Person *p);
};

void Person::PersonImp::greet(Person *p) {
    cout << " hello my name is " << p->name << endl;
}

Person::Person(const string &name) :name(name),imp(new PersonImp) {

}

Person::~Person() {
    delete imp;
}

void Person::greet() {
imp->greet(this);
}

