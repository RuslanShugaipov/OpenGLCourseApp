#ifndef VIEWER_H
#define VIEWER_H

#include <GL/glut.h>

class Viewer
{
private:

public:
	void init();
	void init_interface();
	void init_opengl();
	void init_scene();
	void create_sample_scene();
	void init_interaction();
	void main_loop();
};

#endif