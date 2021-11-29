#include "list.h"
#include "list.cpp"
#include "../objects/graphic_object.h"
#include "../objects/physical_object.h"
#include "../objects/collision.h"

template class List<Graphic::GraphObject>;
template class List<Physic::PhysicObject>;
template class List<Physic::Collision>;
