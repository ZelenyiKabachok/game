#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <stdlib.h>
#include "shader.h"

Shader::Shader(const char *VertFile, const char *FragFile)
{
	GLint vertShader;
	GLint fragShader;
	CompileShader(vertShader, GL_VERTEX_SHADER, VertFile);
	CompileShader(fragShader, GL_FRAGMENT_SHADER, FragFile);
	CompoundShader(vertShader, fragShader);
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::Params(const float *positionData, const float *colorData, int vertics)
{
	GLuint vboHandle[2];	
	glGenBuffers(2, vboHandle);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);
	glBufferData(GL_ARRAY_BUFFER, vertics * sizeof(float), positionData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);
	glBufferData(GL_ARRAY_BUFFER, vertics * sizeof(float), colorData, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vaoHandle);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, vboHandle[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Shader::Render()
{
	glBindVertexArray(vaoHandle);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

const char*  Shader::loadShaderAsString(const char *file)
{
	FILE *fd;
	fd = fopen(file, "r");
	if(!fd) {
		printf("Can't open file: %s\n", file);
		exit(0);
	}
	char *code = new char[512];
	fread(code, 1, 512, fd);
	fclose(fd);
	return code;
}

void Shader::CompoundShader(GLint& vertShader, GLint& fragShader)
{
	programHandle = glCreateProgram();
	if(!programHandle) {
		printf("Error creating program object\n");
		exit(0);
	}
	
	glAttachShader(programHandle, vertShader);
	glAttachShader(programHandle, fragShader);
	
	glLinkProgram(programHandle);

	GLint status;
	glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
	if(status == GL_FALSE) {
		printf("\nError to link shader program!\n");
	
		GLint logLen;
		glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &logLen);
		if(logLen > 0) {
			char *log = new char[logLen];
			glGetProgramInfoLog(programHandle, logLen, NULL, log);
			printf("Program log:\n%s\n", log);
			delete[] log;
		}
	} else {
		glUseProgram(programHandle);
	}
}

void Shader::CompileShader(GLint& shader, GLenum shaderType, const char *file)
{
	shader = glCreateShader(shaderType);

	if(!shader) {
		printf("Error creating shader!\n");
		exit(0);
	}

	const GLchar *shaderCode = loadShaderAsString(file);
	const GLchar *codeArray[] = {shaderCode};

	glShaderSource(shader, 1, codeArray, NULL);
	glCompileShader(shader);

	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE) {
		printf("Error, shader compilation faild\n");
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		
		if(logLen > 0) {
			char *log = new char[logLen];

			glGetShaderInfoLog(shader, logLen, NULL, log);
			printf("\nFile name %s\n", file);
			printf("Shader log:\n%s\n", log);
			delete[] log;
		}
	}
}
