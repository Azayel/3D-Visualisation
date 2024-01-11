#include "../includes/RayRenderer.h"


void RayRenderer::on_initialize(std::string vertex_path, std::string fragment_path, std::shared_ptr<Camera>& _my_Camera){
    RayShader = std::unique_ptr<Shader>(new Shader(vertex_path, fragment_path));
    myCamera = _my_Camera;

    model = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)1000 / (float)1000, 0.1f, 100.0f);

    //Use The Pre-Compiled Shader
    glUseProgram(RayShader->getID());
    //Generate The Vertex Array Objexts and the Buffer Objects
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    //Bind them to the current Buffers
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //Define the size of the vertex holder elements 
    glBufferData(GL_ARRAY_BUFFER, rays.size() * sizeof(float), rays.data(), GL_STATIC_DRAW);
    //Define Positions of each information tuple
    //Location 0 stands for the position of a vertex
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    //Position 1 Stands for the color of the vertex
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
}

void RayRenderer::draw(){
    
  glUseProgram(RayShader->getID());

  model = glm::mat4(1.0f);
  
  int uniformLocation = glGetUniformLocation(RayShader->getID(), "model");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(model));
  
  uniformLocation = glGetUniformLocation(RayShader->getID(), "view");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(myCamera.get()->get_view_matrix()));

  uniformLocation = glGetUniformLocation(RayShader->getID(), "projection");
  glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(projection));

  glBindVertexArray(VAO);

  glDrawArrays(GL_LINES, 0, rays.size());


}

void RayRenderer::insert_ray(glm::vec3 start, glm::vec3 end){


    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    rays.insert(rays.end(), {start.x, start.y , start.z, 0.0f, 0.0f, 0.0f, end.x,end.y,end.z, 0.0f,0.0f,0.0f});
    glBufferData(GL_ARRAY_BUFFER, rays.size() * sizeof(float), rays.data(), GL_STATIC_DRAW);
}

void RayRenderer::destroy_rays(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(RayShader->getID());
}