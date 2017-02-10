#ifndef GL_MYGL_H_
#define GL_MYGL_H_

#include <cmath>
#include <iostream>

#include "definitions.h"
#include "Pixel.h"
#include "Color.h"

void PutPixel(Pixel pixel, Color color) {
    int initialPosition = pixel.initialPosition(IMAGE_WIDTH);

    for (int i = 0; i < 4; i++) {
        FBptr[initialPosition++] = color.rgba[i];
    }
}

void DrawLine(Pixel initialPosition, Pixel finalPosition) {
}

void DrawCanvas(int pixelSpread) {
    int initialCrosshair = IMAGE_WIDTH/2 - 50;
    int finalCrosshair   = IMAGE_WIDTH/2 + 50;

    for (int i = 0; i < IMAGE_WIDTH; i++) {
		PutPixel(Pixel(i, 0), Color(0 ,255,0 ,255));
		PutPixel(Pixel(i, IMAGE_HEIGHT-1), Color(0 ,255,0 ,255));
		PutPixel(Pixel(i, IMAGE_HEIGHT/2), (i % pixelSpread == 0 ? (i > initialCrosshair && i < finalCrosshair ? Color(255, 0 ,0 ,255) :  Color(255, 255, 0, 255)) : Color()));
	}
	for (int i = 1; i < IMAGE_HEIGHT - 1; i++) {
		PutPixel(Pixel(IMAGE_HEIGHT-1, i), Color(0 ,255,0 ,255));
		PutPixel(Pixel(0, i), Color(0 ,255,0 ,255));
		PutPixel(Pixel(IMAGE_WIDTH/2, i), (i % pixelSpread == 0 ? (i > initialCrosshair && i < finalCrosshair ? Color(255, 0 ,0 ,255) :  Color(255, 255, 0, 255)) : Color()));
	}
}
#endif // GL_MYGL_H_
