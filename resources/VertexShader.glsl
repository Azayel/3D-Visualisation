#version 460 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vertexColor; // specify a color output to the fragment shader

void main()
{   
    gl_Position = projection * view * model * vec4(aPos, 1.0); 
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
}
