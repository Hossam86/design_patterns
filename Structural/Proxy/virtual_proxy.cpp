#include <iostream>

struct Image {
    virtual void draw() = 0;
};

struct Bitmap : Image {
public:
    Bitmap(const std::string &filename) : filename(filename) {
        std::cout <<" loading a bitmap from file " << filename <<std::endl;
    }

    void draw() override {
        std::cout << " Drawing a bit Map " << std::endl;
    }
private:
    std::string filename;
};

// Imagine you can't to change the bitmap class for any reason, However. you need change some functionality
struct  LazyBitmap :Image
{
    void draw() override {
        if (!bmp)
        {
            bmp=new Bitmap(filename);
            bmp->draw();
        }
    }

private:
    Bitmap* bmp;
    std::string filename;
};

int main() {
    Bitmap img("nature.png");
    img.draw();
    LazyBitmap img2("nature.png");
    img2.draw();
}
