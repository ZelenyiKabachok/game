#include "engine.h"

Engine::Engine(PhysicObject engine, float maxForce, float startForce,
											float boost, float consumption) :
						PhysicObject(engine), maxThrustForce(maxForce),
						ThrustForce(startForce), boostThrFor(boost),
						averFuelConsumption(consumption) {}

void Engine::Work(const float delta_time, const vec3& direct, bool gas, bool brake)
{
	boostThrustForce *= direct;
	ThrustForce *= direct;
	if(gas && MaxForce(delta_time)) {
		ThrustForce += boostThrustForce * delta_time;
	}
	if(brake) {
		ThrustForce -= boostThrustForce * delta_time;
	} 
	CalcFuelConsumption(delta_time);
	SideEffect();	
}

void Engine::CalcFuelConsumption(const float delta_time)
{
	fuelConsumption = 2 * averFuelConsumption * (maxThrustForce/glm::length(ThrustForce));
}

bool Engine::MaxForce(const float delta_time)
{
	return glm::length(ThrustForce + boostThrustForce*delta_time) < maxThrustForce; 
}

void Engine::SideEffect() {}
