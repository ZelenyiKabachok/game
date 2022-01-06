#ifndef COLL_EDIT_GUI_H
#define COLL_EDIT_GUI_H

#include "load_button.h"
#include "interface.h"

namespace GUI {

class CollEditGui : public Interface {
public:

    CollEditGui(const FT_Face& Face, int width, int height);

    virtual ~CollEditGui() {}

};
}

#endif
