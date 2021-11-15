#ifndef RUSTY_TAIL_H
#define RUSTY_TAIL_H

#include "../aircraft_parts.h"

class RustyTail : public Tail {

	virtual void GetShapes(Shape** const planeShapes, unsigned int& pos);

public:

	RustyTail(const Shader& shader);

};

#endif
