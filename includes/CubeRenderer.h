#pragma once
#include "../includes/Shader.h"
#include "../includes/Camera.h"
#include "../includes/Cubes.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <string>
#include <vector>

class CubeRenderer {
  std::unique_ptr<Shader> CubeShader;
  std::unique_ptr<Shader> RayShader;
  std::unique_ptr<Chunck> myChunck;

  unsigned int VAO, VBO;
  unsigned int rVAO, rVBO;
  glm::mat4 projection;
  glm::mat4 model;
  glm::mat4 view;
  std::shared_ptr<Camera> my_camera;
  unsigned int textureID;
  std::vector<float> rays;
  glm::vec3 lightPosition = glm::vec3(0.0f,10.0f,0.0f);
  float t_minimum = 99999;

std::vector<glm::vec3> cubes;

public:
  
  void on_initialize(std::string vertexShader, std::string fragmentShader, std::shared_ptr<Camera>& camera);
  void draw();
  void destroy_cuberenderer();
  void gen_cubes(int count){
    for(float z = 0.0f; z<count; z+=1.0f){
      for(float x = 0.0f; x < count; x+=1.0f){
        cubes.insert(cubes.end(), {glm::vec3(x,0.0f,z)});
      }
    }
  }


  const glm::mat4 get_projection() const{
    return projection;
  }

  void cast_ray(glm::vec3 from, glm::vec3 to);

};

