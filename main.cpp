#include <glad/glad.h> // Note: GLAD has to be before GLFW for some reason
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include "input.h"
#include "settings.h"

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


void check_shader_for_errors(unsigned int& shader) {

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void check_shader_program_for_errors(unsigned int& program) {


    int  success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}



void render(GLFWwindow* window, unsigned int shader_program, unsigned int VAO) {

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    
    
    // Draw the triangle (to be moved to the main renderloop)
    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);











}

int main() {
    

    // Initializes GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    

    // Creates a window
    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "rose_engine", NULL, NULL);
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

#pragma region Rendering Init
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Vertex buffer object.
    // 1 is the ID for the object
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // Binds the buffer as an array buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Adds the vertex data to the buffer
    // The final argument of this function has a couple states:
    /*
        GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
        GL_STATIC_DRAW: the data is set only once and used many times.
        GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
    */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Defines the vertex shader, stores the position data
    const char* vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    // Creates a vertex shader object
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Attach the source code and compile it
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Checks if there are any bugs in the shader
    check_shader_for_errors(vertexShader);

    // Fragment shader, stores the color data
    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"

        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    check_shader_for_errors(fragmentShader);


    // Creates the shader program
    unsigned int shaderProgram = glCreateProgram();

    // Attaches and link the program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    check_shader_program_for_errors(shaderProgram);

    // We can delete the shaders once we're done with them
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // uses the program
    glUseProgram(shaderProgram);

    // glVertexAttribPointer specifies how a given draw call should interpret the vertex datas
    /*
        - Index of the vertex attribute
        - Number of components per vertex attribute vec3 in this case
        - What each componet of the attribute is - FLOAT
        - If the data should be normalized between -1 and 1
        - Stride of the vertex attributes, measured in bits
        - Pointer of the first vertex component of the first attribute
    */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // ??? not sure

    /*
        Vertex Array Object (VAO) can store vertex attributes and act like a Vertex Buffer Object (VBO)

        """
         A vertex array object stores the following:
            * Calls to glEnableVertexAttribArray or glDisableVertexAttribArray.
            * Vertex attribute configurations via glVertexAttribPointer.
            * Vertex buffer objects associated with vertex attributes by calls to glVertexAttribPointer.
        """

        In core openGL, we need to use VAOs otherwise it will refuse to render anything
    */

    // Create VAO
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // Bind VAO
    glBindVertexArray(VAO);


    // Copy the vertices to the VAO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
#pragma endregion


    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // INPUT
        if (is_key_pressed(window, K_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }
        // INPUT_END

        // RENDERING
        render(window, shaderProgram, VAO);
        // RENDERING_END


        glfwSwapBuffers(window);
        glfwPollEvents();

        

        /*
        process_input();
        update();
        render();
        */



    }

    glfwTerminate();


	return 0;


}