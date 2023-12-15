cmake_minimum_required(VERSION 3.5.0)
project(Visua3D VERSION 0.1.0)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

link_directories(lib/glfw-3.8.8)

include_directories(includes/glad)
include_directories(includes/KHR)
include_directories(includes/glm)

include_directories(includes)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(Visual3D ${SOURCES} src/glad.c)
add_subdirectory(lib/glfw-3.3.8)

target_link_libraries(Visual3D glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Visual3D OpenGL::GL)
file(COPY resources DESTINATION /)