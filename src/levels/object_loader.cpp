#include "object_loader.h"

Graphic::GraphObject* ObjectLoader::New(const String& name
                                      , Graphic::GraphObject* pObj)
{
    graphics[name] = pObj;
    return pObj;
}
    
Physic::PhysicObject* ObjectLoader::New(const String& name
                                       , Physic::PhysicObject* pObj)
{
    physics[name] = pObj;
    return pObj;
}

Aircraft::Body* ObjectLoader::New(const String& name, Aircraft::Body* pObj)
{
    bodies[name] = pObj;
    return pObj;
}

Aircraft::Engine* ObjectLoader::New(const String& name, Aircraft::Engine* pObj)
{
    engines[name] = pObj;
    return pObj;
}

Aircraft::Wings* ObjectLoader::New(const String& name, Aircraft::Wings* pObj)
{
    wings[name] = pObj;
    return pObj;
}

Aircraft::Tail* ObjectLoader::New(const String& name, Aircraft::Tail* pObj)
{
    tails[name] = pObj;
    return pObj;
}

void ObjectLoader::DeleteGraphic(const String& name)
{
    delete graphics[name];
    graphics.erase(name);
}
void ObjectLoader::DeletePhysic(const String& name)
{ 
    delete physics[name];
    physics.erase(name);
}
void ObjectLoader::DeleteBody(const String& name)
{ 
    delete bodies[name];
    bodies.erase(name);
}
void ObjectLoader::DeleteEngine(const String& name)
{
    delete engines[name];
    engines.erase(name);
}
void ObjectLoader::DeleteWings(const String& name)
{
    delete wings[name];
    wings.erase(name);
} 
void ObjectLoader::DeleteTail(const String& name)
{
    delete tails[name];
    tails.erase(name);
}

Graphic::GraphObject* ObjectLoader::GetGraphic(const String& name)
{ return graphics[name]; }
Physic::PhysicObject* ObjectLoader::GetPhysic(const String& name)
{ return physics[name]; }
Aircraft::Body* ObjectLoader::GetBody(const String& name)
{ return bodies[name]; }
Aircraft::Engine* ObjectLoader::GetEngine(const String& name)
{ return engines[name]; }
Aircraft::Wings* ObjectLoader::GetWings(const String& name)
{ return wings[name]; }
Aircraft::Tail* ObjectLoader::GetTail(const String& name)
{ return tails[name]; }

ObjectLoader::~ObjectLoader()
{
    for(auto item : graphics) {
        delete item.second;
    }
    for(auto item : physics) {
        delete item.second;
    }
    for(auto item : bodies) {
        delete item.second;
    }
    for(auto item : engines) {
        delete item.second;
    }
    for(auto item : wings) {
        delete item.second;
    }
    for(auto item : tails) {
        delete item.second;
    }
}
