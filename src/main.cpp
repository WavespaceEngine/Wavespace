#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<VBO.hpp>

const char* vertexShaderSource = R"(#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0")";

const char* fragmentShaderSource = R"(#version 460 core\n"
"out vec4 FragColor; \n"

"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \n"
"}\0")";

int width = 1280;
int height = 720;

void framebufferResizeCallback(GLFWwindow* pWindow, int pWidth, int pHeight) {
    width = pWidth;
    height = pHeight;
    glViewport(0, 0, width, height);
}

int main(int, char**) {
    std::cout << "Hello, world!\n";

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(width, height, "Test", nullptr, nullptr);

    if (!window) {
        std::cout << "Cannot create window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cout << "Could not initialize GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }


    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

