#include "engine.h"
#include "graphics/Graphics.h"
#include "models/Entity_data.h"
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
       
        //Update our entities.
        for (auto &x : entity_data.entity_vec)
        {
            std::vector<float> x_vertices;
            std::vector<float> y_vertices;
            std::cout << "entity id: " << x  << std::endl;
            RenderObject obj = entity_data.render_map [ x ]; 
            //calulate out objs calculate the midpoint of the shape.
            int vert_count = obj.get_vertices().size() / 6;
            
            for ( int j = 0; j < obj.get_vertices().size(); j+=6 )
            {
                std::vector<float> vertices = obj.get_vertices();
                x_vertices.push_back ( vertices [ j ] );
                y_vertices.push_back( vertices [ j+1 ] );
                std::cout << obj.get_vertices().size() <<  "jjj" << j << std::endl;
            }
        
            float mid_x = 0;
            float mid_y = 0;
            for ( auto &i : x_vertices )
            {
                mid_x += i;
            }
            for ( auto &z : y_vertices )
            {
                mid_y += z;
            }
            mid_x = mid_x / x_vertices.size();
            mid_y = mid_y / y_vertices.size();
            float percep = entity_data.perception_map [ x ].perception_day;

            for ( int ent = 1; ent < entity_data.entity_vec.size(); ent++)
            {
                std::vector<float> ent_x_vertices;
                std::vector<float> ent_y_vertices;
                RenderObject ent_obj = entity_data.render_map [ x ]; 
                //calulate out objs calculate the midpoint of the shape.
                int ent_vert_count = ent_obj.get_vertices().size() / 6;
                for ( int ent_j = 0; ent_j < ent_obj.get_vertices().size(); ent_j+=6 )
                {
                    std::vector<float> ent_vertices = ent_obj.get_vertices();
                    ent_x_vertices.push_back ( ent_vertices [ ent_j ] );
                    ent_y_vertices.push_back( ent_vertices [ ent_j+1 ] );
                }
                float ent_mid_x = 0;
                float ent_mid_y = 0;
                for ( auto &ent_x : ent_x_vertices )
                {
                    ent_mid_x += ent_x;
                }
                for ( auto &ent_y : ent_y_vertices )
                {
                    ent_mid_y += ent_y;
                }
                std::cout <<  " ent mid x y:"<<ent_mid_x << ent_mid_y << std::endl;
                std::cout <<  " mid x y:"<< mid_x << mid_y << std::endl;
                ent_mid_x = ent_mid_x / ent_x_vertices.size();
                ent_mid_y = ent_mid_y / ent_y_vertices.size();
                
                float x_calc = ( ent_mid_x - mid_x );
                float y_calc = ( ent_mid_y - mid_y );
                std::cout << x_calc << y_calc << std::endl;
                float distance = std::sqrt( ( x_calc*x_calc ) +  ( y_calc*y_calc ) );
                if (distance <= percep )
                {
                    std::cout << "brute force works" << std::endl;
                    std::cout << "distance" << distance << std::endl;
                }
                else 
                {
                    std::cout << distance << std::endl;
                    std::cout << percep << std::endl;
                }
            }
        }
        //Draw to screen.
        for ( auto& [ id, obj ] : entity_data.render_map )
        {
            obj.init_buffers ( );
            this->graphics.Update ( obj ) ;
        }
    }
}


Entity_data& Engine::get_entity_data ( )
{ 
    return this->entity_data;
}
