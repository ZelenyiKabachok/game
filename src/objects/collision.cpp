#include "collision.h"

Physic::Collision::Collision(const Shape* pArrayOfShapes
                             , const unsigned int num)
                                : numOfShapes(num)
{
	//Создание массива указателей на Shape.
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {
		ppShapes[i] = new Shape(pArrayOfShapes[i]);
	}
	find_AABB_points();
}

Physic::Collision::Collision(Shape** ppArrayOfShapes
                             , const unsigned int num)
                                : numOfShapes(num)
{
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {	
		ppShapes[i] = new Shape(*(ppArrayOfShapes[i]));
	}
	find_AABB_points();
}

Physic::Collision::Collision(const Collision& obj)
                            : numOfShapes(obj.numOfShapes)
{
	ppShapes = new Shape*[numOfShapes];
	for(unsigned int i = 0; i < numOfShapes; i++) {	
		ppShapes[i] = new Shape(*(obj.ppShapes[i]));
	}
	find_AABB_points();
}

//Physic::Collision::Collision(const char *sCollis)

void Physic::Collision::find_AABB_points()
{
	enum Faces { left, down, right, up };
	float pFaces[4] = { 
			ppShapes[0]->pV2Points[0].x, ppShapes[0]->pV2Points[0].y,
			ppShapes[0]->pV2Points[0].x, ppShapes[0]->pV2Points[0].y
	};

	for(unsigned int n = 0; n < numOfShapes; n++) {
		const Shape& cur_shape = *(ppShapes[n]);	
	
		for(unsigned int i = 0; i < cur_shape.num_points; i++) {
			const glm::vec2& cur_v2Point = glm::vec2(
				  glm::vec4(cur_shape.pV2Points[i], 0.0f, 1.0f));

			if(cur_v2Point.x < pFaces[left])
			{ pFaces[left] = cur_v2Point.x; }

			if(cur_v2Point.y < pFaces[down])
			{ pFaces[down] = cur_v2Point.y; }

			if(cur_v2Point.x > pFaces[right])
			{ pFaces[right] = cur_v2Point.x; }

			if(cur_v2Point.y > pFaces[up])
			{ pFaces[up] = cur_v2Point.y; }
		}
	}

	pV2AABB[0].x = pFaces[left];
	pV2AABB[0].y = pFaces[down];
	pV2AABB[1].x = pFaces[right];
	pV2AABB[1].y = pFaces[up];
}

Physic::Collision::~Collision()
{
	for(unsigned int i = 0; i < numOfShapes; i++) {
		delete ppShapes[i];
	}
	delete[] ppShapes;
}

void Physic::Collision::PrintState()
{
/*
	glm::mat4 matPos = translate(glm::mat4(1.0f), Position);
	glm::vec2 AABB[2] = {
		glm::vec2(matPos * glm::vec4(pVAABB[0], 0.0f, 1.0f)),
		glm::vec2(matPos * glm::vec4(pAABB[1], 0.0f, 1.0f)),
	};
	printf("AABB First Point = { %f, %f }\n", AABB[0].x, AABB[0].y);
	printf("AABB Second Point = { %f, %f }\n\n", AABB[1].x, AABB[1].y);

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

void Physic::Collision::Draw(const Camera& camera)
{
    ShRender.Draw(camera, v3Position, angle); 
    ShRender.DrawAABB(camera, pV2AABB, v3Position);
}

void Physic::Collision::BeginDraw(Graphic::Shader& coll
                                  , Graphic::Shader& aabb
                                  , Graphic::Texture2D& collTex)
{
	ShRender.Init(ppShapes, numOfShapes, pV2AABB, coll, aabb, collTex);
}

void Physic::Collision::Movement(glm::vec3 v3NewPos)
{
	v3Position = v3NewPos;
//	PrintState();
}

void Physic::Collision::Rotation(float new_angle)
{
	float delta_angle = new_angle-angle;
	angle = new_angle;
	
	glm::mat4 matRotation = glm::rotate(glm::mat4(1.0f), delta_angle,
										glm::vec3(0.0f, 0.0f, 1.0f));

	for(unsigned int i = 0; i < numOfShapes; i++) {
		Shape& cur_shape = *(ppShapes[i]);

		for(unsigned int j = 0; j < cur_shape.num_points; j++) {
			glm::vec2& cur_v2Point = cur_shape.pV2Points[j];
			cur_v2Point = glm::vec2(matRotation * glm::vec4(cur_v2Point
                                                          , 0.0f, 1.0f));
		}
	}

	find_AABB_points();
}
