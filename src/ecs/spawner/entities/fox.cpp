#include "headers.h"

void fox ( Entity_data& entity_data )
{
    int id = entity_data.entity_vec.size();
    Shape shape;
    std::vector<float> vertices = shape.create_shape ( "square", "orange" );

    entity_data.entity_vec.push_back ( id );
    entity_data.render_map.emplace (  id , RenderObject ( vertices ) );
    entity_data.render_map.at(id).init_buffers();
    entity_data.perception_map.emplace(id, Perception{0.3f, 0.3f});
    // entity_data.eater_type_map.emplace(id, Carnivore);
    // entity_data.energy_map.emplace(id, Energy { 100.0 });
    // entity_data.hunger_map.emplace(id, Hunger { 100.0 });
    // entity_data.max_speed_map.emplace(id, Max_speed { 10  });
    // entity_data.status_map.emplace(id, Status::Idle );
    // entity_data.visable_entities_map.emplace(id,  Visable_entities { });
}
REGISTER_ENTITY ( "fox", fox );

