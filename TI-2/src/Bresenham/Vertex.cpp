#include "Vertex.h"
#include <stdio.h>

Vertex::Vertex (int x, int y, int* RGBA) {
    this->position = new int[2];
    this->RGBA = new int[4];
    setPosition(x,y);
    setColor(RGBA);
}

Vertex::Vertex (int x, int y) {
    this->position = new int[2];
    this->RGBA = new int[4];
    setPosition(x,y);
    for (int color = 0; color < 4 ; color++)
        RGBA[color] = 255;
    setColor(RGBA);
}

Vertex::~Vertex() {
    if(position != NULL) {
        delete []position;
    }
    if(RGBA != NULL) {
        delete []RGBA;
    }
}

void Vertex::setPosition(int x, int y) {

    // if( x < 0 || x > IMAGE_WIDTH || y < 0 || y > IMAGE_HEIGHT ) {
    //     printf("Position (%d,%d)",x,y);
    //     throw std::invalid_argument( "Invalid position of the Vertex" );
    // }

    this->position[0] = x;
    this->position[1] = y;
}

void Vertex::setX(int x) {

    // if( x < 0 || x > IMAGE_WIDTH) {
    //     throw std::invalid_argument( "Invalid position of the Vertex" );
    // }

    this->position[0] = x;
}

void Vertex::setY(int y) {

    // if(y < 0 || y > IMAGE_HEIGHT ) {
    //     throw std::invalid_argument( "Invalid position of the Vertex" );
    // }

    this->position[1] = y;
}

void Vertex::setColor(int* RGBA) {

    for(int index = 0 ; index <= 3 ; index++) {
        if(RGBA[index] < 0 || RGBA[index] > 255) {
            printf("Color (%d,%d,%d)",RGBA[0],RGBA[1],RGBA[2]);
            throw std::invalid_argument( "Invalid color of the Vertex" );
        }
    }

    for(int index = 0 ; index <= 3 ; index++) {
        this->RGBA[index] = RGBA[index];
    }
}

int* Vertex::getPosition() const {
  return this->position;
}

int* Vertex::getColor() const {
  return this->RGBA;
}

int Vertex::getX() const {
  return this->position[0];
}

int Vertex::getY() const {
  return this->position[1];
}
