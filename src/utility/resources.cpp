#include <cstdio>
#include "resources.h"

const Shader& ResourceManager::LoadShader(const char *name, const char *VertShader,
										  const char *FragShader, const char *GeomShader)
{
	Shaders[name] = LoadShaderFromFile(VertShader, FragShader, GeomShader);
	return Shaders[name];
}

const Texture2D& ResourceManager::LoadTexture(const char *name, const char *ImageFile)
{
	Textures[name] = LoadTextureFromFile(ImageFile);
	return Textures[name];
}	

Texture2D ResourceManager::LoadTextureFromFile(const char *ImageFile)
{
	Texture2D texture;
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *pixels = stbi_load(ImageFile, &width, &height, &nrChannels, 0);

	if(nrChannels == 4) {
		texture.InternalFormat = GL_RGBA;
		texture.ImageFormat = GL_RGBA;
	}

	if(!pixels) {
		printf("Error load texture %s\n", ImageFile);
	}
	texture.Generate(width, height, pixels);

	stbi_image_free(pixels);
	return texture;
}

ResourceManager::~ResourceManager()
{
	for(auto item : Shaders) {
		glDeleteProgram(item.second.programHandle);
	}
	for(auto item : Textures) {
		glDeleteTextures(1, &(item.second.texID));
	}
}

Shader ResourceManager::LoadShaderFromFile(const char *VertexShader,
										   const char *FragShader,
										   const char *GeomShader)
{
	const char *VertCode = loadShaderAsString(VertexShader);
	const char *FragCode = loadShaderAsString(FragShader);
	const char *GeomCode = NULL;
	if(GeomShader)
	{ GeomCode = loadShaderAsString(GeomShader); }

	Shader shader;
	shader.Generate(VertCode, FragCode, GeomCode);

	delete[] VertCode;
	delete[] FragCode;
	if(GeomShader)
    { delete[] GeomCode; }

	return shader;
}	

const char* ResourceManager::loadShaderAsString(const char *file)
{
	unsigned int file_size;
	FILE *fd = fopen(file, "r");
	if(!fd) {
		fprintf(stderr, "Can't open file: %s\n", file);
		exit(0);
	}
	
	fseek(fd, 0, SEEK_END);
	file_size = ftello(fd);
	fseek(fd, 0, SEEK_SET);

	char *code = new char[file_size+1];
	fread(code, 1, file_size, fd);
//	code[file_size] = EOF; //Без ручного указания конца файла шейдеры не компилируются.
	fclose(fd);
	return code;
}

const Texture2D& ResourceManager::GetTexture(const char *name)
{ return Textures[name]; }

const Shader& ResourceManager::GetShader(const char *name)
{ return Shaders[name]; }
