#include "engine.h"
#include "graphics/Graphics.h"
#include "models/Entity_data.h"

Engine::Engine ( Entity_data entity_data ) : entity_data(entity_data)
{
    
}

Engine::~Engine ( )
{
    
}

void Engine::run ( )
{
    //Initalize the graphics. This opens the glfw/opengl window.
    Graphics graphics = Graphics(); 
    while ( !glfwWindowShouldClose ( graphics.get_window() ) )
    {
         graphics.Update();
    }
}

