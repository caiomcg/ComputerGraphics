#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include "Vertex.h"

#include <math.h>
#include <stdio.h>

void PutPixel(const Vertex& px);

void DrawLine(const Vertex& px1,const Vertex& px2);

void DrawTriangle(const Vertex& px1,const Vertex& px2,const Vertex& px3);
#endif
