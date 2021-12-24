#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

#include <glad/glad.h>
#include "../utility/shader.h"
#include "../utility/texture.h"
#include "../camera.h"

class Camera;

namespace Graphic {

// Класс GraphObject отображает спрайт на экране
class GraphObject {

protected:
	Shader& shader;
	Texture2D& texture;
	glm::vec3 v3Color = glm::vec3(1.0f);
	GLuint VAO;
	GLenum type;
	unsigned int points;

	glm::mat4 matPosition;
	glm::mat4 matRotation;
	glm::mat4 matSize;
	glm::vec3 v3Position;   //Позиция объекта в мировых координатах
	glm::vec3 v3Size;	    //Размер обекта
	glm::vec3 v3Speed;	//Скорость объекта

	glm::vec3 v3Slant; 	    //Вектор, относительно которого наклонён объект.
	float SlantAngle;	    //Угол наклона.

public:

//Инициализация шейдера
//инициализация без текстуры
	virtual void initShaderData(const float *pData, const unsigned int *pIndices
                            , int numOfVert, unsigned int numOfInd
						    , GLenum DrawType = GL_TRIANGLES);	
//Отрисовывает объект
	virtual void Draw(const Camera& camera) const;  
//Обновляет позицию объектa.
	virtual void Move(const float delta_time);
//Поворачивает объект.
	void Rotate(const glm::vec3& v3Rotate = glm::vec3(1)
                            , const float angle = 0);
//Масштабирует объект.
	void Scale();

	void ChangeTexture(const Texture2D& tex);

	void ChangeColor(const glm::vec3& v3NewColor);
	
	void ChangeSlantVector(const glm::vec3& v3NewSlVec);

	void ChangeSlantAngle(float angle);

	void ChangeSize(float newSize); 

	void ChangeSpeed(const glm::vec3& v3NewSpeed);
	
	void ChangePosition(const glm::vec3& v3NewPos);

//Передаётся шейдерный объект, текстура, позиция, размер объекта и его скорость.
	GraphObject(Shader& sh, Texture2D& tex
                            , const glm::vec3& v3Pos = glm::vec3(0)
				            , const glm::vec3& v3Ratio = glm::vec3(1)
                            , const glm::vec3& v3Spd = glm::vec3(0)
				            , const glm::vec3& v3sl = { 0.0, 0.0, 1.0 }
                            , const float slAng = 0.0);

	virtual ~GraphObject() {}

	glm::vec3 GetSpeed() const;
	glm::vec3 GetPosition() const;

	const Graphic::Shader& GetShader() const;
	const Graphic::Texture2D& GetTexture() const;
};
}

#endif
