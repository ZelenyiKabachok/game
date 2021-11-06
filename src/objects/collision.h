#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Класс содержит форму, для которой расчитываются столкновения.
class CollisionOb {

	glm::vec2 *shape;	//Массив точек.
	glm::vec2 center;	//Центр фигуры.

	const int points;	//Количество точек.

public:
//При создании объекта CollisOb центр находится в точке (0; 0).
//Форма должна быть выпуклой.
	CollisionOb(glm::vec2 *nShape, int nPoints);

	void Change(glm::mat4 matrix);

	~CollisionOb();

};
