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

    if (xDistance < 0) {
        xInitialIncrement = -1;
        xFinalIncrement   = -1;
    } else if (xDistance > 0) {
        xInitialIncrement =  1;
        xFinalIncrement   =  1;
    }
    if (yDistance < 0) {
        yInitialIncrement = -1;
    } else if (yDistance > 0) {
        yInitialIncrement =  1;
    }

    if (fAxis < sAxis) {
        std::swap(fAxis, sAxis);
        if (yDistance < 0) {
            yFinalIncrement = -1;
        } else if (yDistance > 0) {
            yFinalIncrement =  1;
        }
        xFinalIncrement = 0;
    }

    int baseDistance = fAxis << 1;

    Color interpolatedColor = initialVertex.color;
    std::cout << "R - " << (int)(initialVertex.color.rgba[0] - finalVertex.color.rgba[0]) << std::endl;
    std::cout << "G - " << (int)(initialVertex.color.rgba[1] - finalVertex.color.rgba[1]) << std::endl;
    std::cout << "B - " << (int)(initialVertex.color.rgba[2] - finalVertex.color.rgba[2]) << std::endl;
    std::cout << "A - " << (int)(initialVertex.color.rgba[3] - finalVertex.color.rgba[3]) << std::endl;
    std::cout << "\nAxis " << fAxis << std::endl;
    std::cout << "\nR - " << (int)(initialVertex.color.rgba[0] - finalVertex.color.rgba[0])/fAxis << std::endl;
    std::cout << "G - " << (int)(initialVertex.color.rgba[1] - finalVertex.color.rgba[1])/fAxis << std::endl;
    std::cout << "B - " << (int)(initialVertex.color.rgba[2] - finalVertex.color.rgba[2])/fAxis << std::endl;
    std::cout << "A - " << (int)(initialVertex.color.rgba[3] - finalVertex.color.rgba[3])/fAxis << std::endl;



    Color colorIncrement((unsigned char)(finalVertex.color.rgba[0] - initialVertex.color.rgba[0])/fAxis,
                         (unsigned char)(finalVertex.color.rgba[1] - initialVertex.color.rgba[1])/fAxis,
                         (unsigned char)(finalVertex.color.rgba[2] - initialVertex.color.rgba[2])/fAxis,
                         (unsigned char)(finalVertex.color.rgba[3] - initialVertex.color.rgba[3])/fAxis);

    for (int i = 0; i <= fAxis; ++i) {
        PutPixel(Vertex(currentX, currentY, interpolatedColor));
        
        interpolatedColor += colorIncrement;

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
