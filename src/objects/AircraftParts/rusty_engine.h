#ifndef RUSTY_ENGINE_H
#define RUSTY_ENGINE_H

#include "../aircraft_parts.h"

class RustyEngine : public Engine {

	virtual void GetShapes(Shape** const planeShapes, unsigned int& pos); 

public:

	RustyEngine(const Shader& shader);

};

#endif
