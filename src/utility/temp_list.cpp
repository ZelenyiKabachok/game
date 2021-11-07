#include "list.h"
#include "list.cpp"
#include "../objects/graphic_object.h"
#include "../objects/physical_object.h"
#include "../objects/collision.h"

template class List<GraphObject>;
template class List<PhysicObject>;
template class List<Collision>;
