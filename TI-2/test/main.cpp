#include <iostream>
#include "Scale.h"

void print(Matrix* matrix) {
    std::cout << matrix->toString() << std::endl;
}

int main(void) {
    Scale* m = new Scale(3,3);
    m->xFactor(2.0);
    Scale* n = new Scale(3,3);
    n->xFactor(3.0)->yFactor(4.0)->zFactor(5.0);

    print(m);
    print(n);

    Scale* s = (Scale*)m->multiply(n);

    print(s);
    return 0;
}
