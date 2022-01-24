#ifndef COORDINATE_SYSTEM_H
#define COORDINATE_SYSTEM_H

#include "../camera.h"
#include "resources.h"

namespace Graphic {

class CoordSystem : public GraphObject {
public:

    CoordSystem();

    virtual void Draw(const Camera& camera) const;

    virtual void Init();

    virtual ~CoordSystem() {}

};
}

#endif
