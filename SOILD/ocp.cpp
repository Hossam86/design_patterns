#include <iostream>
#include <vector>
using namespace std;

enum class Color
{
    RED,
    GREEN,
    BLUE
};
enum class Size
{
    SMALL,
    MEDUIM,
    LARGE
};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    typedef vector<Product *> Items;
    Items by_color(Items &items, Color &c);
    Items by_size(Items items, const Size size);
};

ProductFilter::Items ProductFilter::by_color(Items &items, Color &c)
{
    Items result;
    for (auto &i : items)
    {
        if (i->color == c)
            result.push_back(i);
    }
    return result;
}
ProductFilter::Items by_size(ProductFilter::Items items, const Size size)
{
    ProductFilter::Items result;
    for (auto &i : items)
        if (i->size == size)
            result.push_back(i);
    return result;
}

ProductFilter::Items by_size_and_color(ProductFilter::Items items, const Size size, const Color color)
{
    ProductFilter::Items result;
    for (auto &i : items)
        if (i->size == size && i->color == color)
            result.push_back(i);
    return result;
};

template <class T>
struct Specification
{
    virtual bool is_satisfied(T *item) = 0;
};

template <class T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> &items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> &items, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (auto &i : items)
        {
            if (spec.is_satisfied(i))
                result.push_back(i);
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    explicit ColorSpecification(Color c) : color(c) {}

    bool is_satisfied(Product *item)
    {
        if (item->color == color)
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Product apple{"Apple", Color::GREEN, Size::SMALL};
    Product tree{"Tree", Color::GREEN, Size::LARGE};
    Product house{"House", Color::BLUE, Size::LARGE};

    vector<Product *> all{&apple, &tree, &house};
    BetterFilter bf;
    ColorSpecification spec(Color::GREEN);
    auto filtered = bf.filter(all, spec);
    for (auto &i : filtered)
    {
        cout << i->name << endl;
    }

    return 0;
}
