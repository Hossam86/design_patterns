#include "renderer.h"

int main() {
    VectorRenderer vectorRenderer;
    Circle vector_circle{vectorRenderer, 0, 0, 5};
    vector_circle.draw();
}