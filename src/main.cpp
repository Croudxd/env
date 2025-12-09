#include <glad/glad.h>
#include <vector>

#include "graphics/renderer.h"
#include <GLFW/glfw3.h>

std::vector<float> vertices = {

    -0.8f, -0.8f, 0.0f, 1.0f, 0.0f, 0.0f, // Vertex 1 (position and color)
    0.0f,  0.8f,  0.0f, 0.0f, 1.0f, 0.0f, // Vertex 2 (position and color)
    0.8f,  -0.8f, 0.0f, 0.0f, 0.0f, 1.0f  // Vertex 3 (position and color)

};
std::vector<float> vertices2 = {

    -0.9f, 0.4f, 0.0f, 1.0f, 0.0f, 1.0f, // Vertex 1 (position and color)
    0.0f,  1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Vertex 2 (position and color)
    0.9f,  0.4f, 0.0f, 0.0f, 1.0f, 1.0f  // Vertex 3 (position and color)

};
std::vector<float> vertices3 = {

    -0.6f, 0.0f,  0.0f, 1.0f, 1.0f, 0.0f, // Vertex 1 (position and color)
    0.0f,  -0.6f, 0.0f, 0.0f, 1.0f, 1.0f, // Vertex 2 (position and color)
    0.6f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f  // Vertex 3 (position and color)

};

std::vector<std::vector<float>> vec_objects = {vertices, vertices2, vertices3};
int main() {
  // Create renderObjects vector for each object we want to render
  // pass to renderer

  std::vector<RenderObject> objects;
  for (auto &x : vec_objects) {
    auto object = RenderObject{x};
    objects.push_back(object);
  }
  renderer(objects);
}
