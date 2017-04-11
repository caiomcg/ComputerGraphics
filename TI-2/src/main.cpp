#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include "Obj/objLoader.h"
#include "Pipeline/Pipeline.h"


// Ponteiro para o objeto que carregará o modelo 3D (formato OBJ).
objLoader *objData;

// Referência para o pipeline gráfico.
Pipeline pipeline = Pipeline::getInstance();

unsigned int ViewPortWidth  = 512;
unsigned int ViewPortHeight = 512;

//-----------------------------------------------------------------------------
void display(void)
{
	glViewport(0, 0, ViewPortWidth, ViewPortHeight);

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
	gluPerspective(	55.0f, 								// angulo de abertura da camera
					(float)ViewPortWidth/ViewPortWidth, // aspecto da imagem
					1.0f, 								// near plane
					50.0f);								// far plane

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(	0.0f, 0.0f, 4.0f,	// posição da câmera
				0.0f, 0.0f, 0.0f,	// ponto para o qual a camera está olhando
				0.0f, 1.0f, 0.0f);	// vetor "up"

	///////////////////////////////////////////////////////////////////////////
	// Desenha os eixos do sistema de coordenadas do universo
	// Vermelho: eixo X
	// Verde: eixo Y
	// Azul: eixo Z
	///////////////////////////////////////////////////////////////////////////

	glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);	// eixo X
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);	// eixo Y
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);	// eixo Z
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
	glEnd();

	///////////////////////////////////////////////////////////////////////////
	// Desenha o modelo carregado utilizando linhas brancas.
	// Cada volta do loop desenha um triangulo, formado por tres linhas. 
	// Cada linha eh formada por 2 pontos (inicial e final).
	///////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < objData->faceCount; i++) {
        obj_face *o = objData->faceList[i];
    }



	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

//-----------------------------------------------------------------------------
// Libera a memoria do objeto responsavel por guardar dados do modelo.
void FreeMemFunc(void)
{
	std::clog << "Exiting...\n";

	if (!objData)
		delete objData;

    pipeline.release();
}

//-----------------------------------------------------------------------------
// Programa principal
int main(int argc, char **argv)
{
	objData = new objLoader();			// cria o objeto que carrega o modelo
	objData->load((char*)argv[1]);	// a carga do modelo é indicada atraves do nome do arquivo.
										// Neste caso, deve ser sempre do tipo OBJ.

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OBJ Loader");

	glutDisplayFunc(display);

	atexit(FreeMemFunc);

	glutMainLoop();

	return 0;
}

