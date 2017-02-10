#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
	DrawCanvas(8);
	//DrawLine(Pixel(IMAGE_WIDTH/2, IMAGE_WIDTH/2), Pixel(IMAGE_WIDTH, 0));
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
