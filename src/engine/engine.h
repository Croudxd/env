#pragma once
#include "graphics/Graphics.h"
#include "models/Entity_data.h"
#include <unordered_map>


using grid = int;

class Engine
{

public:
    Engine ( Entity_data& entity_data ) ;
    ~Engine ( ) ;
    void run ( );
    Entity_data& get_entity_data ( );
    void init_grid ( );
private:    
    Entity_data entity_data;
    Graphics graphics;
    std::unordered_map < grid, std::vector <Entity> > Grid_map; 

};
