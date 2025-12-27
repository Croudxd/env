#include "engine.h"
#include "graphics/Graphics.h"
#include "models/Entity_data.h"
#include "models/components/grid.h"
#include <iostream>

Engine::Engine ( Entity_data& entity_data ) : entity_data(entity_data)
{

}

Engine::~Engine ( )
{
    
}

void Engine::run ( )
{

    // Before we calculate anything for the data we need to find out where it is.
    // so we need to cut our screen into a grid. i will be doing 0.10x0.10 grid, we can change this down the line.
    // Basically need to say if no grid, we make a grid and give every entity a grid number (a being x, y being numbers.)
    //

    // This is our main loop.
    while ( !glfwWindowShouldClose ( this->graphics.get_window ( ) ) )
    {
        //Update our entities.
        //Draw to screen.
        RenderObject &obj = entity_data.render_map [ 1 ]; 
        obj.init_buffers ( );
        this->graphics.Update ( obj );
    }for (const auto& [key, value] : Grid_map)
    {
        if (value.size() < 2)
        {
            //do nothing
        }
    }
}


Entity_data& Engine::get_entity_data ( )
{ 
    return this->entity_data;
}

void Engine::init_grid ( )
{ 

    //go into every remder object, find each x , y value, which is going to alligm to a cell number, add that to the gridmap
    for ( auto &x : entity_data.entity_vec) 
    {
        RenderObject obj = entity_data.render_map [ x ];
        //so obj will store all the vertices, we meed to get the x amd y of each and findthe balue of 
        obj.get_vertices();
    }



    
}  











