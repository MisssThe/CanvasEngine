       ShaderAssetr      #version 330 core
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
}�      #version 330 core

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
}       	       normalTex   	       albedoTex   