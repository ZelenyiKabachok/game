#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Graphic {

class Shader {
public:

	GLuint programHandle = 0;	

	Shader() {}

	void Generate(const char *sVertCode, const char *sFragCode
                                       , const char *sGeomCode);

	void Use() const;

	void SetMatrix4(const char *sVarName, const glm::mat4& matVar) const;

	void SetVector3(const char *sVarName, const glm::vec3& v3Var) const;

	void SetInt(const char *sVarName, const int var) const;

private:	

	void CompileShader(const char *sShaderCode, GLint& shader, GLenum shaderType);
	
	void CompoundShader(GLint& vertShader, GLint& fragShader, GLint& geomShader);
};
}

#endif
