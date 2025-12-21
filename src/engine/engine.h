#pragma once
#include "graphics/Graphics.h"
#include "models/Entity_data.h"

class Engine
{

public:
    Engine ( Entity_data& entity_data ) ;
    ~Engine ( ) ;
    void run ( );
    Entity_data& get_entity_data ( );
private:    
    Entity_data entity_data;
    Graphics graphics;

};
