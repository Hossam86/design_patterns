// This is shrink wrap implementation for using as template for bridge pattern
#ifndef DESIGN_PATTERNS_PIMPL_H
#define DESIGN_PATTERNS_PIMPL_H
#include <memory>

template<class T>
class pimpl {
private:
    std::unique_ptr<T> impl;
public:
    pimpl();

    ~pimpl();

    template<typename ...Args>
    pimpl(Args &&...args);

    T *operator->();

    T &operator*();
};

#endif //DESIGN_PATTERNS_PIMPL_H
