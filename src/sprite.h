#ifndef SPRITE_H
#define SPRITE_H

#include "glad/glad.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"

class Sprite {

	Shader shader;
	GLuint VAO;

public:
	
	Sprite(const Shader& sh);

	void Draw(const Texture2D& texture, const float delta_time, 
		const vec3& position, const vec3& size, const vec3& rotateVector,
 											const float angle);

private:

	void initShaderData();	

};

#endif
