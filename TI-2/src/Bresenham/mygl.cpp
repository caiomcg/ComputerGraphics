#include "mygl.h"


void PutPixel(const Vertex& px) {
    int pixelRealPosition = (px.getX()  + px.getY() * IMAGE_WIDTH) * 4;
    for (int i = 0; i <= 3; i++) {
        FBptr[pixelRealPosition + i] = (int)px.getColor()[i];
    }
}

void DrawLine(const Vertex& px1,const Vertex& px2) {

    Vertex linePosition = Vertex(px1.getX(),px1.getY());

    int gradientColor[4];

    int x = px1.getX();
    int y = px1.getY();

    int xLimit, yLimit, limit;

    int* distortedLine;
    int* straightLine;

    int xVariation, yVariation;

    float distanceXPercent, distanceYPercent;

    //Set the deltaX and deltaY limits
    if (px1.getX() > px2.getX())
        xLimit = (px1.getX() - px2.getX()) + px1.getX();
    else
        xLimit = px2.getX();

    if (px1.getY() > px2.getY())
        yLimit = (px1.getY() - px2.getY()) + px1.getY();
    else
        yLimit = px2.getY();

    xVariation = xLimit - px1.getX();
    yVariation = yLimit - px1.getY();

    if(xVariation < yVariation) {
        straightLine = &x;
        distortedLine = &y;

        int tmp = xVariation;
        xVariation = yVariation;
        yVariation = tmp;
        limit = yLimit;
    }
    else {
        straightLine = &y;
        distortedLine = &x;
        limit = xLimit;
    }

    int distortion = (2 * yVariation) - xVariation;
    int increaseStraight = 2 * yVariation;
    int increaseDistortion = 2 * (yVariation - xVariation);

    while(*distortedLine < limit) {
        if (distortion <= 0) {
            distortion += increaseStraight;
        }
        else {
            distortion += increaseDistortion;
            *straightLine += 1;
        }
        *distortedLine += 1;

        linePosition.setX(x);
        linePosition.setY(y);

        if(xLimit != px2.getX())
            linePosition.setX( px1.getX() - (linePosition.getX() - px1.getX()));
        if(yLimit != px2.getY())
            linePosition.setY( px1.getY() - (linePosition.getY() - px1.getY()));

        if(px2.getX() - px1.getX() == 0)
            distanceXPercent = 1;
        else
            distanceXPercent = (1.0-((float) (linePosition.getX() - px1.getX()) / ((float) px2.getX() - px1.getX())));
        if(px2.getY() - px1.getY() == 0)
            distanceYPercent = 1;
        else
            distanceYPercent = (1.0-((float) (linePosition.getY() - px1.getY()) / ((float) px2.getY() - px1.getY())));

        float distancePercent = xVariation <= yVariation ? distanceYPercent : distanceXPercent;

        for(int index=0 ; index<4 ; index++)
            gradientColor[index] = px1.getColor()[index] * distancePercent + px2.getColor()[index] * (1 - distancePercent);

        PutPixel(Vertex(linePosition.getX(),linePosition.getY(),gradientColor));
    }
    PutPixel(Vertex(px1.getX(),px1.getY(),px1.getColor()));
    PutPixel(Vertex(px2.getX(),px2.getY(),px2.getColor()));
}

void DrawTriangle(const Vertex& px1,const Vertex& px2,const Vertex& px3) {
    DrawLine(px1,px2);
    DrawLine(px2,px3);
    DrawLine(px3,px1);
}