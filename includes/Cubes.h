#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

enum blocktype { Wood, Air };

// THIS SHOULD BE A CUBE IN A CHUNK
struct Cube {

  glm::vec3 min;
  glm::vec3 max;

  // A Cube has definetly an position -> Meaning a translation Vector
  glm::vec3 position;
  
  std::pair<glm::vec3, glm::vec3> getBounds() const {
        glm::vec3 minBounds = position;
        glm::vec3 maxBounds = position;

        // Assume a unit cube with side length 2
        float halfSideLength = 0.5f;

        minBounds -= glm::vec3(halfSideLength, halfSideLength, halfSideLength);
        maxBounds += glm::vec3(halfSideLength, halfSideLength, halfSideLength);

        return std::make_pair(minBounds, maxBounds);
    }
  // A Cube has definetly some kind of texture -> Use the enum to diferentiate
  // between types
  blocktype type;

  Cube(glm::vec3 pos, blocktype t): position(pos), type(t){}
  Cube() = default;
};

// A Chunck stores 16x16x16 cubes meaning 4096 cubes in one chunck!
struct Chunck {
  constexpr static float vertices[] = {
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

  unsigned int vbo, vao;
  std::vector<Cube> stored_cubes;
  std::vector<float> stored_vertices;
  glm::mat4 projection;
  unsigned int textureID;

  // On Initialization of a chunck this function should create and fill a chunck
  // with cubes.
  void create_chunck();
  // After modifying a member cube of a chunck the coresponding chuck should
  // recalculate  its mesh And Cull all faces which are not seen
  void update_mesh();
};
