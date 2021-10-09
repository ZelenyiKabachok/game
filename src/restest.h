#ifndef RESOURSES_H
#define RESOURSES_H

#include <map>
#include "shader.h"
#include "texture.h"

class ResourceManager {
public:
	
	static std::map <const char*, Shader> Shaders;
	static std::map <const char*, Texture2D> Textures;

	static Shader LoadShader(const char *VertShader, 
														const char *FragShader);

	static Shader ReturnShader(const char *name)
	{ return Shaders[name]; }

	static Texture2D LoadTexture(const char *name, const char *ImageFile, bool alpha);

	static Texture2D ReturnTexture(const char *name)
	{ return Textures[name]; }


private:
	
	ResourceManager() {}

	static Shader LoadShaderFromFile(const char *VertShader, const char *FragShader);

	static Texture2D LoadTextureFromFile(const char *ImageFile, bool alpha);

	static const char* loadShaderAsString(const char *fileName);
};

#endif
