#pragma once
#include "../includes/Cubes.h"
#include <iostream>
void Chunck::create_chunck() {
  // For Testing Cases We will fill the chunck with half air and half cubes type
  // wood

  for (float y = 0; y < 16.; y++) {
    for (float x = 0; x < 16.; x++) {
      for (float z = 0; z < 16.; z++) {
        stored_cubes.push_back(Cube{glm::vec3(x, y, z), blocktype::Wood});

        stored_vertices.insert(stored_vertices.end(),{
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, -0.5f,
            -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
            0.0f, 0.0f, 1.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, -0.5f, -0.5f,
            -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, -0.5f, 0.5f,
            1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, -0.5f,
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, -0.5f, -0.5f, 0.5f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f,

            -0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.5f, -0.5f,
            1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
            0.0f, 0.0f, -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.5f, 0.5f,
            1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f, -0.5f,
            1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f,
            0.0f, 0.0f, 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f,
            -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f,
            0.0f, 1.0f, 0.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, -0.5f,
            -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -0.5f, -0.5f,
            -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 0.5f, -0.5f,
            1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
            1.0f, 0.0f, 0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -0.5f,
            0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -0.5f, 0.5f, -0.5f, 0.0f,
            1.0f, 0.0f, 1.0f, 0.0f });
      }
    }
  }

  //std::cout << "length of stored_cubes: " << sizeof(stored_vertices) * sizeof(float)<<  std::endl; 
  //Cout << 4096
}
