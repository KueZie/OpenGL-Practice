#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iterator>
#include "Renderer.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "glewInit() Error!\n";

	std::cout << glGetString(GL_VERSION) << std::endl;

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	GLfloat verticies[8] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	GLuint indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
	VertexBuffer vbo(1, std::vector<GLfloat>(std::begin(verticies), std::end(verticies)), GL_STATIC_DRAW);
	IndexBuffer ibo(1, std::vector<GLuint>(std::begin(indices), std::end(indices)), GL_STATIC_DRAW);

	Shader shader("res/shaders/basic.shader");
	glUseProgram(shader.GetID());
	int i = 1;
	int dir = 3;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
		shader.SetUniform("u_Color", (float)i / 255, (float)1 / i, 2 / i, 1.0f);
		if (i + dir >= 255 || i + dir <= 1)
		{
			dir *= -1;
		}
		else
		{
			i += dir;
		}
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}