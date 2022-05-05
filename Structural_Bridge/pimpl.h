#include <memory>

#ifndef DESIGN_PATTERNS_PIMPL_H
#define DESIGN_PATTERNS_PIMPL_H

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
