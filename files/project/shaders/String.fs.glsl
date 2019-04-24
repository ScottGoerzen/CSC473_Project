#version 330 core

in VertexData
{
    vec3 position;
    vec3 normal;
    vec2 texCoord;
    vec3 eyeDirection;
    vec3 lightDirection;
    vec3 lightPosition;
} inData;

out vec4 fragColour;

void main()
{
    fragColour = vec4(0.0, 1.0, 0.0, 1.0);
}
