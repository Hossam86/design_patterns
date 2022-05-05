
#include "pimpl.h"

template<class T>
pimpl<T>::pimpl():impl(new T{}) {}

template<class T>
pimpl<T>::~pimpl() {}

template<class T>
template<class ...Args>
pimpl<T>::pimpl(Args &&...args) : impl(new T{std::forward<Args>(args)...}) {}


template<class T>
T &pimpl<T>::operator*() {
    return impl.get();
}

template<class T>
T *pimpl<T>::operator->() {
    return *impl.get();
}

