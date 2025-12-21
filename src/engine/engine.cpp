#include "engine.h"
#include "graphics/Graphics.h"
#include "models/Entity_data.h"
#include <iostream>

Engine::Engine ( Entity_data& entity_data ) : entity_data(entity_data)
{

}

Engine::~Engine ( )
{
    
}

void Engine::run (   )
{
    //Initalize the graphics. This opens the glfw/opengl window.
    // This is our main loop.
    while ( !glfwWindowShouldClose ( this->graphics.get_window ( ) ) )
    {
        //Update our entities.
        //Draw to screen.
        RenderObject &obj = entity_data.render_map [ 1 ]; 
        obj.init_buffers ( );
        this->graphics.Update ( obj );
    }
}


Entity_data& Engine::get_entity_data ( )
{ 
    return this->entity_data;
}
