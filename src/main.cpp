
#include <algorithm>
#include <glad/glad.h>

#include <iostream>

#include <GLFW/glfw3.h>
#include <chrono>
#include <memory>
#include <sys/types.h>
#include <thread>

#include "../includes/CubeRenderer.h"
#include "../includes/Shader.h"
#include "../includes/vloop.h"
#include "../includes/Camera.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

std::unique_ptr<Shader> myShader;
std::shared_ptr<Camera> myCamera;

//u_int64_t current;
// IMPORTANT VARIABLES FOR THE window

GLFWwindow *window;
CubeRenderer crender;

// SCREEN WIDTH AND HEIGHT

int SCR_WIDTH = 2000;
int SCR_HEIGHT = 2000;

float lastx = 500;
float lasty = 500;

//TIME SINCE LAST DRAW CALL

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame


bool initialize_window_components() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  // --------------------
  window = glfwCreateWindow(2000, 2000, "Definetly not a window", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetCursorPosCallback(window, mouse_callback);  
  glfwSetMouseButtonCallback(window, mouse_button_callback);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return false;
  }

  return true;
}

void draw() { crender.draw(); }

int main() {
  // glfw: initialize and configure
  // ------------------------------

  if (!initialize_window_components()) {
    std::cout << "ERROR AT INITIALIZING THE WINDOW COMPONENT ABORTING!\n";
    return -1;
  }

  // COMPILE SHADER AND USE Camera HERE

  myCamera = std::shared_ptr<Camera>(new Camera());

  myShader = std::unique_ptr<Shader>(new Shader("../resources/VertexShader.glsl", "../resources/FramgmentShader.glsl"));

  crender.on_initialize("../resources/VertexShader.glsl", "../resources/FramgmentShader.glsl", myCamera);

  
  // uncomment this call to draw in wireframe polygons.
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnable(GL_DEPTH_TEST);  

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {

    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // input
    // -----
    processInput(window);
    
    // render
    // ------
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    draw();



    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  //de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  crender.destroy_cuberenderer();
  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
  
  if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) myCamera.get()->Process_Keyboard(FORWARD, deltaTime);
  if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) myCamera.get()->Process_Keyboard(RIGHT, deltaTime);
  if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) myCamera.get()->Process_Keyboard(BACKWARD, deltaTime);
  if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) myCamera.get()->Process_Keyboard(LEFT, deltaTime);
} 


// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  SCR_HEIGHT = height;
  SCR_WIDTH = width;
  glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
  float xoffset = xpos - lastx;
  float yoffset = lasty - ypos; // reversed since y-coordinates range from bottom to top
  myCamera.get()->process_mouse((xpos - lastx), (lasty - ypos));
  lastx = xpos;
  lasty = ypos;  

}



glm::vec3 positions_to_world_from_screen(glm::vec2 coord) {
    //VIEW PORT SPACE

    //TRANSFORMING INTO NORMALIZED DEVICE COORDINATES
    glm::vec3 ndc_vec3 = glm::vec3(((2.0f * coord.x) / SCR_WIDTH - 1.0f), (1.0f - (2.0f * coord.y) / SCR_HEIGHT), -1.0f);
    
    //TRANSFORMING INTO HOMOHENOUS COORDINATES
    glm::vec4 homogeneous_ndc_vec4 = glm::vec4(ndc_vec3, 1.0f); //1.0f Due to beeing a position in space

    //APPLYING THE INVERSE PROJECTION MATRICE TO TRANSFORM COORDINATES FROM HOMOGENOUS CLIP SPACE ----> EYE SPACE
    glm::vec4 inverse_projection_point = glm::inverse(crender.get_projection()) * homogeneous_ndc_vec4;
    
    //NOW WE NEED TO UNPROJECT ONLY X AND Y PARTS. W WILL BE 0 FOR DIRECTION AND Z WILL BE -1 TO POINT "FORWARD"
    inverse_projection_point = glm::vec4(inverse_projection_point.x, inverse_projection_point.y, -1.0f, 0.0f);

    //NOW WE NEED TO APPLY THE INVERSE VIEW MATRIX!
    glm::mat4 invView = glm::inverse(myCamera.get()->get_view_matrix());
    glm::vec3 ray_world = invView * inverse_projection_point;

    glm::vec3 normalized_ray = glm::normalize(glm::vec3(ray_world.x,ray_world.y,ray_world.z));    


    return ray_world;


}


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        
        double xp, yp;
        glfwGetCursorPos(window, &xp, &yp);

        
        //glm::vec3 altDir = myCamera.get()->c_position + myCamera.get()->c_view_target;
        //glm::vec3 to_point = myCamera.get()->get_camera_position() + glm::vec3(50*direction.x,50*direction.y,50*direction.z);

        glm::vec3 cameraPosition = myCamera.get()->c_position;
        


        glm::vec3 to_point = myCamera.get()->get_camera_position() + glm::vec3(50 * myCamera.get()->c_view_target.x, 50 * myCamera.get()->c_view_target.y , 50 * myCamera.get()->c_view_target.z);
        
        //THIS POSSIBLE ASWELL MOUSE IS ALWAYS IN CENTER SO ITS JUST EASIER WITHOUT THE CALCULATION JUST GET THE CAMREA POSITION AND USE THE VIEW DIRECTION
        //glm::vec3 direction = positions_to_world_from_screen(glm::vec2(500,500));
        //glm::vec3 to_point = myCamera.get()->get_camera_position() + glm::vec3(50 * direction.x, 50 * direction.y , 50 * direction.z);

        std::cout << "Clicked Ray From Point X: " << myCamera.get()->get_camera_position().x << " Y: " << myCamera.get()->get_camera_position().y << " Z: " << myCamera.get()->get_camera_position().z << " To Point X: " << to_point.x << " Y: " << to_point.y << " z: " << to_point.z << "\n";

        crender.insert_ray(myCamera.get()->get_camera_position(),to_point);
    }
}