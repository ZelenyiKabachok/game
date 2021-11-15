#ifndef RUSTY_BODY_H
#define RUSTY_BODY_H

#include "../aircraft_parts.h"

class RustyBody : public Body {

	virtual void GetShapes(Shape** const planeShapes, unsigned int& pos); 

public:

	RustyBody(const Shader& shader);

};

#endif
