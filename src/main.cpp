#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int, char**) {
    std::cout << "Hello, world!\n";

    glfwInit();

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Test", nullptr, nullptr);
    if (!window) {
        std::cout << "Cannot create window!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
