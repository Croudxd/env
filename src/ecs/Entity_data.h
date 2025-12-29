#pragma once
#include <unordered_map>
#include <vector>

#include "ecs/components/renderobject.h"
#include "ecs/components/endurance.h"
#include "ecs/components/energy.h"
#include "ecs/components/hunger.h"
#include "ecs/components/eater_type.h"
#include "ecs/components/max_age.h"
#include "ecs/components/max_speed.h"
#include "ecs/components/perception.h"
#include "ecs/components/rate_of_growth.h"
#include "ecs/components/sleep.h"
#include "ecs/components/status.h"
#include "ecs/components/visable_entities.h"



using Entity = int;


struct Entity_data
{
    Entity_data() = default;
    Entity_data(const Entity_data&) = delete;  
    std::vector<Entity> entity_vec;
    std::unordered_map<Entity, RenderObject> render_map;  
    std::unordered_map<Entity, Eater_type> eater_type_map;
    std::unordered_map<Entity, Endurance> endurance_map;
    std::unordered_map<Entity, Energy> energy_map;
    std::unordered_map<Entity, Hunger> hunger_map;
    std::unordered_map<Entity, Max_age> max_age_map;
    std::unordered_map<Entity, Max_speed> max_speed_map;
    std::unordered_map<Entity, Perception> perception_map;
    std::unordered_map<Entity, Rate_of_growth> rate_of_growth_map;
    std::unordered_map<Entity, Sleep> sleep_map;
    std::unordered_map<Entity, Status> status_map;
    std::unordered_map<Entity, Visable_entities> visable_entities_map;
};
 
