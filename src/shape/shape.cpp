#include "shape.h"
#include <vector>
#include <random>

Shape::Shape ()
{
    create_shape_map();
    create_color_map();
};

void Shape::create_shape_map () 
{
    this->shape_map.emplace("triangle", 18);
    this->shape_map.emplace("square", 24);
}

void Shape::create_color_map () 
{
    this->color_map.emplace("green", std::vector<float> {0.0, 1.0, 0.0});
    this->color_map.emplace("blue", std::vector<float> {0.0, 0.0, 1.0});
    this->color_map.emplace("red", std::vector<float> {1.0, 0.0, 0.0});
}



std::vector<float> Shape::create_shape ( std::string shape, std::string color )
{
    static std::random_device rd;
    static std::mt19937 gen ( rd() );
    std::uniform_real_distribution<float> distr ( -0.8, 0.8 );
    float rand_x = distr ( gen );
    float rand_y = distr ( gen );

    int shape_size = shape_map [ shape ];
    std::vector<float> color_code = color_map [ color ];
    int vertex_count = shape_size / 6;

    std::vector<float> vertices;

    const float radius = 0.1f; 
    const float PI = 3.1415926535f;
    float start_angle =  ( vertex_count == 3 ) ? ( PI / 2.0f ) : ( PI / 4.0f );
    float angle_step = (2.0f * PI) / vertex_count;

    for ( int i = 0; i < vertex_count; i++ )
    {
        float current_angle = start_angle + ( i * angle_step );
        float offsetX = cos( current_angle ) * radius;
        float offsetY = sin ( current_angle ) * radius;

        vertices.push_back ( rand_x + offsetX );
        vertices.push_back ( rand_y + offsetY );
        vertices.push_back ( 0.0f );

        vertices.push_back ( color_code [0] ); 
        vertices.push_back ( color_code [1] );
        vertices.push_back ( color_code [2] );
    }
    return vertices;
}

