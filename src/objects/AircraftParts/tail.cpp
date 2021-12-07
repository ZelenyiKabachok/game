#include "tail.h"

Aircraft::Tail::Tail(enum planeTails name, const char* fCollis
					, float m, float coof 
					, Graphic::Shader& sh
                    , Graphic::Texture2D& tex 
					, const glm::vec3& v3Pos, const glm::vec3& v3Size
					, const glm::vec3& v3Speed)
				: PhysicObject(fCollis, m, coof, sh, tex
                             , v3Pos, v3Size, v3Speed)
				, Name(name) {}


void Aircraft::Tail::FindDirect(float alpha)
{
	DirAngle += alpha;
/*
	if(DirAngle > M_PI/2)  { DirAngle = M_PI/2; }
	if(DirAngle < -M_PI/2) { DirAngle = -M_PI/2; }

	direction.x = cos(DirAngle);
	direction.y = sin(DirAngle);
*/
}

void Aircraft::Tail::FindAngle(const glm::vec3& v3PlaneSpeed)
{
	PlaneAngle = acos((v3PlaneSpeed.x)/
	(sqrt(v3PlaneSpeed.x*v3PlaneSpeed.x + v3PlaneSpeed.y*v3PlaneSpeed.y
			  							+ v3PlaneSpeed.z*v3PlaneSpeed.z)));
	if(v3PlaneSpeed.y < 0) { PlaneAngle *= -1; }
}	
