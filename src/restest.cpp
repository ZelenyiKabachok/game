#include <cstdio>
#include "restest.h"

std::map <const char *, Shader> ResourceManager::Shaders;
std::map <const char *, Texture2D> ResourceManager::Textures;

Shader ResourceManager::LoadShader(const char *VertShader,
														const char *FragShader)
{
	return LoadShaderFromFile(VertShader, FragShader);
}

Texture2D ResourceManager::LoadTexture(const char *name, const char *ImageFile,
																	bool alpha)
{
	Textures[name] = LoadTextureFromFile(ImageFile, alpha);
	return Textures[name];
}	

Texture2D ResourceManager::LoadTextureFromFile(const char *ImageFile, bool alpha)
{
	Texture2D texture;
	int width, height, nrChannels;
	unsigned char *data = stbi_load(ImageFile, &width, &height, &nrChannels, 0);

	if(alpha) {
		texture.InternalFormat = GL_RGBA;
		texture.ImageFormat = GL_RGBA;
	}

	if(data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, 
			GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		printf("Error load texture!\n");
	}

	texture.Generate(width, height, data);

	stbi_image_free(data);
	return texture;
}

Shader ResourceManager::LoadShaderFromFile(const char *VertexShader,
												const char *FragShader)
{
	const char *VertCode = loadShaderAsString(VertexShader);
	const char *FragCode = loadShaderAsString(FragShader);

	Shader shader;
	shader.Generate(VertCode, FragCode);

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
