#pragma once
#include "../includes/Shader.h"
#include "../includes/Camera.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>
#include <vector>

class CubeRenderer {
  std::unique_ptr<Shader> CubeShader;
  unsigned int VAO, VBO;
  glm::mat4 projection;
  glm::mat4 model;
  glm::mat4 view;
  std::shared_ptr<Camera> my_camera;

public:
  void on_initialize(std::string vertexShader, std::string fragmentShader, std::shared_ptr<Camera>& camera);
  void draw();
  void destroy_cuberenderer();
};

struct Cube {
  std::vector<glm::vec3> vertices;

  void initialize_cube(std::vector<glm::vec3> v) { vertices = v; }
};