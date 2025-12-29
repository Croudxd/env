#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Shape 
{
    private:
        std::unordered_map<std::string, int> shape_map;
        std::unordered_map<std::string, float> color_map;
        float size_multiplier;
        void create_shape_map () ;
        void create_color_map () ;



    public:
        Shape ();
        std::vector<float> create_shape (std::string shape, std::string color, float size);


};
