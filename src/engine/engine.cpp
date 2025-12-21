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
    }
}


Entity_data& Engine::get_entity_data ( )
{ 
    return this->entity_data;
}

void Engine::init_grid ( )
{
    for ( auto &id : this->entity_data.entity_vec )
    {
        std::vector <float> &vec = entity_data.render_map [ id ].get_vertices ( );
        int size = vec.size ( ); 

        if ( size == 18 )
        {
           //vertex 1:
           float grid_index_x = (vec [ 0  ] - ( -1.0 ) / 0.1 );
           float grid_index_y = (vec [ 1  ] - ( -1.0 ) / 0.1 );
        {    
           float grid_index_x = (vec [ 6  ] - ( -1.0 ) / 0.1 );
           float grid_index_y = (vec [ 7  ] - ( -1.0 ) / 0.1 );
        }

        {    
           float grid_index_x = (vec [ 12 ] - ( -1.0 ) / 0.1 );
           float grid_index_y = (vec [ 13 ] - ( -1.0 ) / 0.1 );
        }


        }
        if ( size == 36 )
        {
            // square.
        }
        else 
        {
            return; 
        }
    }

}  











