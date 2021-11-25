#ifndef SPRITE_H
#define SPRITE_H

#include <glad/glad.h>
#include "../utility/resources.h"
#include "../camera.h"

class Camera;

using glm::vec3;
using glm::mat4;

// Класс GraphObject отображает спрайт на экране
class GraphObject {

protected:
	Shader shader;
	Texture2D texture;
	vec3 color = vec3(1.0, 1.0, 1.0);
	GLuint VAO;
	GLenum type;
	unsigned int points;

	mat4 PositionMatrix;
	mat4 RotateMatrix;
	mat4 SizeMatrix;
	vec3 ObPosition; //Позиция объекта в мировых координатах
	vec3 ObSize;	 //Размер обекта
	vec3 ObSpeed;	 //Скорость объекта

	vec3 SlantVector; 	//Вектор, относительно которого наклонён объект.
	float SlantAngle;	//Угол наклона.

public:

//Инициализация шейдера
//инициализация без текстуры
	virtual void initShaderData(const float *Data, const unsigned int *indices,
						int DataVert, unsigned int IndicesQuantity,
						GLenum DrawType = GL_TRIANGLES);	
//Отрисовывает объект
	virtual void Draw(const Camera& camera) const;  
//Обновляет позицию объектa.
	virtual void Move(const float delta_time);
//Поворачивает объект.
	void Rotate(const vec3& rotateVec = vec3(1), const float angle = 0);
//Масштабирует объект.
	void Scale();

	void ChangeTexture(const Texture2D& tex);

	void ChangeColor(const vec3& newColor);
	
	void ChangeSlantVector(const vec3& newSlVec);

	void ChangeSlantAngle(float angle);

	void ChangeSize(const vec3& newSize); 

	void ChangeSpeed(const vec3& newSpeed);
	
	void ChangePosition(const vec3& newPos);

//Передаётся шейдерный объект, текстура, позиция, размер объекта и его скорость.
	GraphObject(const Shader& sh, const Texture2D& tex, const vec3& pos = vec3(0), 
				const vec3& size = vec3(1), const vec3& speed = vec3(0),
				const vec3& slVec = { 0.0, 0.0, 1.0 }, const float slAng = 0.0);

	virtual ~GraphObject() {}

	vec3 GetSpeed() const;
	
	vec3 GetPosition() const;

	const Shader& GetShader() const;
	const Texture2D& GetTexture() const;
};

#endif
