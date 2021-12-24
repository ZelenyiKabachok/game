#ifndef OBJECT_LOADER_H
#define OBJECT_LOADER_H

#include <map>
#include "../objects/graphic_object.h"
#include "../objects/physical_object.h"
#include "../objects/aircraft_parts.h"

class ObjectLoader {

    std::map <String, Graphic::GraphObject*> graphics;
    std::map <String, Physic::PhysicObject*> physics;
    std::map <String, Aircraft::Body*> bodies;
    std::map <String, Aircraft::Engine*> engines;
    std::map <String, Aircraft::Wings*> wings;
    std::map <String, Aircraft::Tail*> tails;

public:

    ObjectLoader() {}

    Graphic::GraphObject* New(const String& name
                                    , Graphic::GraphObject* pObj);
    Physic::PhysicObject* New(const String& name
                                    , Physic::PhysicObject* pObj);
    Aircraft::Body* New(const String& name
                                    , Aircraft::Body* pObj);
    Aircraft::Engine* New(const String& name
                                    , Aircraft::Engine* pObj);
    Aircraft::Wings* New(const String& name
                                    , Aircraft::Wings* pObj);
    Aircraft::Tail* New(const String& name
                                    , Aircraft::Tail* pObj);
    
    void DeleteGraphic(const String& name);
    void DeletePhysic(const String& name);
    void DeleteBody(const String& name);
    void DeleteEngine(const String& name);
    void DeleteWings(const String& name);
    void DeleteTail(const String& name);

    Graphic::GraphObject* GetGraphic(const String& name);
    Physic::PhysicObject* GetPhysic(const String& name);
    Aircraft::Body* GetBody(const String& name);
    Aircraft::Engine* GetEngine(const String& name);
    Aircraft::Wings* GetWings(const String& name);
    Aircraft::Tail* GetTail(const String& name);

    ~ObjectLoader();

};

#endif
