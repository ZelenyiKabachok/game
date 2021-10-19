#ifndef SPRITE_H
#define SPRITE_H

#include "glad/glad.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"

class GraphObject {

	Shader shader;
	Texture2D texture;
	GLuint VAO;
	
	vec3 ObPosition;
	vec3 ObSize;
	vec3 ObSpeed;

public:

	void initShaderData(const float *Data, const unsigned int *indices);	

	void Move(const float delta_time, const vec3& rotateVec, const float angle);

	void Draw(const mat4& Model);

	void ChangeTexture(const Texture2D& tex);

	void ChangeSize(const vec3& newSize); 

	void ChangeSpeed(const vec3& newSpeed);

	GraphObject(const Shader& sh, const Texture2D& tex, const vec3& pos, 
									const vec3& size, const vec3& speed);
};

#endif
