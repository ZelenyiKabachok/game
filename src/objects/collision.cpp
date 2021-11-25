#include "collision.h"

Collision::Collision(const Shape* const arrayOfShapes, const unsigned int num) : numOfShapes(num)
{
	//Создание массива указателей на Shape.
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppShapes[i] = new Shape(arrayOfShapes[i]);
	}
	find_AABB_points();
	ShRender.Init(ppShapes, numOfShapes, pAABB);
}

Collision::Collision(Shape** arrayOfShapes, const unsigned int num) : numOfShapes(num)
{
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {	
		ppShapes[i] = new Shape(*(arrayOfShapes[i]));
	}
	find_AABB_points();
	ShRender.Init(ppShapes, numOfShapes, pAABB);
}

Collision::Collision(const Collision& obj) : numOfShapes(obj.numOfShapes)
{
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {	
		ppShapes[i] = new Shape(*(obj.ppShapes[i]));
	}
	find_AABB_points();
	ShRender.Init(ppShapes, numOfShapes, pAABB);
}

void Collision::find_AABB_points()
{
	enum Faces { left, down, right, up };
	float faces[4] = { 
			ppShapes[0]->pPoints[0].x, ppShapes[0]->pPoints[0].y, 
			ppShapes[0]->pPoints[0].x, ppShapes[0]->pPoints[0].y
	};

	for(unsigned int n = 0; n < numOfShapes; n++) {
		const Shape& cur_shape = *(ppShapes[n]);	
	
		for(unsigned int i = 0; i < cur_shape.num_points; i++) {
			const glm::vec2& cur_point = glm::vec2(
				  glm::vec4(cur_shape.pPoints[i], 0.0f, 1.0f));

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

	pAABB[0].x = faces[left];
	pAABB[0].y = faces[down];
	pAABB[1].x = faces[right];
	pAABB[1].y = faces[up];

	//ppGraphic[numOfShapes]->GetShader().SetVector3("First", vec3(pAABB[0], 0.0f));
	//ppGraphic[numOfShapes]->GetShader().SetVector3("Second", vec3(pAABB[1], 0.0f));

}

Collision::~Collision()
{
	for(unsigned int i = 0; i < numOfShapes; i++) {
		delete ppShapes[i];
	}
	delete[] ppShapes;
}

void Collision::PrintState()
{
	glm::mat4 matPos = translate(glm::mat4(1.0f), Position);
	glm::vec2 AABB[2] = {
		glm::vec2(matPos * glm::vec4(pAABB[0], 0.0f, 1.0f)),
		glm::vec2(matPos * glm::vec4(pAABB[1], 0.0f, 1.0f)),
	};
	printf("AABB First Point = { %f, %f }\n", AABB[0].x, AABB[0].y);
	printf("AABB Second Point = { %f, %f }\n\n", AABB[1].x, AABB[1].y);
/*
	for(unsigned int i = 0; i < numOfShapes; i++) {
		printf("(%d) Shape:\n", i+1);
		printf("Center = { %f; %f }\n", matPos*ppShapes[i]->center.x,
										matPos*ppShapes[i]->center.y);
		for(unsigned int j = 0; j < ppShapes[i]->num_points; j++) {
			printf("\t(%d) { %f; %f }\n", j+1, matPos*ppShapes[i]->pPoints[j].x,
											   matPos*ppShapes[i]->pPoints[j].y);
		}
		printf("\n");
	}
*/
}

void Collision::Draw(const Camera& camera)
{ ShRender.Draw(camera, Position, angle); }

void Collision::Movement(glm::vec3 new_pos)
{
	//glm::vec3 delta_pos = new_pos - Position;
	Position = new_pos;
/*
	glm::mat4 matPosition = glm::translate(glm::mat4(1.0f), delta_pos);

	for(unsigned int i = 0; i < numOfShapes; i++) {
		Shape& cur_shape = *(ppShapes[i]);
		cur_shape.center = glm::vec2(matPosition * glm::vec4(cur_shape.center, 0.0f, 1.0f));

		for(unsigned int j = 0; j < cur_shape.num_points; j++) {
				glm::vec2& cur_point = cur_shape.pPoints[j];

				cur_point = glm::vec2(matPosition * glm::vec4(cur_point, 0.0f, 1.0f));
		}
	}

	pAABB[0] = glm::vec2(matPosition * glm::vec4(pAABB[0], 0.0f, 1.0f));
	pAABB[1] = glm::vec2(matPosition * glm::vec4(pAABB[1], 0.0f, 1.0f));
*/
	PrintState();
}

void Collision::Rotation(float new_angle)
{
	float delta_angle = new_angle-angle;
	angle = new_angle;
	
	glm::mat4 matRotation = glm::rotate(glm::mat4(1.0f), delta_angle,
										glm::vec3(0.0f, 0.0f, 1.0f));

	for(unsigned int i = 0; i < numOfShapes; i++) {
		Shape& cur_shape = *(ppShapes[i]);

		for(unsigned int j = 0; j < cur_shape.num_points; j++) {
			glm::vec2& cur_point = cur_shape.pPoints[j];
			cur_point = glm::vec2(matRotation * glm::vec4(cur_point, 0.0f, 1.0f));
		}
	}

	find_AABB_points();
}
