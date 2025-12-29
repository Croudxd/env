#pragma once
#include "ecs/Entity_data.h"
#include <string>
#include <unordered_map>

class Spawner
{
    public:
        Spawner (Entity_data entity_data ) ;      
        
            
        

        //User can create their own cusotm function, will use this later on.
        void add_entity();


        void add_entity(std::string str);
        

    private:
        void init_map ();
        std::unordered_map<std::string, void(*)()> entity_function_map;
        Entity_data entity_data;
};


