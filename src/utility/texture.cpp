#include "texture.h"


Texture2D::Texture2D() : Width(0), Height(0), InternalFormat(GL_RGB), ImageFormat(GL_RGB),
		Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), FilterMin(GL_LINEAR), FilterMax(GL_LINEAR)
{
	glGenTextures(1, &texID);
}

void Texture2D::Generate(unsigned int width, unsigned int height, 
									const unsigned char *data)
{	
	Width = width;
	Height = height;

	glBindTexture(GL_TEXTURE_2D, texID);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, width, height, 0, 
								ImageFormat, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FilterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FilterMax);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}
		
void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, texID);
}
