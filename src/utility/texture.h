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

	Texture2D();
	
	void Generate(unsigned int width, unsigned int height
                    , const unsigned char *pData);

	void Bind() const;
};
}

#endif
