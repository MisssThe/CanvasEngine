       ShaderAsset%      #version 330 core
layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;
// layout (location = 2) in vec3 normal;
layout (location = 3) in vec2 texCoord;

out vec2 uv;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    uv = texCoord;
}w      #version 330 core

layout (location = 0) out vec4 albedoOut;
layout (location = 1) out vec4 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in vec2 uv;

uniform sampler2D albedoTex;

void main()
{
    vec4 albedo = vec4(texture(albedoTex, uv));
    albedoOut = vec4(albedo.xyz, 1.0);
    gNormal = vec4(1.0, 0.5, 0.5, 1.0);
    gAlbedoSpec = vec4(0.5, 0.5, 1.0, 1.0);
}        