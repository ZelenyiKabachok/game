#ifndef LOAD_BUTTON_H
#define LOAD_BUTTON_H

#include "button.h"

namespace GUI {

class LoadButton : public Button {
public:

    LoadButton(const String& name, glm::vec3 v3Pos);
    
    virtual void ChangeState(State newState, Setting& data);

    virtual ~LoadButton() {}

};
}

#endif
