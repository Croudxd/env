#include <utility>
#include <vector>
class RenderObject {
public:
  RenderObject(std::vector<float> vertices);
  int init_buffers();
  unsigned int &get_vbo() { return this->VBO; };
  unsigned int &get_vao() { return this->VAO; };
  std::vector<float> &get_vertices() { return this->vertices; };

private:
  unsigned int VBO;
  unsigned VAO;
  std::vector<float> vertices;
};
