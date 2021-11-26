#ifndef SHAPE_DRAW_H
#define SHAPE_DRAW_H

#include "shape.h"
#include "graphic_object.h"
#include "../camera.h"
#include "../utility/shader.h"
#include "../utility/texture.h"
#include "../utility/resources.h"

extern Camera camera;

class ShapeDraw : public GraphObject {

    friend class CollDraw;
	
public:

	ShapeDraw(const Shader& sh, const Texture2D& tex, const vec3& pos = vec3(0), 
				const vec3& size = vec3(1), const vec3& speed = vec3(0),
				const vec3& slVec = { 0.0, 0.0, 1.0 }, const float slAng = 0.0);


	virtual void initShaderData(const float *Data, const glm::vec3& Color,
						unsigned int vertexes, GLenum DrawType = GL_LINE_LOOP);
	virtual void initShaderData(const glm::vec2 *Data, const glm::vec3& Color,
						unsigned int vertexes, GLenum DrawType = GL_LINE_LOOP);

	virtual void Move(const char *uniPos, const vec3& pos);
	
	virtual void Draw(const Camera& camera, float width) const;

	virtual ~ShapeDraw() {};

};

#endif
