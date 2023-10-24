#version 330 core
layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;
// layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 texCoord;

out vec2 uv;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    uv = texCoord;
}