#ifndef SHAPE_DRAW_H
#define SHAPE_DRAW_H

#include "shape.h"
#include "graphic_object.h"

extern Camera camera;

namespace Graphic {

//Отрисовка контура фигуры класса Shape.
class ShapeDraw : public GraphObject {

    friend class CollDraw;
	
public:

	ShapeDraw(Shader& sh, Texture2D& tex
                , const glm::vec3& v3Pos = glm::vec3(0) 
				, const glm::vec3& v3Size = glm::vec3(1)
                , const glm::vec3& v3Speed = glm::vec3(0)
				, const glm::vec3& v3Slant = { 0.0, 0.0, 1.0 }
                , const float slAng = 0.0);


	virtual void initShaderData(const float *pData
                                , const glm::vec3& v3Color
				                , unsigned int vertexes
                                , GLenum DrawType = GL_LINE_LOOP);
	virtual void initShaderData(const glm::vec2 *pData
                                , const glm::vec3& v3Color
						        , unsigned int vertexes
                                , GLenum DrawType = GL_LINE_LOOP);

	virtual void Move(const char *sUniPos, const glm::vec3& v3Pos);
	
	virtual void Draw(const Camera& camera, float width) const;

	virtual ~ShapeDraw() {};

};
}

#endif
