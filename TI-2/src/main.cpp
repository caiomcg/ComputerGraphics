#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include "Obj/objLoader.h"
#include "Pipeline/Pipeline.h"
#include "main.h"


// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

void MyGlDraw(void) {
    pipeline.addTransl(-200.0f, 200.0f, 0.0f);
    pipeline.init(3.0f, 2.0f, IMAGE_WIDTH, IMAGE_HEIGHT);
}

int main(int argc, char **argv)
{
    pipeline.setObjData(argv[1]);

    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;

    // Framebuffer scan loop.
    glutMainLoop();

	return 0;
}

