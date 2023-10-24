#version 330 core

layout (location = 0) out vec4 albedoOut;
layout (location = 1) out vec4 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in vec2 uv;

uniform sampler2D albedoTex;
uniform sampler2D normalTex;

void main()
{
    vec4 albedo = vec4(texture(albedoTex, uv));
    vec4 normal = vec4(texture(normalTex, uv));
    albedoOut = vec4(albedo.xyz * normal.xyz, 1.0);
    gNormal = vec4(1.0, 0.5, 0.5, 1.0);
    gAlbedoSpec = vec4(0.5, 0.5, 1.0, 1.0);
}