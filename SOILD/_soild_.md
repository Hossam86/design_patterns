# The SOLID Design Principles

SOLID is a popular set of design principles that are used in object-oriented software development. SOLID is an acronym that stands for five key design principles: single responsibility principle, open-closed principle, Liskov substitution principle, interface segregation principle, and dependency inversion principle.

The principles were developed originally by Robert C. Martin in 2000. Martin states that successful software will change and develop over time. As it changes, it becomes increasingly complex, rigid, and vicious if it doesn't have good design . So The principles were developed to avoid these problematic Issues.

1. Single Responsibility Principle (SRP)
2. Open-Closed Principle (OCP)
3. Liskov Substitution Principle (LSP)
4. Interface Segregation Principle (ISP)
5. Dependency Inversion Principle (DIP)

## Single Responsibility Principle (SRP)

### states that each class has only one responsibility, and therefore has only one reason to change

in Example srp.cpp, suppose you decide to keep your journal, simply we have a class with a constructor and member function to add entries
now suppose you decide to make the journal persist by saving it in a file. if we do it as a member function this will be problematic because any change in the persistence approach( cloud instead of a file, ..etc) would require a lot of tiny changes in affected classes

"an architecture that leads you to have to do lots of tiny changes in lost of classes, whether related (as in a hierarchy) or not, is typically a code smell "

## Open Closed Principle (OCP)

### states that a type is open for extension but closed for modification.

In other words, want to provide certain filtering capabilities for a given set of products. example (ocp.cpp)

We make a filter say for color, but unfortunately, sometimes new requirements come in and ask us to implement filtering by size, or combination between size and color. So we jump back to the code and add a new member function to do that. this feels like duplication and may be problematic.

1. perhaps in a different compilation unit
2. recompiling something that already works and may have been shipped to clients

Why don’t we just write a general method and take the filtering function as an argument? The open-Closed Principle states that a type is open for extension but closed for modification.
In other words, we want extensible filtering without having to modify it.

HOW?
we conceptually separate our filtering process into two parts

1. filter (a process that takes all items and returns some )
2. specification definition of a function that will apply to the data

## Liskov Substitution Principle

subtypes should be a substitution with base type
in other words, if the interface takes an object of type parent, it should equally take a child without breaking anything

## Interface Segregation Principle

the idea here is to segregate parts of a complicated interface into separate parts to avoid forcing implementors to implement something they don't need.

## Dependency Inversion Principle

High-level modules should not depend on low-level modules. Both should depend on abstractions.
Simply we can say dependencies on interfaces or base classes are better than dependencies on concrete types.

## Summery

Implementing SOLID design principles during development will lead to systems that are more maintainable, scalable, testable, and reusable.
