#pragma once
#include "ecs/Entity_data.h"
#include <string>
#include <unordered_map>

using entity_func = void ( * ) (Entity_data& entity_data);

class Spawner
{
    public:
        Spawner ( Entity_data& entity_data ) ;      
        //User can create their own cusotm function, will use this later on.
        void add_entity ();

        void add_entity ( std::string str );
        
        static std::unordered_map<std::string, entity_func>& get_map ();

    private:
        Entity_data& entity_data;
};

#define REGISTER_ENTITY(name, func) \
    static inline bool reg_##func = []() { \
        Spawner::get_map()[name] = func; \
        return true; \
    }();

