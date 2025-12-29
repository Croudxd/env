#include <glad/glad.h>
#include <unistd.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ecs/Entity_data.h"
#include "engine/engine.h"


int main ( )
{
    Entity_data entity_data;
    Engine engine = Engine ( entity_data ) ;
    engine.run ( );
    
}


