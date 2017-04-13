#include <GL/glut.h>
#include <iostream>
#include "Pipeline/Pipeline.h"
#include "main.h"


// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

float translationFactor = 0.0f;

void MyGlDraw(void) {
    pipeline.clean();

    pipeline.setTranslation(0.0f, 0.0f, 1.0f);
    pipeline.setRotation(translationFactor, 0.0f, 1.0f, 0.0f);
    pipeline.setScale(0.75f, 0.75f, 0.75f);

    pipeline.init(2.15f, 2.0f);

    translationFactor += 0.005;
}

int main(int argc, char **argv)
{
    pipeline.setObjData("assets/monkey_head2.obj");

    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;

    // Framebuffer scan loop.
    glutMainLoop();

	return 0;
}

