#ifndef RUSTY_WINGS_H
#define RUSTY_WINGS_H

#include "../aircraft_parts.h"

namespace Aircraft {

class RustyWings : public Wings {

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos);

public:
	
	RustyWings(const Graphic::Shader& shader);

};
}

#endif
