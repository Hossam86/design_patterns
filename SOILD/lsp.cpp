#include <iostream>
using namespace std;
class Rectangle
{
protected:
    int width;
    int height;

public:
    Rectangle(int width, int height) : width(width), height(height) {}
    virtual void set_width(int width) { this->width = width; };
    virtual void set_height(int height) { this->height = height; };
    int get_height() { return height; };
    int get_width() { return width; };
    int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}
    void set_width(int width) override { this->width = height = width; }
    void set_height(int height) override { this->height = width = height; }
};

void process(Rectangle &r)
{
    int w = r.get_width();
    r.set_height(10);
    cout << "epected area  = " << w * 10 << ", got " << r.area() << endl;
}

int main()
{
    Rectangle r{5, 5};
    process(r);

    Square s{5};
    process(s);
    return 0;
}