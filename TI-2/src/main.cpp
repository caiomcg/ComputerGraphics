#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include "Obj/objLoader.h"
#include "Pipeline/Pipeline.h"
#include "main.h"


// Ponteiro para o objeto que carregará o modelo 3D (formato OBJ).
objLoader *objData;

// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

void MyGlDraw(void) {
    for(int i=0; i<objData->faceCount; i++)
    {
        obj_face* o = objData->faceList[i];

        drawLine(
                Pixel(objData->vertexList[o->vertex_index[0]]->e[0],objData->vertexList[o->vertex_index[0]]->e[1]),
                Pixel(objData->vertexList[o->vertex_index[1]]->e[0],objData->vertexList[o->vertex_index[1]]->e[1]));

        drawLine(
                Pixel(objData->vertexList[o->vertex_index[1]]->e[0],objData->vertexList[o->vertex_index[1]]->e[1]),
                Pixel(objData->vertexList[o->vertex_index[2]]->e[0],objData->vertexList[o->vertex_index[2]]->e[1]));

        drawLine(
                Pixel(objData->vertexList[o->vertex_index[2]]->e[0],objData->vertexList[o->vertex_index[2]]->e[1]),
                Pixel(objData->vertexList[o->vertex_index[0]]->e[0],objData->vertexList[o->vertex_index[0]]->e[1]);
    }

}

int main(int argc, char **argv)
{
	objData = new objLoader();			// cria o objeto que carrega o modelo
	objData->load((char*)argv[1]);	// a carga do modelo é indicada atraves do nome do arquivo.
										// Neste caso, deve ser sempre do tipo OBJ.
    InitOpenGL(&argc, argv);
    InitCallBacks();
    InitDataStructures();

    // Ajusta a função que chama as funções do mygl.h
    DrawFunc = MyGlDraw;

    // Framebuffer scan loop.
    glutMainLoop();

	return 0;
}

