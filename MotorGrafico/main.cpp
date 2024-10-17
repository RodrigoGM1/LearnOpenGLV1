#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//Definicion de las funciones
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
//Definicion de las funciones

int main() {

	//Creacion de la pantalla
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Ventana", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Fallo al crear la ventana GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//Creacion de la pantalla

	//Creacion del contexto openGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//Creacion del contexto openGL

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Loop de renderizado
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//Loop de renderizado


	glfwTerminate();

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) //Funcion para adaptar el contexto openGL al tamaño de la pantalla
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) //Funcion para cerrar la pantalla
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}