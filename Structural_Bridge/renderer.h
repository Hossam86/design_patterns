// Supposed we have two different shapes - Circle, Square,
// and we want to renderer them with two different methods (Raster- Vector)
// this end up with 2x2 variation for renderers  RasterCircularRender, RasterSquareRender, VectorCircleRenderer,
// this called cartesian explosion problem

#ifndef DESIGN_PATTERNS_RENDERER_H
#define DESIGN_PATTERNS_RENDERER_H

#include <iostream>

struct Renderer {
    virtual void render_circle(float x, float y, float radius) = 0;
    virtual  void render_square(float size)=0;
};

struct VectorRenderer : Renderer {
    void render_circle(float x, float y, float radius) override;
};

struct RasterRenderer : Renderer {
    void render_circle(float x, float y, float radius) override;
};

struct Shape {
protected:
    Renderer &renderer;
public:
    Shape(Renderer &renderer) : renderer(renderer) {}

public:
    virtual void draw() = 0;

    virtual void resize(float factor) = 0;
};

struct Circle : Shape {
    Circle(Renderer &renderer, float x, float y, float radius) : Shape(renderer), x(x), y(y), radius(radius) {}

    float x, y, radius;

    void draw() override;

    void resize(float factor) override;
};

struct Square : Shape {
    float size;

    Square(Renderer &renderer, float size) : Shape(renderer), size(size) {}

    void resize(float factor) override;

    void draw() override;
};

#endif //DESIGN_PATTERNS_RENDERER_H
