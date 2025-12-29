#include "engine.h"
#include "graphics/Graphics.h"
#include "ecs/Entity_data.h"
#include <iostream>
#include <cmath>

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
        perception_brute_force ();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Draw to screen.
        
        for ( auto it = entity_data.render_map.begin(); it != entity_data.render_map.end(); ++it ) {
            this->graphics.Update(it->second);
        }
        glfwSwapBuffers(this->graphics.get_window());
        glfwPollEvents();
    }
}


Entity_data& Engine::get_entity_data ()
{ 
    return this->entity_data;
}


bool Engine::perception_brute_force ()
{
    if ( entity_data.entity_vec.size () == 0)
    {
        return false;
    }
    for ( auto &id_a : entity_data.entity_vec )
    {
        RenderObject& obj_a = entity_data.render_map [ id_a ];
        auto vertices_a = obj_a.get_vertices ();
        
        float mid_x_a = 0, mid_y_a = 0;
        int count_a = 0;

        for ( size_t j = 0; j < vertices_a.size (); j += 6 )
        {
            mid_x_a += vertices_a [ j ];
            mid_y_a += vertices_a [ j+1 ];
            count_a++;
        }
        if ( count_a > 0 )
        {
            mid_x_a /= count_a;
            mid_y_a /= count_a;
        }

        float percep = entity_data.perception_map[id_a].perception_day;

        for ( auto &id_b : entity_data.entity_vec ) 
        {
            if ( id_a == id_b ) continue;  

            RenderObject& obj_b = entity_data.render_map [ id_b ];
            auto vertices_b = obj_b.get_vertices ();
            
            float mid_x_b = 0, mid_y_b = 0;
            int count_b = 0;

            for ( size_t k = 0; k < vertices_b.size(); k += 6 )
            {
                mid_x_b += vertices_b [ k ];
                mid_y_b += vertices_b [ k+1 ];
                count_b++;
            }
            if ( count_b > 0 ) 
            {
                mid_x_b /= count_b;
                mid_y_b /= count_b;
            }

            float dx = mid_x_b - mid_x_a;
            float dy = mid_y_b - mid_y_a;
            float distance = std::sqrt( ( dx * dx ) + ( dy * dy ) );

            if ( distance <= percep ) 
            {
                entity_data.visable_entities_map [ id_a ].entities.push_back( id_b );
            }
       }
    }
    return false; 
}
