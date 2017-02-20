#ifndef GL_COLOR_H
#define GL_COLOR_H

#include <iostream>

struct Color {
    unsigned char rgba[4];

    Color(const unsigned char R = 0, const unsigned char G = 0, const unsigned char B = 0, const unsigned char A = 0);

    Color& operator+=(const Color& other);

    void represent(void);

    Color& add(double* ar);
};

#endif //GL_COLOR_H
