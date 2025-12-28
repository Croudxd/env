#include <glad/glad.h>
#include <unistd.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

#include "models/Entity_data.h"
#include "engine/engine.h"





void create_tree ( Entity_data& entity_data, int id /* position */ )
{
    std::vector<float> vertices = 
    {
        -0.1f, -0.1f, 0.0f, 0.0f, 1.0f, 0.0f, // Vertex 1 (position and color: Green)
        0.0f,  0.1f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (position and color: Green)
        0.1f,  -0.1f, 0.0f, 0.0f, 1.0f, 0.0f  // Vertex 3 (position and color: Green)
    };
    entity_data.entity_vec.push_back ( id );
    RenderObject obj = RenderObject ( vertices );
    entity_data.render_map.emplace ( id,  obj );
    struct Perception perp = { 0.3, 0.3 };
    entity_data.perception_map.emplace (id,  perp );
}

void create_tree1 ( Entity_data& entity_data, int id /* position */ )
{
    std::vector<float> vertices = 
    {
        -0.4f,  0.2f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 1 (moved left and up)
        -0.3f,  0.4f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (moved left and up)
        -0.2f,  0.2f,  0.0f, 0.0f, 1.0f, 0.0f  // Vertex 3 (moved left and up)
    };
    entity_data.entity_vec.push_back ( id );
    RenderObject obj = RenderObject ( vertices );
    entity_data.render_map.emplace ( id,  obj );
    struct Perception perp = { 0.3, 0.3 };
    entity_data.perception_map.emplace (id,  perp );
}
void create_tree2 ( Entity_data& entity_data, int id /* position */ )
{
    std::vector<float> vertices = 
    {
        -0.2f,  0.2f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 1 (moved right)
        -0.1f,  0.4f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (moved right)
         0.0f,  0.2f,  0.0f, 0.0f, 1.0f, 0.0f  // Vertex 3 (moved right)
    };
    entity_data.entity_vec.push_back ( id );
    RenderObject obj = RenderObject ( vertices );
    entity_data.render_map.emplace ( id,  obj );
    struct Perception perp = { 0.3, 0.3 };
    entity_data.perception_map.emplace (id,  perp );
}

int main ( )
{
    Entity_data entity_data;
    
    Engine engine = Engine ( entity_data ) ;
    create_tree ( engine.get_entity_data() ,  1 /* id */ );
    create_tree1 ( engine.get_entity_data() ,  2 /* id */ );
    create_tree2 ( engine.get_entity_data() ,  3 /* id */ );
    engine.run ( );
    
}


