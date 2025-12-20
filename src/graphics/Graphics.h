#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Graphics
{

private:
    unsigned int shaderProgram;
    GLFWwindow *window;

    GLFWwindow* create_glfw_window ();

public:
    Graphics ( ) ;
    ~Graphics ( ) ;
    void Update ( ) ;

};






