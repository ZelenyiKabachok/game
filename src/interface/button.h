#ifndef BUTTOM_H
#define BUTTOM_H

#include "../objects/graphic_objects.h"
#include "../objects/collision.h"

class Buttom : public Graphic::GraphObject {

    float points[2];

public:

    Buttom();

    virtual ~Buttom();


}

#endif
