#include <GL/glut.h>
#include <iostream>
#include "Pipeline/Pipeline.h"
#include "main.h"


// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

float rotationFactor = 0.0f;
float scaleFactor = 0.7f;

void MyGlDraw(void) {
    pipeline.clean();

    pipeline.setTranslation(0.0f, 0.0f, 1.0f);
    pipeline.setRotation(rotationFactor, 0.0f, 1.0f, 0.0f);
    pipeline.setScale(scaleFactor,scaleFactor,scaleFactor);

    pipeline.init(2.15f, 2.0f);

    rotationFactor += 0.07f;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "No path to .obj provided. Exiting..." << std::endl;
        return 1;
    }
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

