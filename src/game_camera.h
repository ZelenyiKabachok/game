#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include "objects/graphic_object.h"

namespace Graphic {
class GraphObject;
}

class GameCamera : public Camera {
		
	glm::vec3 v3Speed;

    const Graphic::GraphObject* pTarget = NULL;

public:

	void FocusOnTheObject(const Graphic::GraphObject *obj);

	void CancelFocus();

	virtual void Move(float delta_time);

	GameCamera(int width, int height, const glm::vec3& v3Pos = glm::vec3(0)
             , const glm::vec3& v3Sp = glm::vec3(0));

    virtual ~GameCamera() {}
	
    void Follow(float delta_time);

	void ChangeSpeed(const glm::vec3& v3NewSpeed);

};

#endif
