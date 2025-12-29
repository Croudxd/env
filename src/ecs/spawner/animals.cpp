#include <iostream>
#include "ecs/Entity_data.h"
#include "spawner.h"
#include "shape/shape.h"



void fox ( Entity_data& entity_data )
{
    int id = entity_data.entity_vec.size();
    Shape shape;
    std::vector<float> vertices = shape.create_shape ( "square", "green" );
    entity_data.entity_vec.push_back ( id );
    entity_data.render_map.emplace (  id , RenderObject ( vertices ) );
    entity_data.render_map.at(id).init_buffers();
    entity_data.perception_map.emplace(id, Perception{0.3f, 0.3f});
}
REGISTER_ENTITY ( "fox", fox );

void tree ( Entity_data& entity_data )
{
    int id = entity_data.entity_vec.size();
    Shape shape;
    std::vector<float> vertices = shape.create_shape ( "triangle", "blue" );
    entity_data.entity_vec.push_back ( id );
    entity_data.render_map.emplace (  id , RenderObject ( vertices ) );
    entity_data.render_map.at(id).init_buffers();
    entity_data.perception_map.emplace(id, Perception{0.3f, 0.3f});
}
REGISTER_ENTITY ( "tree", tree );
