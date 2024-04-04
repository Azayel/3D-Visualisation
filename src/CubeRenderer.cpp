#include "../includes/CubeRenderer.h"
#include "../includes/Camera.h"
#include "../includes/Cubes.h"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <limits>
#include <iostream>
#include <memory>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

float t_minimum = 9999;

static unsigned int loadTexture(char const *path) {
  unsigned int textureID;
  glGenTextures(1, &textureID);

  int width, height, nrComponents;
  unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
  if (data) {
    GLenum format;
    if (nrComponents == 1)
      format = GL_RED;
    else if (nrComponents == 3)
      format = GL_RGB;
    else if (nrComponents == 4)
      format = GL_RGBA;

    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
        format == GL_RGBA
            ? GL_CLAMP_TO_EDGE
            : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent
                          // semi-transparent borders. Due to interpolation it
                          // takes texels from next repeat
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                    format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
  } else {
    std::cout << "Texture failed to load at path: " << path << std::endl;
    stbi_image_free(data);
  }

  return textureID;
}

void CubeRenderer::on_initialize(std::string vertexfn, std::string fragmentfn,
                                 std::shared_ptr<Camera> &_my_Camera) {

  // Creating Cube Shader Object using unique pointer. Cube Renderer has soly
  // the rights to the object!
  CubeShader = std::unique_ptr<Shader>(new Shader(vertexfn, fragmentfn));
  RayShader = std::unique_ptr<Shader>(
      new Shader("../resources/RayVertexShader.glsl",
                 "../resources/RayFragmentShader.glsl"));
  my_camera = _my_Camera;

  // Some Initial Setups for the MVP Matrrice

  // model = glm::rotate(glm::scale(glm::mat4(1.0f),glm::vec3(1.0f,1.0f,1.0f)),
  // glm::radians(45.0f),glm::vec3(1.0f,1.0f,0.0f)); view =
  // glm::lookAt(glm::vec3(0.0f,0.0f,3.0f),
  // glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
  model = glm::mat4(1.0f);
  projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)1000,
                                0.1f, 100.0f);

  float vertices[] = {
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f,
      -0.5f, 1.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  -0.5f, 1.0f,
      1.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  -0.5f, 1.0f,  1.0f,  0.0f,
      0.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,

      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f,
      0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,
      1.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,  0.5f,  1.0f,  1.0f,  0.0f,
      0.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
      -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,

      -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,  -0.5f, 0.5f,
      -0.5f, 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,
      1.0f,  1.0f,  0.0f,  0.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  1.0f,
      0.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
      -0.5f, 0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,

      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,
      -0.5f, 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 0.0f,
      1.0f,  1.0f,  0.0f,  0.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  1.0f,  1.0f,
      0.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
      0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  1.0f,  0.0f,  0.0f,

      -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  -0.5f,
      -0.5f, 1.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,
      0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  1.0f,  0.0f,  0.0f,
      1.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      -0.5f, -0.5f, -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,

      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,
      -0.5f, 1.0f,  1.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,
      0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
      1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      -0.5f, 0.5f,  -0.5f, 0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
  };

  // Just generating cubes directly
  //gen_cubes(10);

  // Generating a chung

  myChunck = std::unique_ptr<Chunck>(new Chunck{});
  myChunck->create_chunck();

  // After this line we have created 16*16*16 cubes => 4096 cubes.
  // Each Cube has 6*2*3 verticies = 36 Vertices
  // Meaning each Chunck has a total of 4096 * 36 = 147456 Vertices
  // Remind: These Chuncks have not been meshed. (Face culling of meshes that
  // are not visible by the camera)

  // Cube Renderer Projection Matrix
  // projection =  glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f,
  // 0.1f, 100.0f);

  textureID = loadTexture("../resources/wood.png");

  glUseProgram(CubeShader->getID());
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, myChunck->stored_vertices.size(),
               myChunck->stored_vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
                        (void *)(5 * sizeof(float)));
  glEnableVertexAttribArray(2);
}

void CubeRenderer::draw() {

  glUseProgram(CubeShader->getID());
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);
  glBindVertexArray(VAO);

  int uniformLocation = glGetUniformLocation(CubeShader->getID(), "view");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE,
                     glm::value_ptr(my_camera.get()->get_view_matrix()));

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "projection");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "viewPos");
  glUniform3f(uniformLocation, my_camera.get()->c_position.x,
              my_camera.get()->c_position.y, my_camera.get()->c_position.z);

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "lightPos");
  glUniform3f(uniformLocation, lightPosition.x, lightPosition.y,
              lightPosition.z);

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "model");
  for (Cube c : myChunck->stored_cubes) {
    model = glm::mat4(1.0f);
    model = glm::translate(model, c.position);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }
}

