#pragma once
// Vertex shader

const char *vertexShaderSource = R"glsl(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
out vec3 vertexColor;
uniform vec3 uOffset;

void main() {
    gl_Position = vec4(aPos + uOffset, 1.0);
    vertexColor = aColor;
}
)glsl";

// Fragment shader
const char *fragmentShaderSource = R"glsl(
#version 330 core
in vec3 vertexColor;
out vec4 FragColor;

void main() {
    FragColor = vec4(vertexColor, 1.0);
}
)glsl";
