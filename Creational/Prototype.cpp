// motivation
// iterate existing design to not be created from scratch
// we make a clone the prototype
#include <iostream>

using namespace std;

struct Address {
    string street, city;
    int suit;

    Address(const string &street, const string &city, int suit) : street(street), city(city), suit(suit) {}

    Address(const Address &other) : street(other.street), city(other.city), suit(other.suit) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        os << "street: " << address.street << " city: " << address.city << " suit: " << address.suit;
        return os;
    }

};

struct Contact {
    string name;
    Address address;

    Contact(const string &name, const Address &address) : name(name), address(address) {}

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        os << "name: " << contact.name << " address: " << contact.address;
        return os;
    }
};

// default shallow copy constructor
struct Contact2 {
    string name;
    Address *address;

    Contact2(const string &name, Address *address) : name(name), address(address) {}

    friend ostream &operator<<(ostream &os, const Contact2 &contact2) {
        os << "name: " << contact2.name << " address: " << *contact2.address;
        return os;
    }
};


// deep copy constructor
struct Contact3 {
    string name;
    Address *address;

    Contact3(const string &name, Address *address) : name(name), address(address) {}

    Contact3(const Contact3 &other) : name(other.name), address(new Address{*other.address}) {}

    ~Contact3() { delete address; }

    friend ostream &operator<<(ostream &os, const Contact3 &contact3) {
        os << "name: " << contact3.name << " address: " << *contact3.address;
        return os;
    }
};

struct EmployeeFactory {
    static unique_ptr<Contact3> new_main_office_employee(const string &name, const int suite) {
        static Contact3 p{"", new Address{" 7th District", "Cairo", 0}};
        return new_employee(name, suite, p);
    }

private:
    static unique_ptr<Contact3> new_employee(const string &name, const int suite, const Contact3 &prototype) {
        auto result = make_unique<Contact3>(prototype);
        result->name = name;
        result->address->suit = suite;
        return result;
    }

};

int main() {
//    Contact Hossam{"Hossam", Address{"123 7th district", "Cairo", 123}};
//    Contact Samir {"Samir", Address{"123 7th district", "Giza", 321}};
    Contact3 Hossam{"Hossam", new Address{"123 7th district", "Cairo", 123}};

    Contact3 Samir = Hossam;
    Samir.name = "Samir";
    Samir.address->suit = 321;
    cout << Hossam << endl;
    cout << Samir << endl;

    auto Seif= EmployeeFactory::new_main_office_employee("seif", 123);
    cout << *Seif<<endl;
}