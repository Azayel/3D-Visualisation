
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


std::unique_ptr<Shader> myShader;
std::shared_ptr<Camera> myCamera;

u_int64_t current;
// IMPORTANT VARIABLES FOR THE window

GLFWwindow *window;
CubeRenderer crender;

// SCREEN WIDTH AND HEIGHT

int SCR_WIDTH = 1000;
int SCR_HEIGHT = 1000;


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
  window = glfwCreateWindow(1000, 1000, "Definetly not a window", NULL, NULL);

  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


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
