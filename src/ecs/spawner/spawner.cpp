#include "ecs/spawner/spawner.h"
#include "ecs/Entity_data.h"

Spawner::Spawner ( Entity_data& entity_data ) : entity_data(entity_data)
{

}

std::unordered_map<std::string, entity_func>& Spawner::get_map ()
{
    static std::unordered_map<std::string, entity_func> internal_map;
    return internal_map;
}

void Spawner::add_entity ( std::string name )
{
    auto& m = get_map();
    if ( m.count ( name ) )
    {
        m[name]( /* we can add parameters here. */ this->entity_data);
    }
}

void Spawner::add_entity ()
{

}

