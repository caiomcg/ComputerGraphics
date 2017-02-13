#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
	DrawLine(Vertex(0, 0, Color(255, 255, 0, 255)), Vertex(300, 20));
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
