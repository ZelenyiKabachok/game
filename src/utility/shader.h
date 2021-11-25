#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:

	GLuint programHandle = 0;	

	Shader() {}

	//~Shader() { glDeleteProgram(programHandle); }

	void Generate(const char *VertCode, const char *FragCode, const char *GeomCode);

	void Use() const;

	void SetMatrix4(const char *varName, const glm::mat4 &matrix) const;

	void SetVector3(const char *varName, const glm::vec3 &vector) const;

	void SetInt(const char *varName, const int var) const;

private:	

	void CompileShader(const char *ShaderCode, GLint& shader, GLenum shaderType);
	
	void CompoundShader(GLint& vertShader, GLint& fragShader, GLint& geomShader);
};

#endif
