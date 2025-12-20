#pragma once
#include "models/components/renderobject.h"
#include "models/Entity_data.h"

class Engine
{

public:
    Engine ( Entity_data entity_data ) ;
    ~Engine ( ) ;
    void run ();
private:    
    Entity_data entity_data;

};
