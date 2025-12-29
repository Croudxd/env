#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ecs/components/renderobject.h"


class Graphics
{

private:
    unsigned int shaderProgram;
    GLFWwindow *window;

    GLFWwindow* create_glfw_window ();

public:
    Graphics ( ) ;
    ~Graphics ( ) ;
    void Update ( RenderObject obj ) ;
    GLFWwindow* get_window();

};






