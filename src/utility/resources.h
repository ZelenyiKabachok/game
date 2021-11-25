#ifndef RESOURSES_H
#define RESOURSES_H

#include <map>
#include "shader.h"
#include "texture.h"

class ResourceManager {
	
	std::map <const char*, Shader> Shaders;
	std::map <const char*, Texture2D> Textures;
	
public:

	const Shader& LoadShader(const char *name, const char *VertShader, 
							 const char *FragShader, const char *GeomShader = NULL);

	const Texture2D& LoadTexture(const char *name, const char *ImageFile);

	void DeleteShader(const char *name)
	{ glDeleteProgram(Shaders[name].programHandle); }
	
	void DeleteTexture(const char *name)
	{ glDeleteTextures(1, &(Textures[name].texID)); }

	const Shader& GetShader(const char *name);
	const Texture2D& GetTexture(const char *name);

	ResourceManager() {}
	
	~ResourceManager();

private:

	Shader LoadShaderFromFile(const char *VertShader, 
							  const char *FragShader, const char *GeomShader);

	Texture2D LoadTextureFromFile(const char *ImageFile);

	const char* loadShaderAsString(const char *fileName);
};

#endif
