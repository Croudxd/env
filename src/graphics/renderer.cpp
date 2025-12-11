#include "renderer.h"
#include "shaders.h"
#include <cstddef>
#include <glad/glad.h>
#include <iostream>

#include <GLFW/glfw3.h>
#include <cstdio>
#include <vector>

int renderer(std::vector<RenderObject> &objects) {
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // Create window
  GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    return -1;

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    printf("Vertex Shader Compilation Error:\n%s\n", infoLog);
  }

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    printf("Fragment Shader Compilation Error:\n%s\n", infoLog);
  }

  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    printf("Shader Program Linking Error:\n%s\n", infoLog);
  }
  for (auto &x : objects) {
    auto i = x.init_buffers();
    if (i != 0) {
      std::cout << "Error";
    }
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto &x : objects) {
      glBindBuffer(GL_ARRAY_BUFFER, x.get_vbo());
      glBufferSubData(GL_ARRAY_BUFFER, 0,
                      x.get_vertices().size() * sizeof(float),
                      static_cast<const void *>(x.get_vertices().data()));
      glUseProgram(shaderProgram);
      glBindVertexArray(x.get_vao());
      glDrawArrays(GL_TRIANGLES, 0, x.get_vertices().size() / 6);
      glBindVertexArray(0);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  for (auto &x : objects) {
    glDeleteVertexArrays(1, &x.get_vao());
    glDeleteBuffers(1, &x.get_vbo());
    glDeleteProgram(shaderProgram);
  }
  glfwTerminate();
  return 0;
}
