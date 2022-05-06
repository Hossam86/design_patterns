
#ifndef DESIGN_PATTERNS_FOO_H
#define DESIGN_PATTERNS_FOO_H

#include "pimpl.h"

class Foo {
    class impl;

    pimpl<impl> impl;
};


#endif //DESIGN_PATTERNS_FOO_H
