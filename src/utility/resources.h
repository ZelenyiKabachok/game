#ifndef RESOURSES_H
#define RESOURSES_H

#include <map>
#include "collision_in_files.h"

class ResourceManager {
	
    std::map <const char*, Graphic::Shader> Shaders;
	std::map <const char*, Graphic::Texture2D> Textures;

public:

    static ResourceManager& Instance();

	Graphic::Shader& LoadShader(const char *sName
                            , const char *fVertShader
							, const char *fFragShader
                            , const char *fGeomShader = NULL);

	Graphic::Texture2D& LoadTexture(const char *name
                                        , const char *fImageFile);

    Physic::Collision LoadCollision(const char* fFile);

	const char* loadFileAsString(const char *sFileName);

	void DeleteShader(const char *sName);
	
	void DeleteTexture(const char *sName);

	Graphic::Shader& GetShader(const char *sName);
	Graphic::Texture2D& GetTexture(const char *sName);

	~ResourceManager();

private:

	ResourceManager() {}
    ResourceManager(const ResourceManager& res) = delete;
    ResourceManager& operator=(const ResourceManager& res) = delete;
    

	Graphic::Shader LoadShaderFromFile(const char *fVertShader
							           , const char *fFragShader
                                       , const char *fGeomShader);

	Graphic::Texture2D LoadTextureFromFile(const char *fImageFile);

};

#endif
