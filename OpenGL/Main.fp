#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
	vec4 baseColor = texture(tex0, TexCoord) * vec4(ourColor,1.0);
	FragColor = mix(	baseColor, 
						texture(tex1, TexCoord), 
						texture(tex1, TexCoord).a * 0.9) ;
}