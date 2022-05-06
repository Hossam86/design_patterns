
#include "renderer.h"

void VectorRenderer::render_circle(float x, float y, float radius) {
    std::cout << " Drawing a vector circle of radius" << radius << std::endl;
}

void RasterRenderer::render_circle(float x, float y, float radius) {
    std::cout << "Rasterizing a circle of radius" << radius << std::endl;
}

void Circle::draw() {
    renderer.render_circle(x, y, radius);
}

void Circle::resize(float factor) {
    radius *= factor;
}

void Square::draw() {
    renderer.render_circle()
}

void Square::resize(float factor) {
    size *= factor;
}
