cmake_minimum_required(VERSION 3.0.0)
project(Visua3D VERSION 0.1.0)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

link_directories(libs/glfw)

include_directories(includes/glad)
include_directories(includes/KHR)
include_directories(includes)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(Visual3D ${SOURCES} src/glad.c)

target_link_libraries(Visual3D glfw dl)

