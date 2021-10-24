#include <cstdio>
#include "shader.h"

void Shader::Generate(const char *VertCode, const char *FragCode)
{
	GLint vertShader;
	GLint fragShader;
	CompileShader(VertCode, vertShader, GL_VERTEX_SHADER);
	CompileShader(FragCode, fragShader, GL_FRAGMENT_SHADER);
	CompoundShader(vertShader, fragShader);
/*
	printf("VertexShader:\n%s\n\n", VertCode);
	printf("FragShader:\n%s\n\n", FragCode);
*/
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::SetMatrix4(const char *varName, const glm::mat4 &matrix) const
{
	GLuint location = glGetUniformLocation(programHandle, varName);
	if(location >= 0)
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetInt(const char *varName, const int var) const
{
	GLuint location = glGetUniformLocation(programHandle, varName);
	if(location >= 0)
		glUniform1i(location, var);
}

void Shader::CompoundShader(GLint& vertShader, GLint& fragShader)
{
	programHandle = glCreateProgram();
	if(!programHandle) {
		printf("Error creating program object\n");
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
	}
}

void Shader::CompileShader(const char *shaderCode, GLint& shader, GLenum shaderType)
{
	shader = glCreateShader(shaderType);

	if(!shader) {
		printf("Error creating shader!\n");
		return;
	}
	
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
			printf("Shader log:\n%s\n", log);
			delete[] log;
		}
	}
}

void Shader::Use() const { glUseProgram(programHandle); }
