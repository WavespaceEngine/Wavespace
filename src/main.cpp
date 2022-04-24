#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
