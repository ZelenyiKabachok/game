#include "collision.h"

Collision::Collision(Shape *arrayOfShapes, const unsigned int num) : numOfShapes(num)
{
	//Создание массива указателей на Shape.
	shapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {
		shapes[i] = new Shape(arrayOfShapes[i]);
	}
	find_AABB_points();
}

void Collision::find_AABB_points()
{
	enum Faces { left, down, right, up };
	float faces[4] = { 
			shapes[0]->points[0].x, shapes[0]->points[0].y, 
			shapes[0]->points[0].x, shapes[0]->points[0].y
	};

	for(unsigned int n = 0; n < numOfShapes; n++) {
		const Shape& cur_shape = *(shapes[n]);	
	
		for(unsigned int i = 0; i < cur_shape.num_points; i++) {
			const glm::vec2& cur_point = cur_shape.points[i];

			if(cur_point.x < faces[left])
			{ faces[left] = cur_point.x; }

			if(cur_point.y < faces[down])
			{ faces[down] = cur_point.y; }

			if(cur_point.x > faces[right])
			{ faces[right] = cur_point.x; }

			if(cur_point.y > faces[up])
			{ faces[up] = cur_point.y; }
		}
	}

	AABB[0].x = faces[left];
	AABB[0].y = faces[down];

	AABB[1].x = faces[right];
	AABB[1].y = faces[up];
}

Collision::~Collision()
{
	delete[] shapes;
}

void Collision::Movement(glm::mat4 matrix)
{
	for(unsigned int i = 0; i < numOfShapes; i++) {
		Shape& cur_shape = *(shapes[i]);
		cur_shape.center = glm::vec2(glm::vec4(cur_shape.center, 0.0f, 0.0f) * matrix);

		for(unsigned int j = 0; j < cur_shape.num_points; j++) {
				glm::vec2& cur_vec = cur_shape.points[j];

				cur_vec = glm::vec2(glm::vec4(cur_vec, 0.0f, 0.0f) * matrix);
		}
	}
	AABB[0] = glm::vec2(glm::vec4(AABB[0], 0.0f, 0.0f) * matrix);
	AABB[1] = glm::vec2(glm::vec4(AABB[1], 0.0f, 0.0f) * matrix);
}

void Collision::Rotation(glm::mat4 matrix)
{
	for(unsigned int i = 0; i < numOfShapes; i++) {
		Shape& cur_shape = *(shapes[i]);

		for(unsigned int j = 0; j < cur_shape.num_points; j++) {
			glm::vec2& cur_vec = cur_shape.points[j];
			cur_vec = glm::vec2(glm::vec4(cur_vec, 0.0f, 0.0f) * matrix);
		}
	}
	find_AABB_points();
}
