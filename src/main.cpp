#include <glad/glad.h>
#include <unistd.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <iostream>

#include "ecs/Entity_data.h"
#include "ecs/spawner/spawner.h"
#include "engine/engine.h"


int main ( )
{
    Entity_data entity_data;
    Spawner spawner = Spawner ( entity_data );
    Engine engine = Engine ( entity_data ) ;
    spawner.add_entity ( "tree" );
    spawner.add_entity ( "tree" );
    spawner.add_entity ( "fox" );
    spawner.add_entity ( "fox" );
    spawner.add_entity ( "fox" );
    engine.run ();
    
}


