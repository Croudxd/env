#include <glad/glad.h>
#include <unistd.h>
#include <vector>
#include <GLFW/glfw3.h>

#include "models/Entity_data.h"
#include "engine/engine.h"

std::vector<float> vertices = 
{
    -0.8f, -0.8f, 0.0f, 1.0f, 0.0f, 0.0f, // Vertex 1 (position and color)
    0.0f,  0.8f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (position and color)
    0.8f,  -0.8f, 0.0f, 0.0f, 0.0f, 1.0f  // Vertex 3 (position and color)
};

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

std::vector<std::vector<float>> vec_objects = { vertices, vertices2, vertices3 };

int main ( )
{
    Entity_data entity_data;
    //set data.
    
   Engine engine = Engine ( entity_data ) ;
   engine.run();
    
}

