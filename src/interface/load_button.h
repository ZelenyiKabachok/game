#ifndef LOAD_BUTTON_H
#define LOAD_BUTTON_H

#include "button.h"

namespace GUI {

class LoadButton : public Button {
public:

    LoadButton(const Graphic::VisualString& name, const glm::vec3& v3Pos
             , int screenWidth, int screenHeight);
    
    virtual void ChangeState(State newState, Setting& data);

    virtual ~LoadButton() {}

};
}

#endif
