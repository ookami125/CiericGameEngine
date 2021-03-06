#version 330 core
uniform mat4 MVP;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 coords;

out vec2 uvCoord;

void main()
{
    gl_Position = vec4(position, 1.0) * MVP;
	uvCoord = coords;
} 