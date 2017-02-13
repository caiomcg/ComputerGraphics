#ifndef GL_MYGL_H_
#define GL_MYGL_H_

#include <cmath>
#include <iostream>

#include "definitions.h"
#include "Vertex.h"
#include "Color.h"

void PutPixel(Vertex vertex) {
    if (vertex.isValid())  {
        int initialPosition = vertex.initialPosition();

        for (int i = 0; i < 4; i++) {
            FBptr[initialPosition++] = vertex.color.rgba[i];
        }
    } else {
        std::cerr << "Coordinates " << vertex.x << " and " << vertex.y << " are out of bounds\n";
    }
}

void DrawLine(Vertex initialVertex, Vertex finalVertex) {
    int xDistance    = finalVertex.x - initialVertex.x;
    int yDistance    = finalVertex.y - initialVertex.y;

    int currentY     = initialVertex.y;
    int baseDistance = (yDistance << 1) - xDistance;

    int eIncrement   = (yDistance << 1);
    int seIncrement  = (yDistance - xDistance) << 1;

    PutPixel(Vertex(initialVertex.x, currentY, initialVertex.color));

    for (int currentX = initialVertex.x + 1; currentX <= finalVertex.x; currentX++) {
        if (baseDistance <= 0) {
            baseDistance += eIncrement;
        } else {
            currentY++;
            baseDistance += seIncrement;
        }
        PutPixel(Vertex(currentX, currentY, initialVertex.color));
    }
}

void DrawCanvas(int vertexSpread) {
    int initialCrosshair = IMAGE_WIDTH/2 - 50;
    int finalCrosshair   = IMAGE_WIDTH/2 + 50;

    for (int i = 0; i < IMAGE_WIDTH; i++) {
		PutPixel(Vertex(i, 0, Color(0 ,255,0 ,255)));
		PutPixel(Vertex(i, IMAGE_HEIGHT-1, Color(0 ,255,0 ,255)));
		PutPixel(Vertex(i, IMAGE_HEIGHT/2, (i % vertexSpread == 0 ? (i > initialCrosshair && i < finalCrosshair ? Color(255, 0 ,0 ,255) :  Color(255, 255, 0, 255)) : Color())));
	}
	for (int i = 1; i < IMAGE_HEIGHT - 1; i++) {
		PutPixel(Vertex(IMAGE_HEIGHT-1, i, Color(0 ,255,0 ,255)));
		PutPixel(Vertex(0, i, Color(0 ,255,0 ,255)));
		PutPixel(Vertex(IMAGE_WIDTH/2, i,  (i % vertexSpread == 0 ? (i > initialCrosshair && i < finalCrosshair ? Color(255, 0 ,0 ,255) :  Color(255, 255, 0, 255)) : Color())));
	}
}
#endif // GL_MYGL_H_
