#ifndef COLLISIONS_EDITOR_H
#define COLLISIONS_EDITOR_H

#include "level.h"
#include "../interface/coll_edit_gui.h"
#include "../free_camera.h"
#include "object_loader.h"

class CollisionsEditor : public ILevel {

    ObjectLoader objects;
    FreeCamera *pCamera;
    GUI::CollEditGui *pInterface;
    Setting active;

public:

    CollisionsEditor() {}

    virtual void Load(const FT_Face& face, int width, int height);

	virtual void UpDate(float delta_time, const Input& input);

	virtual void Render();

	virtual ~CollisionsEditor();

};

#endif
