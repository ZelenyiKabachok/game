#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H

#include "button.h"

namespace GUI {

class ColorButton : public Button {
public:

    ColorButton(const glm::vec3& v3Pos, int screenWidth, int screenHeight);

    virtual void InitShaderData();

    virtual void ChangeState(State newState, Data& otherData, const Input& input);

    virtual ~ColorButton() {}

};
}

#endif
