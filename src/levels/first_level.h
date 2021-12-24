#ifndef FIRST_LEVEL_H
#define FIRST_LEVEL_H

#include "level.h"
#include "../game_camera.h"
#include "../free_camera.h"
#include "object_loader.h"
#include "../interface/interface.h"

class FirstLevel : public ILevel {

	GameCamera *pCamera;
    
    ObjectLoader objects; 
    
	Physic::PCollisions CollObjects;	

	Aircraft::Plane *pPlane;
	
public:

	FirstLevel() {}

	virtual void Load(int width, int height);

	virtual void UpDate(float delta_time, const Input& input);

	virtual void Render();

	virtual ~FirstLevel();

};

#endif
