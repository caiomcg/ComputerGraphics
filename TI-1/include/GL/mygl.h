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
    int yInitialIncrement = 0;
    int yFinalIncrement   = 0;
    int xInitialIncrement = 0;
    int xFinalIncrement   = 0;

    int xDistance    = finalVertex.x - initialVertex.x;
    int yDistance    = finalVertex.y - initialVertex.y;

    int fAxis      = std::abs(xDistance);
    int sAxis      = std::abs(yDistance);

    int currentY     = initialVertex.y;
    int currentX     = initialVertex.x;

    xInitialIncrement = xFinalIncrement = (xDistance < 0 ? -1 : (xDistance > 0 ? 1 : 0));
    yInitialIncrement = (yDistance < 0 ? -1 : (yDistance > 0 ? 1 : 0));

    if (fAxis < sAxis) {
        std::swap(fAxis, sAxis);
        yFinalIncrement = (yDistance < 0 ? -1 : (yDistance > 0 ? 1 : 0));
        xFinalIncrement = 0;
    }

    int baseDistance = fAxis << 1;

    Color interpolatedColor = initialVertex.color;


    double variance[4] = {(double)(finalVertex.color.rgba[0] - initialVertex.color.rgba[0])/fAxis,
                         (double)(finalVertex.color.rgba[1] - initialVertex.color.rgba[1])/fAxis,
                         (double)(finalVertex.color.rgba[2] - initialVertex.color.rgba[2])/fAxis,
                         (double)(finalVertex.color.rgba[3] - initialVertex.color.rgba[3])/fAxis};

    double newColor[4] = {(double)initialVertex.color.rgba[0],
                          (double)initialVertex.color.rgba[1],
                          (double)initialVertex.color.rgba[2],
                          (double)initialVertex.color.rgba[3]};

    for (int i = 0; i <= fAxis; ++i) {
        PutPixel(Vertex(currentX, currentY, Color().add(newColor)));

        newColor[0] += variance[0];
        newColor[1] += variance[1];
        newColor[2] += variance[2];
        newColor[3] += variance[3];

        baseDistance += sAxis;

        if (baseDistance <= fAxis) {
            currentX += xFinalIncrement;
            currentY += yFinalIncrement;
        } else {
            baseDistance -= fAxis;
            currentX += xInitialIncrement;
            currentY += yInitialIncrement;
        }
    }
}

void DrawTriangle(Vertex fVertex, Vertex sVertex, Vertex tVertex) {
    DrawLine(fVertex, sVertex);
    DrawLine(sVertex, tVertex);
    DrawLine(tVertex, fVertex);
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
