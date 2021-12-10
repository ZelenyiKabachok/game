#ifndef COLLISIONS_EDITOR_H
#define COLLISIONS_EDITOR_H

#include "level.h"
#include "../free_camera.h"
#include "object_loader.h"

class CollisionsEditor : public ILevel {

    ObjectLoader objects;
    FreeCamera *pCamera;
    const char* sActive = "RustyEngine";

public:

    CollisionsEditor() {}

    virtual void Load();

	virtual void UpDate(float delta_time, const bool *pKeys
                , const float angle, float scroll);

	virtual void Render();

	virtual ~CollisionsEditor();

};

#endif
