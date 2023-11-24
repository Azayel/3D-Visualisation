#include "../includes/CubeRenderer.h"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include "../includes/Camera.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"





void CubeRenderer::on_initialize(std::string vertexfn, std::string fragmentfn, std::shared_ptr<Camera>& _my_Camera) {


  //Creating Cube Shader Object using unique pointer. Cube Renderer has soly the rights to the object!
  CubeShader = std::unique_ptr<Shader>(new Shader(vertexfn, fragmentfn));
  my_camera = _my_Camera;



  //Some Initial Setups for the MVP Matrrice
  
  //model = glm::rotate(glm::scale(glm::mat4(1.0f),glm::vec3(1.0f,1.0f,1.0f)), glm::radians(45.0f),glm::vec3(1.0f,1.0f,0.0f));
  //view = glm::lookAt(glm::vec3(0.0f,0.0f,3.0f), glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,1.0f,0.0f));
  model = glm::mat4(1.0f);
  projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)1000, 0.1f, 100.0f);


  float vertices[] = {
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,0.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,0.0f, 1.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,0.0f, 0.0f, 1.0f,

         0.5f,  0.5f,  0.5f,1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,1.0f, 1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,1.0f, 1.0f, 0.0f,
         0.5f, -0.5f, -0.5f,1.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,1.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,1.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,1.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,1.0f, 0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,0.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,0.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,0.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,0.0f, 1.0f, 1.0f,
    };


    gen_cubes(1);

 
  //Cube Renderer Projection Matrix
  //projection =  glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f, 0.1f, 100.0f);



  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glGenVertexArrays(1, &rVAO);
  glGenBuffers(1, &rVBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
  glEnableVertexAttribArray(1);


  glBindVertexArray(rVAO);
  glBindBuffer(GL_ARRAY_BUFFER, rVBO);
  glBufferData(GL_ARRAY_BUFFER, rays.size() * sizeof(float), rays.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
  glEnableVertexAttribArray(1);
}

void CubeRenderer::draw() {


  glUseProgram(CubeShader->getID());

  glBindVertexArray(VAO);

  int uniformLocation = glGetUniformLocation(CubeShader->getID(), "view");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(my_camera.get()->get_view_matrix()));

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "projection");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));

  uniformLocation = glGetUniformLocation(CubeShader->getID(), "model");
  for(glm::vec3 pos: cubes){
    model = glm::mat4(1.0f);
    model = glm::translate(model, pos);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);

  }

  model = glm::mat4(1.0f);
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
  
  glBindVertexArray(rVAO);

  glDrawArrays(GL_LINES, 0, rays.size());


    


}


void CubeRenderer::insert_ray(glm::vec3 from, glm::vec3 to){
  
  glBindVertexArray(rVAO);
  glBindBuffer(GL_ARRAY_BUFFER, rVBO);
  rays.insert(rays.end(), {from.x, from.y , from.z, 0.0f, 0.0f, 0.0f, to.x,to.y,to.z, 0.0f,0.0f,0.0f});
  glBufferData(GL_ARRAY_BUFFER, rays.size() * sizeof(float), rays.data(), GL_STATIC_DRAW);
  std::cout << "Size: " << rays.size() << "\n";
  glBindVertexArray(0);
}

void CubeRenderer::destroy_cuberenderer() {

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(CubeShader->getID());
}
