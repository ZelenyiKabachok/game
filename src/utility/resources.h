#ifndef RESOURSES_H
#define RESOURSES_H

#include <map>
#include "shader.h"
#include "texture.h"

class ResourceManager {
	
	std::map <const char*, Graphic::Shader> Shaders;
	std::map <const char*, Graphic::Texture2D> Textures;
	
public:

	const Graphic::Shader& LoadShader(const char *sName
                            , const char *fVertShader
							, const char *fFragShader
                            , const char *fGeomShader = NULL);

	const Graphic::Texture2D& LoadTexture(const char *name
                                        , const char *fImageFile);

	void DeleteShader(const char *sName);
	
	void DeleteTexture(const char *sName);

	const Graphic::Shader& GetShader(const char *sName);
	const Graphic::Texture2D& GetTexture(const char *sName);

	ResourceManager() {}
	
	~ResourceManager();

private:

	Graphic::Shader LoadShaderFromFile(const char *fVertShader
							           , const char *fFragShader
                                       , const char *fGeomShader);

	Graphic::Texture2D LoadTextureFromFile(const char *fImageFile);

	const char* loadShaderAsString(const char *sFileName);
};

#endif
