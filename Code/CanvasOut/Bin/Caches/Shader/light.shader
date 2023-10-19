       ShaderAsset�       #version 330 core

layout (location = 0) in vec3 pos;
layout (location = 2) in vec2 texCoord;
out vec2 TexCoords;

void main()
{
    TexCoords = texCoord;
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}�       #version 330 core

out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D albedoTex;
uniform sampler2D

void main()
{
    FragColor = texture(screenTexture, TexCoords);
}        