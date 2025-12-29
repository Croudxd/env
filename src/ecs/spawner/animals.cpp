#include <iostream>
#include "ecs/Entity_data.h"
#include "spawner.h"

void fox (Entity_data& entity_data)
{

    int id = entity_data.entity_vec.size();
    std::vector<float> vertices = 
    {
         0.6f,    0.6f,    0.0f,    0.0f,  1.0f,  0.0f, // Bottom-Left
         0.8f,    0.6f,    0.0f,    0.0f,  1.0f,  0.0f, // Bottom-Right
         0.6f,    0.8f,    0.0f,    0.0f,  1.0f,  0.0f, // Top-Left

         0.8f,    0.6f,    0.0f,    0.0f,  1.0f,  0.0f, // Bottom-Right
         0.8f,    0.8f,    0.0f,    0.0f,  1.0f,  0.0f, // Top-Right
         0.6f,    0.8f,    0.0f,    0.0f,  1.0f,  0.0f
    };

    entity_data.entity_vec.push_back ( id );
    entity_data.render_map.emplace (  id , RenderObject ( vertices ) );
    entity_data.render_map.at(id).init_buffers();
    entity_data.perception_map.emplace(id, Perception{0.3f, 0.3f});

}

REGISTER_ENTITY ( "fox", fox );



void tree ( Entity_data& entity_data )
{
    int id = entity_data.entity_vec.size();
    std::vector<float> vertices = 
    {
        -0.1f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f, // Vertex 1 (position and color: Green)
        0.0f,  0.1f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (position and color: Green)
        0.1f,  -0.1f, 0.0f, 0.0f, 1.0f, 0.0f  // Vertex 3 (position and color: Green)
    };

    entity_data.entity_vec.push_back ( id );
    entity_data.render_map.emplace (  id , RenderObject ( vertices ) );
    entity_data.render_map.at(id).init_buffers();
    entity_data.perception_map.emplace(id, Perception{0.3f, 0.3f});
}
REGISTER_ENTITY ( "tree", tree );
