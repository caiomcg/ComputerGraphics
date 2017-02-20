#include "Color.h"

Color::Color(const unsigned char R, const unsigned char G, const unsigned char B, const unsigned char A) {
    rgba[0] = R;
    rgba[1] = G;
    rgba[2] = B;
    rgba[3] = A;
}

Color& Color::operator+=(const Color& other) {
    if (this != &other) { // self-assignment check expected
        this->rgba[0] += other.rgba[0];
        this->rgba[1] += other.rgba[1];
        this->rgba[2] += other.rgba[2];
        this->rgba[3] += other.rgba[3];
    }
    return *this;
}

void Color::represent(void) {
    std::cout << "R - " << (int)rgba[0] << std::endl;
    std::cout << "G - " << (int)rgba[1] << std::endl;
    std::cout << "B - " << (int)rgba[2] << std::endl;
    std::cout << "A - " << (int)rgba[3] << std::endl;

}
