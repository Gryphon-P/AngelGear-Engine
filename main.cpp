#include <glad/glad.h> // Note: GLAD has to be before GLFW for some reason
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include "input.h"
#include "settings.h"

// Resizes the viewport according to the window size
void _framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Polls input from the window
void _process_input(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void _check_shader_for_errors(unsigned int& shader) {

    int  success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void _check_shader_program_for_errors(unsigned int& program) {


    int  success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void _render(GLFWwindow* window, unsigned int shader_program, unsigned int VAO) {

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    
    
    // Draw the triangle (to be moved to the main renderloop)
    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

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
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    // Resizes the viewport whenever the window changes size
    glfwSetFramebufferSizeCallback(window, _framebuffer_size_callback);

    

#pragma region Rendering Init

    // Representation of a triangle
    float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };

    // Triangle indices
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
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
    _check_shader_for_errors(vertexShader);

    // Fragment shader, stores the color data
    const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"

        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);\n"
        "}\n";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    _check_shader_for_errors(fragmentShader);


    // Creates the shader program
    unsigned int shaderProgram = glCreateProgram();

    // Attaches and link the program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    _check_shader_program_for_errors(shaderProgram);

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

    // Element buffer object
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    // Binds the EBO to VRAM
    // Creates an element array buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Set the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Draws mesh as wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#pragma endregion


    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        // INPUT
        if (_is_key_pressed(window, K_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }
        // INPUT_END

        // RENDERING
        _render(window, shaderProgram, VAO);
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


/*
A given shader program is formatted as follows:
#version version_num version_type

in type var_name;
in type var_name;

out type var_name_out;

uniform type uniform_var_name;

void main() 
{
    // Wonky code goes here

    // Output variables
    var_name_out = processed_data;
}

// We are allowed 16 4-component vertex attributes.
These could be things like position, normal, UV, etc.

GLSL Types:
vecN: very useful
bvecN: bool vec, maybe useful?
ivecN: probobly useful?
uvecN: can't see a lot of use cases
dvecN: can't see a lot of use cases, 32 bit is fine most of the time

we use "layout (location = 0)" before an input variable in order to get the memory location so we can write to it.
However, one can get the vertex attribute location via glGetAttribLocation(shader_program, "attribute_name");


*/



