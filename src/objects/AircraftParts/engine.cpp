#include "engine.h"

Engine::Engine(enum planeEngines name, float maxForce, float startForce, 
					float boost, float consumption, float m, float coof, 
					const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed),
				Name(name), maxThrustForce(maxForce), ThrustForce(startForce),
				boostThrFor(boost), averFuelConsumption(consumption) {}

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
