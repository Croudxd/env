#include "shaders.h"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <cstdio>
#include "graphics/Graphics.h"
#include <iostream>
//create glfw window and shaders and any opengl stuff and return glfw window and shaderprogram.




Graphics::Graphics ( )
{
    if ( !glfwInit ( ) )
    {
        std::cout << "glfw init failed.";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window  = create_glfw_window();
    if ( !window ) 
    {
        std::cout << "window null.";
        glfwTerminate ();
        return;
    }
 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "window null.";
        return;
    }

    this->shaderProgram = initalize_shaders ();
    std::cout << "Success";
}


Graphics::~Graphics ( )
{
    glDeleteProgram(shaderProgram);
    glfwTerminate();
}

void Graphics::Update ( ) {

    
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->window);
    glfwPollEvents();
   
}


GLFWwindow* Graphics::create_glfw_window ()
{
    GLFWwindow *window = glfwCreateWindow ( 640, 480, "Env", NULL, NULL );
    if ( !window ) 
    {
        std::cout << "glfw terminate no window.";
        glfwTerminate ();

    }
    glfwMakeContextCurrent ( window );
    return window;
}

GLFWwindow* Graphics::get_window ( ) { return this->window; }
