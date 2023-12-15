#version 460 core
out vec4 FragColor;
  
in vec2 TextCoordinates;
in vec3 normals;
in vec3 FragPos;
uniform sampler2D text;   
uniform vec3 lightPos;
uniform vec3 viewPos;


void main()
{
    //FragColor = vec4(VertexColor.xyz, 0.0);
    vec3 color = texture(text,TextCoordinates).rgb;
     // ambient
    vec3 ambient = 0.9 * color;
    // diffuse
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 normal = normalize(normals);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * color;
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;

    vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

    vec3 specular = vec3(0.3) * spec; // assuming bright white light color
    FragColor = vec4(ambient + diffuse + specular, 1.0);
} 
