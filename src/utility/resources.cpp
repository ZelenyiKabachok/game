#include <cstdio>
#include "resources.h"

const Shader& ResourceManager::LoadShader(const char *name, const char *VertShader,
														const char *FragShader)
{
	Shaders[name] = LoadShaderFromFile(VertShader, FragShader);
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
												const char *FragShader)
{
	const char *VertCode = loadShaderAsString(VertexShader);
	const char *FragCode = loadShaderAsString(FragShader);

	Shader shader;
	shader.Generate(VertCode, FragCode);

	delete[] VertCode;
	delete[] FragCode;

	return shader;
}	

const char* ResourceManager::loadShaderAsString(const char *file)
{
	FILE *fd;
	fd = fopen(file, "r");
	if(!fd) {
		printf("Can't open file: %s\n", file);
		exit(0);
	}
	char *code = new char[1024];
	fread(code, 1, 1024, fd);
	fclose(fd);
	return code;
}

const Texture2D& ResourceManager::GetTexture(const char *name)
{ return Textures[name]; }

const Shader& ResourceManager::GetShader(const char *name)
{ return Shaders[name]; }



