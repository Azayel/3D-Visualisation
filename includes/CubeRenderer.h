#pragma once
#include "../includes/Shader.h"
#include <glm/glm.hpp>
#include <memory>
#include <vector>

class CubeRenderer {
  std::unique_ptr<Shader> CubeShader;
  unsigned int VAO, VBO;

public:
  void on_initialize(char *vertexShader, char *fragmentShader);
  void draw();
  void destroy_cuberenderer();
};

struct Cube {
  std::vector<glm::vec3> vertices;

  void initialize_cube(std::vector<glm::vec3> v) { vertices = v; }
};
