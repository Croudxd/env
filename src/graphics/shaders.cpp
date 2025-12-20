#include "shaders.h"
#include <cstddef>
#include <cstdio>
#include <glad/glad.h>

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

const char *fragmentShaderSource = R"glsl(
#version 330 core
in vec3 vertexColor;
out vec4 FragColor;

void main() {
    FragColor = vec4(vertexColor, 1.0);
}
)glsl";

unsigned int initalize_shaders () 
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("Vertex Shader Compilation Error:\n%s\n", infoLog);
    }
    
    //fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) 
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("Fragment Shader Compilation Error:\n%s\n", infoLog);
    }

    //shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("Shader Program Linking Error:\n%s\n", infoLog);
    }

    //delete shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
