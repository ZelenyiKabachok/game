#ifndef OBJECT_LOADER_H
#define OBJECT_LOADER_H

#include <map>
#include "../objects/graphic_object.h"
#include "../objects/physical_object.h"
#include "../objects/aircraft_parts.h"

class ObjectLoader {

    std::map <const char*, Graphic::GraphObject*> graphics;
    std::map <const char*, Physic::PhysicObject*> physics;
    std::map <const char*, Aircraft::Body*> bodies;
    std::map <const char*, Aircraft::Engine*> engines;
    std::map <const char*, Aircraft::Wings*> wings;
    std::map <const char*, Aircraft::Tail*> tails;

public:

    ObjectLoader() {}

    Graphic::GraphObject* New(const char* name
                                    , Graphic::GraphObject* pObj);
    Physic::PhysicObject* New(const char* name
                                    , Physic::PhysicObject* pObj);
    Aircraft::Body* New(const char* name
                                    , Aircraft::Body* pObj);
    Aircraft::Engine* New(const char* name
                                    , Aircraft::Engine* pObj);
    Aircraft::Wings* New(const char* name
                                    , Aircraft::Wings* pObj);
    Aircraft::Tail* New(const char* name
                                    , Aircraft::Tail* pObj);
    
    void DeleteGraphic(const char* name);
    void DeletePhysic(const char* name);
    void DeleteBody(const char* name);
    void DeleteEngine(const char* name);
    void DeleteWings(const char* name);
    void DeleteTail(const char* name);

    Graphic::GraphObject* GetGraphic(const char* name);
    Physic::PhysicObject* GetPhysic(const char* name);
    Aircraft::Body* GetBody(const char* name);
    Aircraft::Engine* GetEngine(const char* name);
    Aircraft::Wings* GetWings(const char* name);
    Aircraft::Tail* GetTail(const char* name);

    ~ObjectLoader();

};

#endif
