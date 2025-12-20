#pragma once
#include <unordered_map>
#include <vector>

#include "models/components/renderobject.h"
#include "models/components/endurance.h"
#include "models/components/energy.h"
#include "models/components/hunger.h"
#include "models/components/eater_type.h"
#include "models/components/max_age.h"
#include "models/components/max_speed.h"
#include "models/components/perception.h"
#include "models/components/rate_of_growth.h"
#include "models/components/sleep.h"
#include "models/components/status.h"



using Entity = int;


struct Entity_data
{
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
    

};
