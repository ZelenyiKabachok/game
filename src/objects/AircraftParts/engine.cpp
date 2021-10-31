#include "engine.h"

Engine::Engine(enum planeEngines name, float maxForce, vec3 startForce, 
					vec3 boost, float boostM, float consumption, float m, 
					float coof, const Shader& sh, const Texture2D& tex, 
					const vec3& pos, const vec3& size,
					const vec3& speed) : 
				PhysicObject(m, coof, sh, tex, pos, size, speed),
				Name(name), maxThrustForce(maxForce),
				ThrustForce(startForce),
				boostThrustForce(boost), MaxBoost(boostM),
				averFuelConsumption(consumption) {}

void Engine::Work(const float delta_time, float angle, bool gas, bool brake)
{
	glm::mat4 RotateMatrix = glm::rotate(mat4(1.0), angle, vec3(0.0, 0.0, 1.0));
	boostThrustForce = vec3(RotateMatrix * glm::vec4(MaxBoost, 0.0, 0.0, 1.0));
	ThrustForce = vec3(RotatMatrix * glm::vec4(maxThrustForce, 0.0, 0.0, 1.0));

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
