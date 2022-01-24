#ifndef COLL_EDIT_GUI_H
#define COLL_EDIT_GUI_H

#include "interface.h"
#include "load_button.h"
#include "color_button.h"
#include "show_hide_button.h"

namespace GUI {

class CollEditGui : public Interface {
public:

    CollEditGui(const Graphic::GraphObject *pObjects, int size
              , const FT_Face& Face, int width, int height);

    virtual ~CollEditGui() {}

};
}

#endif
