// why : --> Imagine you want to hide the detail of Implementation to be not exposed in class header file
//     : --> minimizes compilation time and helps programmers to reduce build dependencies.
// what: Decouple interface from implementation
// How : moving the private data/methods members in a separate class and access it through pointer
#include <string>
#include <iostream>
#ifndef DESIGN_PATTERNS_PERSON_H
#define DESIGN_PATTERNS_PERSON_H

using  namespace std;
class Person {
public:
    Person(const string &name);
    virtual ~Person();
    void greet();
    class PersonImp;
    PersonImp *imp;
private:
    string name;
};


#endif //DESIGN_PATTERNS_PERSON_H
