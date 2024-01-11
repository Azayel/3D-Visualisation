#pragma once
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Vector>

enum blocktype{
    Wood,
    Air
};


// THIS SHOULD BE A CUBE IN A CHUNK
struct Cube{

    //A Cube has definetly an position -> Meaning a translation Vector
    glm::vec3 position;

    //A Cube has definetly some kind of texture -> Use the enum to diferentiate between types
    blocktype type;

};

//A Chunck stores 16x16x16 cubes meaning 4096 cubes in one chunck!
struct Chunck{

    unsigned int vbo, vao;
    std::vector<Cube> stored_cubes;
    glm::mat4 projection;
    unsigned int textureID;


    //On Initialization of a chunck this function should create and fill a chunck with cubes.
    void create_chunck();
    //After modifying a member cube of a chunck the coresponding chuck should recalculate  its mesh
    //And Cull all faces which are not seen
    void update_mesh();



};