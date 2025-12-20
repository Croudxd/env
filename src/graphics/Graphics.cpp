#include "shaders.h"
#include <cstddef>
#include <cstdio>
#include "graphics/Graphics.h"
//create glfw window and shaders and any opengl stuff and return glfw window and shaderprogram.



Graphics::Graphics ( )
{
    if ( !glfwInit ( ) )
    {
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window  = create_glfw_window();
    if ( !window ) 
    {
        glfwTerminate ();
        return;
    }
 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return;
    }



    this->shaderProgram = initalize_shaders ();
   
    //return window and shaderProgram.
}


Graphics::~Graphics ( )
{
    //glDeleteVertexArrays(1, 1);
    //glDeleteBuffers(1, &x.get_vbo());
    glDeleteProgram(shaderProgram);
    glfwTerminate();
}

void Graphics::Update ( ) {

    while (!glfwWindowShouldClose(this->window)) 
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}


GLFWwindow* Graphics::create_glfw_window ()
{
    GLFWwindow *window = glfwCreateWindow ( 640, 480, "Env", NULL, NULL );
    if ( !window ) 
    {
        glfwTerminate ();
    }
    glfwMakeContextCurrent ( window );
    return window;
}
