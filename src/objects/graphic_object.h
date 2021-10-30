#ifndef SPRITE_H
#define SPRITE_H

#include <glad/glad.h>
#include "../loads.h"
#include "../camera.h"

// Класс GraphObject отображает спрайт на экране
class GraphObject {

	Shader shader;
	Texture2D texture;
	GLuint VAO;

	mat4 Model;

protected:
	
	vec3 ObPosition; //Позиция объекта в мировых координатах
	vec3 ObSize;	 //Размер обекта
	vec3 ObSpeed;	 //Скорость объекта

public:

//Инициализация шейдера
	void initShaderData(float *Data, unsigned int *indices,
						int DataVert, int IndicesQuantity);	

//Обновляет объект (его позицию с учётом камеры)
	void Move(const float delta_time, const vec3& rotateVec = vec3(1),
												const float angle = 0);

//Отрисовывает объект
	void Draw() const;

public:

	void ChangeTexture(const Texture2D& tex);

	void ChangeSize(const vec3& newSize); 

	void ChangeSpeed(const vec3& newSpeed);
	
	void ChangePosition(const vec3& newPos);

//Передаётся шейдерный объект, текстура, позиция, размер объекта и его скорость.
	GraphObject(const Shader& sh, const Texture2D& tex, const vec3& pos = vec3(0), 
							const vec3& size = vec3(1), const vec3& speed = vec3(0));

	vec3 GetSpeed() const;
	
	vec3 GetPosition() const;
};

#endif
