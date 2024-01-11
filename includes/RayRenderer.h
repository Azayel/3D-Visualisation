#pragma once 
#include "../includes/Shader.h"
#include "../includes/Camera.h"

#include <memory>
#include <Vector>
#include <String>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class RayRenderer{

    unsigned int VAO, VBO;
    std::unique_ptr<Shader> RayShader;
    std::shared_ptr<Camera> myCamera;
    std::vector<float> rays;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;

    public:

    void on_initialize(std::string vertex_path,std::string fragment_path, std::shared_ptr<Camera>&);
    void draw();
    void destroy_rays();
    void insert_ray(glm::vec3, glm::vec3);
        
};