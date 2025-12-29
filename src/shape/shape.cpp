#include "shape.h"
#include <vector>

Shape::Shape ()
{

    create_shape_map();
    create_color_map();


};

void Shape::create_shape_map () 
{
    this->shape_map.emplace("triangle", 18);
    this->shape_map.emplace("square", 36);
}

void Shape::create_color_map () 
{
    this->color_map.emplace("green", 18);
    this->color_map.emplace("blue", 18);
    this->color_map.emplace("red", 18);
}

std::vector<float> Shape::create_shape (std::string shape, std::string color, float size)
{
    int shape_size = shape_map [ shape ];
    float color_code = color_map [ color ];
    int vertex_count = shape_size / 6;

    std::vector<float> vertices;
    for ( int x = 0; x <= shape_size ; x++ )
    {
        vertices.push_back(0.0);
    }
    //Difficult part is here. i actually dont know what to do tbh.
}

