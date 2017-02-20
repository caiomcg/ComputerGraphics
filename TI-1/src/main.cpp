#include "main.h"

void bresenhamDemo() {
	DrawLine(Vertex((IMAGE_WIDTH-1)/2, 0, Color(255, 255, 0, 255)), Vertex((IMAGE_WIDTH-1)/2, IMAGE_HEIGHT-1));
	DrawLine(Vertex(0, (IMAGE_HEIGHT-1)/2, Color(255, 255, 0, 255)), Vertex(IMAGE_WIDTH-1, (IMAGE_HEIGHT-1)/2));
	DrawLine(Vertex(0, 0, Color(0, 255, 0, 255)), Vertex(IMAGE_WIDTH-1,IMAGE_HEIGHT-1));
	DrawLine(Vertex(0, IMAGE_HEIGHT-1, Color(0, 255, 0, 255)), Vertex(IMAGE_WIDTH-1,0));
	DrawLine(Vertex(0, 0, Color(0, 255, 0, 255)), Vertex(IMAGE_WIDTH-1,IMAGE_HEIGHT-1));
}

//-----------------------------------------------------------------------------
void MyGlDraw(void) {
	DrawTriangle(Vertex(0, 0, Color(255, 0, 0, 255)), Vertex((IMAGE_WIDTH)/2, (IMAGE_HEIGHT)/2, Color(0, 255, 0, 255)), Vertex(IMAGE_WIDTH, 0, Color(0, 0, 255, 255)));
}
//----------------------------------------------------------------------------
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
