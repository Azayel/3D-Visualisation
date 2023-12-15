#version 460 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec2 TextureCoordinates;
layout (location = 2) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 TextCoordinates;
out vec3 normals;
out vec3 FragPos;
void main()
{   
    TextCoordinates = TextureCoordinates;
    normals = normal;
    FragPos = aPos;
    gl_Position = projection * view * model * vec4(aPos, 1.0); 

}
