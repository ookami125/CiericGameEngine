#version 330 core
uniform sampler2D tex;
in vec2 uvCoord;

out vec4 color;

void main()
{
	color = texture(tex, uvCoord);
	if(color.a<1.0) discard;
}