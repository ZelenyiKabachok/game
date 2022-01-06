#include <cstdio>
#include "resources.h"

Graphic::Shader& ResourceManager::LoadShader(
                      const char *sName, const char *fVertShader
				    , const char *fFragShader, const char *fGeomShader)
{
	Shaders[sName] = LoadShaderFromFile(fVertShader, fFragShader, fGeomShader);
	return Shaders[sName];
}

Graphic::Texture2D& ResourceManager::LoadTexture(const char *sName
                                                , const char *fImageFile)
{
	Textures[sName] = LoadTextureFromFile(fImageFile);
	return Textures[sName];
}	

Physic::Collision ResourceManager::LoadCollision(const char *fName)
{
    String sCollis = loadFileAsString(fName);
    Physic::Collision collision = readCollision(sCollis.GetPointer());
    return collision;
}

Graphic::Texture2D ResourceManager::LoadTextureFromFile(const char *fImageFile)
{
	Graphic::Texture2D texture;
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *pixels = stbi_load(fImageFile, &width, &height, &nrChannels, 0);

	if(nrChannels == 4) {
		texture.InternalFormat = GL_RGBA;
		texture.ImageFormat = GL_RGBA;
	}

	if(!pixels) {
		printf("Error load texture %s\n", fImageFile);
	}
	texture.Generate(width, height, pixels);

	stbi_image_free(pixels);
	return texture;
}

ResourceManager& ResourceManager::Instance()
{
    static ResourceManager res;
    return res;
}

ResourceManager::~ResourceManager()
{
/*
	for(auto item : Shaders) {
		glDeleteProgram(item.second.programHandle);
	}
	for(auto item : Textures) {
		glDeleteTextures(1, &(item.second.texID));
	}
*/
}

Graphic::Shader ResourceManager::LoadShaderFromFile(const char *fVertexShader
										          , const char *fFragShader
										          , const char *fGeomShader)
{

	String sVertCode = loadFileAsString(fVertexShader);
	String sFragCode = loadFileAsString(fFragShader);
	String sGeomCode;// = '\0';//NULL;
	if(fGeomShader)
	{ sGeomCode = loadFileAsString(fGeomShader); }

    //printf("\nVertex:\n%s\nFrag:\n%s\nGeom:\n%s\n", sVertCode.GetPointer()
     //       , sFragCode.GetPointer(), sGeomCode.GetPointer());

	Graphic::Shader shader;
	shader.Generate(sVertCode.GetPointer(), sFragCode.GetPointer()
                  , sGeomCode.GetPointer());

	return shader;
}	


String ResourceManager::loadFileAsString(const char *fFile)
{
    std::string string;
    std::ifstream file(fFile);
    std::stringstream vShaderStream;
 
    vShaderStream << file.rdbuf();

    file.close();

    string = vShaderStream.str();
    
    return String(string.c_str());
} 

/*
//Я не понимаю откуда берутся лишние символы в конце строки!
String ResourceManager::loadFileAsString(const char *fFile)
{
	unsigned int file_size;
	FILE *fd = fopen(fFile, "rw");
	if(!fd) {
		fprintf(stderr, "Can't open file: %s\n", fFile);
		exit(0);
	}

	fseek(fd, 0, SEEK_END);
	file_size = ftello(fd);
	fseek(fd, 0, SEEK_SET);

    char sStr[file_size+1];
	fread(sStr, 1, file_size, fd);
    sStr[file_size] = '\0';
    printf("String: %s\n", sStr);
    String string(sStr);
	fclose(fd);
	return string;
}
*/

Graphic::Texture2D& ResourceManager::GetTexture(const char *sName)
{ return Textures[sName]; }

Graphic::Shader& ResourceManager::GetShader(const char *sName)
{ return Shaders[sName]; }

void ResourceManager::DeleteShader(const char *sName)
{ glDeleteProgram(Shaders[sName].programHandle); }
	
void ResourceManager::DeleteTexture(const char *sName)
{ glDeleteTextures(1, &(Textures[sName].texID)); }
