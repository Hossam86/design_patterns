#include <cmath>

struct Point1
{
    float x, y;
    // constructor for point in cartesian coordinates

    Point1(const float x, const float y) : x(x), y(y) {}
    // Problem-> what about if you to initialize point with polar coordinates
    // unfortunately you can't have two constructor with same argument types
    // Point(const float r, const float theta)
    // {
    //     x = r * cos(theta);
    //     y = r * sin(theta);
    // }
};
// first solution for above problem is to intriduce enumeration

enum class PointType
{
    CARTESIAN,
    POLAR
};
struct Point2
{
    float x, y;
    // Problem: names of argument loss the meaning
    Point2(const float a, const float b, PointType type)
    {
        if (type == PointType::CARTESIAN)
        {
            this->x = a;
            this->y = b;
        }
        if (type == PointType::POLAR)
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }
};
// to solve the above problem we will introduce the factory pattern
struct Point3
{
    float x, y;

protected:
    // private constructor because we don't want any one call it
    Point3(const float x, const float y) : x(x), y(y) {}

public:
    static Point3 NewCartesian(const float x, const float y)
    {
        return {x, y};
    }
    static Point3 NewPolar(const float r, const float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

// juust like with builder, we can take all the Point creation functions out into
// into separate class

struct Point4
{
    float x, y;
    // friend to access class private constructor
    friend class PointFactory;

private:
    Point4(float x, float y) : x(x), y(y) {}
};

struct PointFactory
{
    static Point4 NewCartesian(const float x, const float y)
    {
        return {x, y};
    }
    static Point4 NewPolar(const float r, const float theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }
};

int main(int argc, char const *argv[])
{
    auto p3 = Point3::NewPolar(5, M_PI_4);
    auto P4 = PointFactory::NewCartesian(3, 4);
    return 0;
}
