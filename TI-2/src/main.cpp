#include <GL/glut.h>
#include <iostream>
#include "Pipeline/Pipeline.h"
#include "main.h"


// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

float translationFactor = 0.0f;

void MyGlDraw(void) {
    pipeline.clean();
    pipeline.setTranslation(-IMAGE_WIDTH/2,IMAGE_HEIGHT/2,0.0f);
    pipeline.setScale(150.0f, -150.0f, 150.0f);
    pipeline.setRotation(translationFactor, 0.0f, 1.0f, 0.0f);
    pipeline.init(5.0f, 1.5f, IMAGE_WIDTH, IMAGE_HEIGHT);

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

