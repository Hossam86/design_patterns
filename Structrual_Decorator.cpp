#include <string>
#include <iostream>
#include <sstream>
// extend the object functionality
struct Shape {
    virtual std::string str() const = 0;
};

struct Circle : Shape {
    float radius;

    explicit Circle(float radius) : radius(radius) {}
    void  resize(float  factor) {radius*=factor;}
    std::string str() const override {
        std::ostringstream oss;
        oss << " A Circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape {
    float side;

    Square(float side) : side(side) {}
    void  resize(float  factor) {side*=factor;}
    std::string str() const override {
        std::ostringstream oss;
        oss << " A Square of radius " << side;
        return oss.str();
    }
};
struct  ColoredShape:Shape
{
    Shape &shape;
    std::string color;

    ColoredShape(Shape &shape, const std::string &color) : shape(shape), color(color) {}

    std::string str() const override {
        std::ostringstream oss;
        oss<<shape.str() <<" has the the color " << color;
        return oss.str();
    }
};

struct TransparentShape:Shape
{
    Shape &shape;
    uint8_t transperency;

    TransparentShape(Shape &shape, uint8_t transperency) : shape(shape), transperency(transperency) {}

    std::string str() const override {
        std::ostringstream oss;
        oss<<shape.str() << " has " << static_cast<float>(transperency) /255.f*100.f << "% transperency";
        return  oss.str();
    }

};

int main()
{
    Circle circle{5};
    ColoredShape coloredcircle{circle, "red"};
    std:: cout << coloredcircle.str() <<std::endl;

    TransparentShape my_circle {coloredcircle, 51};
    std::cout<< my_circle.str() <<std::endl;
}