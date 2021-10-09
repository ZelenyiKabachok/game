#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "loads/stb_image.h"

class Texture2D {
public:

	GLuint texID;
	unsigned int Width, Height;
	unsigned int InternalFormat;
	unsigned int ImageFormat;
	
	unsigned int Wrap_S;
	unsigned int Wrap_T;
	unsigned int FilterMin;
	unsigned int FilterMax;

	Texture2D();
	
	void Generate(unsigned int width, unsigned int height, const unsigned char *data);

	void Bind() const;
};

#endif
