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

    void resize(float factor) { radius *= factor; }

    std::string str() const override {
        std::ostringstream oss;
        oss << " A Circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape {
    float side;

    Square(float side) : side(side) {}

    void resize(float factor) { side *= factor; }

    std::string str() const override {
        std::ostringstream oss;
        oss << " A Square of radius " << side;
        return oss.str();
    }
};

struct ColoredShape : Shape {
    Shape &shape;
    std::string color;

    ColoredShape(Shape &shape, const std::string &color) : shape(shape), color(color) {}

    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has the the color " << color;
        return oss.str();
    }
};

struct TransparentShape : Shape {
    Shape &shape;
    uint8_t transperency;

    TransparentShape(Shape &shape, uint8_t transperency) : shape(shape), transperency(transperency) {}

    std::string str() const override {
        std::ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transperency) / 255.f * 100.f << "% transperency";
        return oss.str();
    }

};
// Static Decorator
//  - Mixing inheritance
//  - Perfect forward

template<typename T>
concept IsAShape= std::is_base_of<Shape,T>::value;

template<IsAShape T>
struct ColoredShape2 : T {
    std::string color;
    ColoredShape2(){}

    template<typename ...Args>
    ColoredShape2(const std::string &color, Args ...args):T(std::forward<Args>(args)...),color(color){}

    std::string str()  const override
    {
        std::ostringstream oss;
        oss<<T::str() << " has the color" << color ;
        return oss.str();
    }
};

int main() {
// Dynamic Decorator
    Circle circle{5};
    ColoredShape red_circle{circle, "red"};
    std::cout << red_circle.str() << std::endl;
    TransparentShape my_circle{red_circle, 51};
    std::cout << my_circle.str() << std::endl;


    // Static Decorator
    ColoredShape2<Circle> green_circle{"green",5};
    std::cout <<green_circle.str() <<std::endl;


}