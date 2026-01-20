#include <glad/glad.h> // Note: GLAD has to be before GLFW for some reason
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include "Input.h"

// Resizes the viewport according to the window size
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Polls input from the window
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    

    // Initializes GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    

    // Creates a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "rose_engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initializes GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // Sets viewport dimentions
    glViewport(0, 0, 800, 600);
    
    // Resizes the viewport whenever the window changes size
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // INPUT
        processInput(window);
        // INPUT_END

        // RENDERING

        // Clears the screen
        glClearColor(0.5f, 0.f, 0.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // RENDERING_END


        glfwSwapBuffers(window);
        glfwPollEvents();

        if (is_key_pressed(window, K_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }


    }

    glfwTerminate();


	return 0;


}