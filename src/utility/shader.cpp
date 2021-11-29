#include <cstdio>
#include "shader.h"

void Graphic::Shader::Generate(const char *sVertCode
                                , const char *sFragCode
                                , const char *sGeomCode)
{
	GLint vertShader;
	GLint fragShader;
	GLint geomShader = 0;
	CompileShader(sVertCode, vertShader, GL_VERTEX_SHADER);
	CompileShader(sFragCode, fragShader, GL_FRAGMENT_SHADER);
	if(sGeomCode) {
		CompileShader(sGeomCode, geomShader, GL_GEOMETRY_SHADER);
	}
	CompoundShader(vertShader, fragShader, geomShader);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
	glDeleteShader(geomShader);
}

void Graphic::Shader::SetMatrix4(const char *sVarName
                                , const glm::mat4 &matVar) const
{
	GLuint location = glGetUniformLocation(programHandle, sVarName);
	if(location >= 0)
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matVar));
}

void Graphic::Shader::SetVector3(const char *sVarName
                                , const glm::vec3& v3Var) const
{
	GLuint location = glGetUniformLocation(programHandle, sVarName);
	float pArr[3] = { v3Var.x, v3Var.y, v3Var.z };
	if(location >= 0)
		glUniform3fv(location, 1, pArr);
}

void Graphic::Shader::SetInt(const char *sVarName, const int var) const
{
	GLuint location = glGetUniformLocation(programHandle, sVarName);
	if(location >= 0)
		glUniform1i(location, var);
}

void Graphic::Shader::CompoundShader(GLint& vertShader
                                , GLint& fragShader
                                , GLint& geomShader)
{
	programHandle = glCreateProgram();
	if(!programHandle) {
		printf("Error creating program object\n");
	}
	
	glAttachShader(programHandle, vertShader);
	glAttachShader(programHandle, fragShader);
	if(geomShader) {
		glAttachShader(programHandle, geomShader);
	}
	
	glLinkProgram(programHandle);

	GLint status;
	glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
	if(status == GL_FALSE) {
		printf("\nError to link shader program!\n");
	
		GLint logLen;
		glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &logLen);
		if(logLen > 0) {
			char *sLog = new char[logLen];
			glGetProgramInfoLog(programHandle, logLen, NULL, sLog);
			printf("Program log:\n%s\n", sLog);
			delete[] sLog;
		}
	}
}

void Graphic::Shader::CompileShader(const char *sShaderCode
                                    , GLint& shader
                                    , GLenum shaderType)
{
	shader = glCreateShader(shaderType);

	if(!shader) {
		printf("Error creating shader!\n");
		return;
	}
	
	const GLchar *sCodeArray[] = {sShaderCode};

	glShaderSource(shader, 1, sCodeArray, NULL);
	glCompileShader(shader);

	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE) {
		printf("Error, shader compilation faild\n");
		printf("Shader Code:\n%s", sShaderCode);
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		
		if(logLen > 0) {
			char *sLog = new char[logLen];

			glGetShaderInfoLog(shader, logLen, NULL, sLog);
			printf("Shader log:\n%s\n", sLog);
			delete[] sLog;
		}
	}
}

void Graphic::Shader::Use() const { glUseProgram(programHandle); }
