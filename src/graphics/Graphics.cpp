#include "shaders.h"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <cstdio>
#include "graphics/Graphics.h"
#include "models/components/renderobject.h"
#include <iostream>
//create glfw window and shaders and any opengl stuff and return glfw window and shaderprogram.




Graphics::Graphics ( )
{
    std::cout << "into";
    if ( !glfwInit ( ) )
    {
        std::cout << "glfw init failed.";
        return;
    }

    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    this->window = create_glfw_window ( );
    if ( !window ) 
    {
        std::cout << "window null.";
        glfwTerminate ( );
        return;
    }
 
    if ( !gladLoadGLLoader ( ( GLADloadproc )glfwGetProcAddress ) )
    {
        std::cout << "window null.";
        return;
    }

    this->shaderProgram = initalize_shaders ( );
}


Graphics::~Graphics ( )
{
    glDeleteProgram ( shaderProgram );
    glfwTerminate ( );
}

void Graphics::Update ( RenderObject obj ) 
{
    std::vector < float > vec = obj.get_vertices();
    glClear ( GL_COLOR_BUFFER_BIT );
    glBindBuffer ( GL_ARRAY_BUFFER, obj.get_vbo ( ) );
    glBufferSubData ( GL_ARRAY_BUFFER, 0, obj.get_vertices( ).size() * sizeof ( float ), static_cast<const void *>( obj.get_vertices( ).data( ) ) );
    glUseProgram ( shaderProgram );
    glBindVertexArray ( obj.get_vao ( ) );
    glDrawArrays ( GL_TRIANGLES, 0, obj.get_vertices().size() / 6 );
    glBindVertexArray ( 0 );
    glfwSwapBuffers ( window );
    glfwPollEvents ( );
}

GLFWwindow* Graphics::create_glfw_window ()
{
    GLFWwindow *window = glfwCreateWindow ( 640, 480, "Env", NULL, NULL );
    glfwMakeContextCurrent ( window );
    if ( !window ) 
    {
        std::cout << "glfw terminate no window.";
        glfwTerminate ( );

    }
    return window;
}

GLFWwindow* Graphics::get_window ( ) { return this->window; }
