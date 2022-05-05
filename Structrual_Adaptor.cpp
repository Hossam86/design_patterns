// Adpator Pattern
// what --> get the interface you want from the interface you have
// why -->suppose you want to keep working with geometrical objects but also need the rendering,
//          so you need to adapt your geometry to pixel-based representation.
// how --> idea to interface object do the necessary steps for the conversion
//          and also can include cache maps to cache information that not changed or any other optimization

#include <vector>

namespace geom {
    struct Point {
        int x, y;

        Point operator+(const Point &rhs) { return Point{x + rhs.x, y + rhs.y}}
    };

    struct Line {
        point start, end;
    };

    struct VectorObject {
        virtual std::vector<Line>::iterator begin() = 0;

        virtual std::vector<Line>::iterator end() = 0;
    };

    struct VectorRect : VectorObject {
        VectorRect(int x, int y, int width, int height) {
            lines.emplace_back(Line{Point{x, y}, Point{x + width, y}});
            lines.emplace_back(Line{Point{x + width, y}, Point{x + width, y + height}});
            lines.emplace_back(Line{Point{x + width, y + height}, Point{x, y + height}});
            lines.emplace_back(Line{Point{x, y + height}, Point{x + y}});
        }

        std::vector<Line>::iterator begin() override { return lines.begin(); }

        std::vector<Line>::iterator end() override { return lines.end(); }

    private:
        std::vector<Line> lines;
    };
}

//Now, here’s the set-up. Suppose we want to draw lines on screen. Rectangles,
//even! Unfortunately, we cannot, because the only interface for drawing is literally this:

void DrawPoints(CPaintDC &dc, std::vector<geom::Point>::iterator\
 start, std::vector<geom::Point>::iterator end) {
    for (auto i = start; i != end; ++i)
        dc.SetPixel(i->x, i->y, 0);
}

// So we need Adaptor to covert lines in points

struct LinePointAdaptor {
    LinePointAdaptor(const geom::Line &line) {
// TODO Line-Point conversion
    }

    virtual std::vector<geom::Point>::iterator begin() { return points.begin(); }

    virtual std::vector<geom::Point>::iterator end() { return points.end(); }

private:
    std::vector<geom::Point> points;
};

int main() {

}