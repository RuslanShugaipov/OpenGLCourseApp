#include "Viewer.h"

void Viewer::init()
{
	init_interface();
	init_opengl();
	init_scene();
	init_interaction();
}

void Viewer::init_interface()
{
	glutInit(nullptr, nullptr);
	glutInitWindowSize(640, 480);

}