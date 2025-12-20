#pragma once
#include <vector>
class RenderObject {
public:
  RenderObject() = default;
  RenderObject(std::vector<float> vertices);
  ~RenderObject () ;
  int init_buffers();
  unsigned int &get_vbo() { return this->VBO; };
  unsigned int &get_vao() { return this->VAO; };
  std::vector<float> &get_vertices() { return this->vertices; };

  void set_vertices(std::vector<float> vertices) { this->vertices = vertices; };

private:
  unsigned int VBO;
  unsigned VAO;
  std::vector<float> vertices;
};
