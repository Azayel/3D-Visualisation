#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>


enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};


class Camera{
    
    //Initialize Initial CameraPosition and camara Matrice
    glm::vec3 c_position;
    glm::vec3 c_view_target;
    glm::vec3 lookUp;
    float yaw = -90.0f;
    float pitch = 0.0f;




    public:
    
    Camera(glm::vec3 position = glm::vec3(0.0f,0.0f, 3.0f),  glm::vec3 view_target = glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3 lu = glm::vec3(0.0f,1.0f,0.0f)){
        c_position = position;
        c_view_target = view_target;
        lookUp = lu;
    }

    //Return the view matrix
    glm::mat4 get_view_matrix() const{
        return glm::lookAt(c_position, c_position + c_view_target, lookUp);;
    }

    void Process_Keyboard(Camera_Movement direction, float deltaTime){
        if(direction == FORWARD) c_position += 2.5f * deltaTime * c_view_target;
        if(direction == BACKWARD) c_position -= 2.5f * deltaTime * c_view_target;
        if(direction == RIGHT) c_position -= glm::normalize(glm::cross(c_view_target, lookUp)) * (2.5f * deltaTime);
        if(direction == LEFT) c_position += glm::normalize(glm::cross(c_view_target, lookUp)) * (2.5f * deltaTime) ;

    }


    void process_mouse(float xoffset, float yoffset){

        const float sensitivity = 0.1f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;


        yaw   += xoffset;
        pitch += yoffset;

         if(pitch > 89.0f)
        pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        c_view_target = glm::normalize(direction);
    }

};