#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {

	bool compileStatus = false;

public:

	GLuint programHandle = 0;	

	Shader() {}

	//~Shader() { glDeleteProgram(programHandle); }

	void Generate(const char *VertCode, const char *FragCode);

	bool IsCompiled() { return compileStatus; }

	void Use() { glUseProgram(programHandle); }

	void SetMatrix4(const char *varName, const glm::mat4 &matrix);

	void SetInt(const char *varName, const int var);

private:	

	void CompileShader(const char *ShaderCode, GLint& shader, GLenum shaderType);
	
	bool CompoundShader(GLint& vertShader, GLint& fragShader);
};

#endif
