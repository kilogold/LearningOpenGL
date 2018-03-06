#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
  
uniform vec3 lightPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    float ambientStrength = 0.01;
    vec3 ambient = ambientStrength * lightColor;

	//diffuse
	vec3 vecFragToLight = normalize(lightPos - FragPos);
	float diffuse_normal_scale = max(dot(normalize(Normal),vecFragToLight), 0.0);
	vec3 diffuse = lightColor * diffuse_normal_scale;

    FragColor = vec4((diffuse + ambient) * objectColor, 1.0);
}