       ShaderAssetz       #version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}      #version 330 core

layout (location = 0) out vec4 gPosition;
layout (location = 1) out vec4 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

void main()
{
    gPosition = vec4(0.5, 1.0, 0.5, 1.0);
    gNormal = vec4(1.0, 0.5, 0.5, 1.0);
    gAlbedoSpec = vec4(0.5, 0.5, 1.0, 1.0);
}        