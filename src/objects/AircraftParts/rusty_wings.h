#ifndef RUSTY_WINGS_H
#define RUSTY_WINGS_H

#include "../aircraft_parts.h"

class RustyWings : public Wings {

	virtual void GetShapes(Shape** const planeShapes, unsigned int& pos);

public:
	
	RustyWings(const Shader& shader);

};

#endif
