#include <glad/glad.h>
#include <unistd.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

#include "models/Entity_data.h"
#include "engine/engine.h"


std::vector<float> vertices2 = 
{
    -0.9f, 0.4f, 0.0f, 1.0f, 0.0f, 1.0f, // Vertex 1 (position and color)
    0.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Vertex 2 (position and color)
    0.9f,  0.4f, 0.0f, 0.0f, 1.0f, 1.0f  // Vertex 3 (position and color)
};

std::vector<float> vertices3 = 
{
    -0.6f, 0.0f,  0.0f, 1.0f, 1.0f, 0.0f, // Vertex 1 (position and color)
    0.0f,  -0.6f, 0.0f, 0.0f, 1.0f, 1.0f, // Vertex 2 (position and color)
    0.6f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f  // Vertex 3 (position and color)
};


void create_tree (Entity_data& entity_data, int id /* position */ )
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

int main ( )
{
    Entity_data entity_data;
    
    Engine engine = Engine ( entity_data ) ;
    create_tree ( engine.get_entity_data() ,  1 /* id */ );
    create_tree ( engine.get_entity_data() ,  2 /* id */ );
    engine.run ( );
    
}


