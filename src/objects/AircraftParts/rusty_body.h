#ifndef RUSTY_BODY_H
#define RUSTY_BODY_H

#include "../aircraft_parts.h"

namespace Aircraft {

class RustyBody : public Body {

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos); 

public:

	RustyBody(const Graphic::Shader& shader);

};
}

#endif
