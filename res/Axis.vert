#version 410

//uniform mat4 matrix;
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

out vec4 v4Color;

uniform mat4 transform;

void main()
{
    v4Color = color;
    gl_Position = transform * position;
}