// https://gist.github.com/DomNomNom/46bb1ce47f68d255fd5d
// https://education.siggraph.org/static/HyperGraph/raytrace/rtinter3.htm#:~:text=We%20can%20use%20a%20box,bounding%20volume%20or%20a%20box.
// https://www.sciencedirect.com/topics/computer-science/aligned-bounding-box
// https://gamedev.stackexchange.com/questions/18436/most-efficient-aabb-vs-ray-collision-algorithms
bool AABB(const glm::vec3 &local_ray_origin,
          const glm::vec3 &local_ray_direction) {
  // Bounding Box
  glm::vec3 min_bound = glm::vec3(-0.5f, -0.5f, -0.5f);
  glm::vec3 max_bound = glm::vec3(0.5f, 0.5f, 0.5f);

  // Compute t-values for each pair of planes
  //  Point = Origin + t * direction | - Origin
  //  Point - Origin = t * direction | : Directopm
  //  (Point -  Origin) / Directiom = t
  glm::vec3 t_min = (min_bound - local_ray_origin) / local_ray_direction;
  glm::vec3 t_max = (max_bound - local_ray_origin) / local_ray_direction;

  // WHY?
  float t_enter =
      glm::max(glm::max(glm::min(t_min.x, t_max.x), glm::min(t_min.y, t_max.y)),
               glm::min(t_min.z, t_max.z));
  float t_exit =
      glm::min(glm::min(glm::max(t_min.x, t_max.x), glm::max(t_min.y, t_max.y)),
               glm::max(t_min.z, t_max.z));

  // RAY INTERSECTS UNDER THIS CONDITION. But WYH?
  return t_enter < t_exit;
}

bool AABB1(const glm::vec3 &local_ray_origin,
           const glm::vec3 &local_ray_direction) {
  // Bounding Box
  glm::vec3 min_bound = glm::vec3(-0.5f, -0.5f, -0.5f);
  glm::vec3 max_bound = glm::vec3(0.5f, 0.5f, 0.5f);

  float Tnear = -std::numeric_limits<float>::infinity();
  float Tfar = std::numeric_limits<float>::infinity();

  for (int i = 0; i < 3; i++) {

    if (local_ray_direction[i] == 0) {
      std::cout << "ray dir 0!\n";

      return false;
    }

    /*
    Are in NDC of object dont care
    if(local_ray_origin[i] < min_bound[i] || local_ray_origin[i] >
    max_bound[i]){ std::cout << "big or!\n";

      return false;
    }
    */

    float t_1 = (min_bound[i] - local_ray_origin[i]) / local_ray_direction[i];
    float t_2 = (max_bound[i] - local_ray_origin)[i] / local_ray_direction[i];

    if (t_1 > t_2) {
      float temp = t_1;
      t_1 = t_2;
      t_2 = temp;
      std::cout << "swap!\n";
    }

    if (t_1 > Tnear) {
      Tnear = t_1;
    }

    if (t_2 < Tfar) {
      Tfar = t_2;
    }

    if (Tnear > Tfar) {
      std::cout << "Tnear > tfar!\n";

      return false;
    }

    if (Tfar < 0) {
      std::cout << "Tfar < 0!\n";

      return false;
    }
  }

  return true;
}

bool AABB2(const glm::vec3 &local_ray_origin,
           const glm::vec3 &local_ray_direction, glm::vec3 min_bound,
           glm::vec3 max_bound) {

  // Compute t-values for each pair of planes
  //  Point = Origin + t * direction | - Origin
  //  Point - Origin = t * direction | : Directopm
  //  (Point -  Origin) / Directiom = t
  glm::vec3 t_min = (min_bound - local_ray_origin) / local_ray_direction;
  glm::vec3 t_max = (max_bound - local_ray_origin) / local_ray_direction;

  // WHY?
  float t_enter =
      glm::max(glm::max(glm::min(t_min.x, t_max.x), glm::min(t_min.y, t_max.y)),
               glm::min(t_min.z, t_max.z));
  float t_exit =
      glm::min(glm::min(glm::max(t_min.x, t_max.x), glm::max(t_min.y, t_max.y)),
               glm::max(t_min.z, t_max.z));

  // RAY INTERSECTS UNDER THIS CONDITION. But WYH?
  bool has_intersection = t_enter < t_exit;
  
  if(has_intersection && (t_minimum < 0.0f || t_enter < t_minimum)){
    t_minimum = t_enter;
  }

  return has_intersection;

}


Cube find_intersected_cube(glm::vec3 &origin, glm::vec3 &direction, std::vector<Cube> &cubes ){
  Cube nearestCube;
  float nearestDistance = std::numeric_limits<float>::infinity();
  
  for (const Cube& c : cubes) {
    auto bounds = c.getBounds();
    if(AABB2(origin, direction, bounds.first , bounds.second)){
      nearestCube = c;
    }
  }

  return nearestCube;
}

// TODO: Universal Function for multiple Chuncks. SEGMENTATION FAULT WHEN
// TRIGGERING TO MANY CUBES AT THE SAME TIME!
void CubeRenderer::cast_ray(glm::vec3 from, glm::vec3 to) {
  glm::vec3 direction = my_camera.get()->c_view_target;
  // cubes is translation of the original cube

  glm::vec3 cubePos;
  /*
  for (Cube c : myChunck->stored_cubes) {

    glm::vec3 pos = c.position;
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    glm::mat4 modelInverse = glm::inverse(model);

    glm::vec3 local_ray_origin =
        modelInverse * glm::vec4(from.x, from.y, from.z, 1.0f);
    glm::vec3 local_ray_direction =
        modelInverse * glm::vec4(direction.x, direction.y, direction.z, 0.0f);

  
  }
  */
  auto ca = find_intersected_cube(from,to,(myChunck->stored_cubes));
  std::cout << "Cube found:  " << ca.position.x << " " << ca.position.y << " " << ca.position.z << std::endl;
}

void CubeRenderer::destroy_cuberenderer() {

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(CubeShader->getID());

}
