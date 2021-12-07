#include "engine.h"

Aircraft::Engine::Engine(enum planeEngines name
					, float maxForce, const glm::vec3& v3StartForce
					, const glm::vec3& v3Pulse, float pulse
                    , float consumption 
                    , const char* fCollis, float m
					, float coof, Graphic::Shader& sh
                    , Graphic::Texture2D& tex
					, const glm::vec3& v3Pos, const glm::vec3& v3Size
					, const glm::vec3& v3Speed) 
				: PhysicObject(fCollis, m, coof, sh, tex
                             , v3Pos, v3Size, v3Speed)
				, Name(name), maxThrustForce(maxForce)
				, v3ThrustForce(v3StartForce)
				, v3PowerPulse(v3Pulse), Pulse(pulse)
				, averFuelConsumption(consumption) {}

void Aircraft::Engine::Work(const float delta_time, float angle
                                        , bool gas, bool brake)
{
	glm::mat4 matRotate = glm::rotate(glm::mat4(1.0), angle
                                        , glm::vec3(0.0, 0.0, 1.0));
	v3PowerPulse = glm::vec3(matRotate * glm::vec4(Pulse, 0.0, 0.0, 1.0));
	v3ThrustForce = glm::vec3(matRotate * glm::vec4(maxThrustForce
                                                  , 0.0, 0.0, 1.0));

	if(gas && MaxForce(delta_time)) {
		v3ThrustForce += v3PowerPulse * delta_time;
	}
	if(brake) {
		v3ThrustForce -= v3PowerPulse * delta_time;
	} 
	CalcFuelConsumption(delta_time);
	SideEffect();	
}

void Aircraft::Engine::CalcFuelConsumption(const float delta_time)
{
	fuelConsumption = 2 * averFuelConsumption * (maxThrustForce
                                                /glm::length(v3ThrustForce));
}

bool Aircraft::Engine::MaxForce(const float delta_time)
{
	return glm::length(v3ThrustForce+v3PowerPulse*delta_time) < maxThrustForce; 
}

void Aircraft::Engine::SideEffect() {}
