#version 330 core

out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D albedoTex;
uniform sampler2D

void main()
{
    FragColor = texture(screenTexture, TexCoords);
}