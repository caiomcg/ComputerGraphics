#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
	DrawCanvas();
}
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {

	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();
	return 0;
}
