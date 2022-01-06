#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "../../external/stb_image/stb_image.h"

namespace Graphic {

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

public:

	Texture2D(unsigned int wrap_s = GL_REPEAT, unsigned int wrap_t = GL_REPEAT
            , unsigned int internal = GL_RGB, unsigned int image = GL_RGB);
	
	void Generate(unsigned int width, unsigned int height
                    , const unsigned char *pData);

	void Bind() const;
};
}

#endif
