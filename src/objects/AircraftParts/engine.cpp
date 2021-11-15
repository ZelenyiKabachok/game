#include "engine.h"

Engine::Engine(enum planeEngines name, unsigned int nshapes,
					float maxForce, vec3 startForce, 
					vec3 Ppulse, float pulse, float consumption, float m, 
					float coof, const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed),
				Name(name), num_shapes(nshapes), maxThrustForce(maxForce),
				ThrustForce(startForce),
				PowerPulse(Ppulse), Pulse(pulse),
				averFuelConsumption(consumption) {}

void Engine::Work(const float delta_time, float angle, bool gas, bool brake)
{
	glm::mat4 RotateMatrix = glm::rotate(mat4(1.0), angle, vec3(0.0, 0.0, 1.0));
	PowerPulse = vec3(RotateMatrix * glm::vec4(Pulse, 0.0, 0.0, 1.0));
	ThrustForce = vec3(RotateMatrix * glm::vec4(maxThrustForce, 0.0, 0.0, 1.0));

	if(gas && MaxForce(delta_time)) {
		ThrustForce += PowerPulse * delta_time;
	}
	if(brake) {
		ThrustForce -= PowerPulse * delta_time;
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
	return glm::length(ThrustForce + PowerPulse*delta_time) < maxThrustForce; 
}

void Engine::SideEffect() {}
