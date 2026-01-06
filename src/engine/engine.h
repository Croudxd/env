#pragma once
#include "graphics/Graphics.h"
#include "ecs/Entity_data.h"

class Engine
{

public:
    Engine ( Entity_data& entity_data ) ;
    ~Engine () ;
    void run ();
    Entity_data& get_entity_data ();
private:    
    bool perception_brute_force ();
    void compute_entity_behaviour ();
    Entity_data &entity_data;
    Graphics graphics;

};
