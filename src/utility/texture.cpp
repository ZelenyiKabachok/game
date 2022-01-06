#include "texture.h"


Graphic::Texture2D::Texture2D(unsigned int wrap_s, unsigned int wrap_t
                            , unsigned int internal, unsigned int image)
                                : Width(0), Height(0)
                                , InternalFormat(internal), ImageFormat(image)
		                        , Wrap_S(wrap_s), Wrap_T(wrap_t)
                                , FilterMin(GL_LINEAR), FilterMax(GL_LINEAR)
{
	glGenTextures(1, &texID);
}

void Graphic::Texture2D::Generate(unsigned int width, unsigned int height 
								    , const unsigned char *pData)
{	
	Width = width;
	Height = height;

	glBindTexture(GL_TEXTURE_2D, texID);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, width, height, 0, 
								ImageFormat, GL_UNSIGNED_BYTE, pData);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, FilterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, FilterMax);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}
		
void Graphic::Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, texID);
}
