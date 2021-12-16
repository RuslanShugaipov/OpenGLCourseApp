//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

//Занятие 2 (рисование окна)
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow*, int width, int heigth);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LOKI", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}*/

//Занятие 4 (рисование треугольника)
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout(location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//
//	int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//
//	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	float vertices[] = {
//		 0.5f, 0.5f, 0.0f,
//		 0.5f, -0.5f, 0.0f,
//		-0.5f, -0.5f, 0.0f,
//		-0.5f,  0.5f, 0.0f
//	};
//
//	unsigned int indices[] = {
//		0, 1, 3,
//		1, 2, 3
//	};
//
//	unsigned int EBO;
//	glGenBuffers(1, &EBO);
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	//Отрисовка полигонов в режиме кракаса
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6,  GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}

//Упражнение 3
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout(location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShader1Source = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShader2Source = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//	int shaderProgramOrange = glCreateProgram();
//	int shaderProgramYellow = glCreateProgram();
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShader1Source, NULL);
//	glCompileShader(fragmentShaderOrange);
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShader2Source, NULL);
//	glCompileShader(fragmentShaderYellow);
//
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//
//	glAttachShader(shaderProgramYellow, vertexShader);
//	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//	glLinkProgram(shaderProgramYellow);
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderOrange);
//	glDeleteShader(fragmentShaderYellow);
//
//	float vertices[] = {
//		 -0.5f, 0.95f, 0.0f,
//		 -0.75f, 0.25f, 0.0f,
//		 -0.25f, 0.25f, 0.0f,
//
//		  0.5f, -0.95f, 0.0f,
//		  0.75f, -0.25f, 0.0f,
//		  0.25f, -0.25f, 0.0f,
//	};
//
//
//	unsigned int VBOs[2], VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//Отрисовка полигонов в режиме кракаса
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgramOrange);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glUseProgram(shaderProgramYellow);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 3, 3);
//
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(2, VAOs);
//	glDeleteBuffers(2, VBOs);
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//#include "Shader.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Triangle", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader myShaders("C:/Users/Руслан/OneDrive/Документы/Visual Studio 2019/Projects/OpenGLCourseApp/Shaders/vertexShader.vs",
//		"C:/Users/Руслан/OneDrive/Документы/Visual Studio 2019/Projects/OpenGLCourseApp/Shaders/fragmentShader.fs");
//
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
//	};
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	//Отрисовка полигонов в режиме кракаса
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	myShaders.use();
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}

#include <cstdio>
#include <cstdarg>
#include <cmath>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;
double translate_x = 0;
double translate_y = 0;
double translate_z = -0.3;

void display();
void keyboard(unsigned char key, int x, int y);
void init();
void reset();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(320, 320);
	glutInitWindowPosition(600, 300);
	glutCreateWindow("Cube");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	
	init();
	glutMainLoop();

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, translate_z);

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y,0.0, 1.0, 0.0);

	//передняя сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	//задняя сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	//правая сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();


	//левая сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();


	//верхняя сторона
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	//нижняя сторона
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		rotate_y += 5;
		break;
	case 'd':
		rotate_y -= 5;
		break;
	case 'w':
		rotate_x += 5;
		break;
	case 's':
		rotate_x -= 5;
		break;
	case 'q':
		translate_z += 0.05;
		break;
	case 'e':
		translate_z -= 0.05;
		break;
	case 'r':
		reset();
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'a':
//		rotate_y += 5;
//		break;
//	case 'd':
//		rotate_y -= 5;
//		break;
//	case 'w':
//		rotate_x += 5;
//		break;
//	case 's':
//		rotate_x -= 5;
//		break;
//	default:
//		break;
//	}
//
//	glutPostRedisplay();
//}

void init()
{
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void reset()
{
	rotate_x = 0;
	rotate_y = 0;
	rotate_z = 0;
	translate_x = 0;
	translate_y = 0;
	translate_z = 0;
}