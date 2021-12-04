#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include "level.h"
#include "../game_camera.h"
#include "../free_camera.h"

class FirstLevel : public ILevel {

	GameCamera *pCamera;
    
    FreeCamera *pFCamera;

	List<Graphic::GraphObject> GrObjects;

	List<Physic::PhysicObject> PhObjects;

	Physic::PCollisions CollObjects;	

	Aircraft::Plane *pPlane;
	
public:

	FirstLevel(); 

	virtual void Load();

	virtual void UpDate(float delta_time, const bool *pKeys
                , const float angle, float scroll);

	virtual void Render();

	virtual ~FirstLevel();

};

#endif
