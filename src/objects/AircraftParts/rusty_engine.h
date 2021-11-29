#ifndef RUSTY_ENGINE_H
#define RUSTY_ENGINE_H

#include "../aircraft_parts.h"

namespace Aircraft {

class RustyEngine : public Engine {

	virtual void GetShapes(Physic::Shape** ppPlaneShapes, unsigned int& pos); 

public:

	RustyEngine(const Graphic::Shader& shader);

};
}

#endif
