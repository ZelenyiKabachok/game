#ifndef RUSTY_TAIL_H
#define RUSTY_TAIL_H

#include "../aircraft_parts.h"

namespace Aircraft {

class RustyTail : public Tail {

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos);

public:

	RustyTail(const Graphic::Shader& shader);

};
}

#endif
