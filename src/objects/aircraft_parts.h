#ifndef AIRCRAFT_PARTS_H
#define AIRCRAFT_PARTS_H

/*
Классы из AircraftParts, являются
дружественными к классу Plane. Все методы
этих классов, кроме конструктора и деструктора вызываются
из Plane. Унаследованны от PhysicObject.
*/

#include "../utility/resources.h"

extern ResourceManager resources;

#include "AircraftParts/body.h"
#include "AircraftParts/engine.h"
#include "AircraftParts/wings.h"
#include "AircraftParts/tail.h"

#include "AircraftParts/rusty_body.h"
#include "AircraftParts/rusty_engine.h"
#include "AircraftParts/rusty_wings.h"
#include "AircraftParts/rusty_tail.h"

#endif
