#ifndef SHOW_HIDE_BUTTON_H
#define SHOW_HIDE_BUTTON_H

#include "button.h"

namespace GUI {

class ShowHideBut : public Button {

    const Graphic::GraphObject *pObject;    
    bool show = true;

public:

    ShowHideBut(const Graphic::GraphObject *pGrObj
              , const glm::vec3& v3Pos
              , int screenWidth, int screenHeight);

    virtual void Draw(const Camera& camera, const Character *pCharacters
                                   , unsigned int VBO, unsigned int VAO);

    virtual void ChangeState(State newState, Data& data
                                    , const Input& input);

    virtual ~ShowHideBut() {}

};
}

#endif
