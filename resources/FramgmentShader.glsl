#version 460 core
out vec4 FragColor;
  
in vec3 VertexColor;


void main()
{
    FragColor = vec4(VertexColor.xyz, 0.0);
} 
