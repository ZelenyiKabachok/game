#ifndef SHADER_H
#define SHADER_H

class Shader {

	GLuint vaoHandle;
	GLuint programHandle;	

public:

	Shader(const char *VertFile, const char *FragFile);

	void Params(const float *positionData, const float *colorData, int vertics);

	void Render();	

private:	

	void CompileShader(GLint& shader, GLenum shaderType, const char *file);
	
	const char* loadShaderAsString(const char *file);
	
	void CompoundShader(GLint& vertShader, GLint& fragShader);
};

#endif
