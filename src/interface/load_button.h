#ifndef LOAD_BUTTON_H
#define LOAD_BUTTON_H

#include "button.h"

namespace GUI {

class LoadButton : public Button {
public:

    LoadButton(Graphic::Shader& shader, Graphic::Texture2D texture
                                     , const char *str, int length);
    
    void Press();

};
}

#endif
