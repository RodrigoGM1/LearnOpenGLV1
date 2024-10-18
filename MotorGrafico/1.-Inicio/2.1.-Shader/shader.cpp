/*
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int ancho, int alto);
void processInput(GLFWwindow* window);

const char* vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "out vec4 vertexColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
    "}\0";
//const char* fragmentShaderSource =
//    "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "in vec4 vertexColor;\n"
//    "void main(){\n"
//    "   FragColor = vertexColor;\n"
//    "}\0";
const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec4 ourColor;\n"
    "void main(){\n"
    "   FragColor = ourColor;\n"
    "}\0";

int main()
{
    int success;
    char infoLog[512];
    //Creacion de la pantalla
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ventana", NULL, NULL);
    if (window == NULL) {
        std::cout << "Fallo al crear la ventana GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //Creacion de la pantalla

    //Creacion del contexto OPENGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Fallo al inicializar GALD" << std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //Creacion del contexto OPENGL

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILACION FALLIDA\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILACION FALLIDA\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::LINKEO FALLIDO\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //Loop de renderizado
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        std::cout << greenValue << std::endl; 
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        glUseProgram(shaderProgram);
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //Loop de renderizado

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int ancho, int alto) {
    glViewport(0, 0, ancho, alto);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
*/