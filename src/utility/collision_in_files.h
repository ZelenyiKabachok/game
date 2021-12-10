#ifndef COLLISION_IN_FILES_H
#define COLLISION_IN_FILES_H

#include "../objects/collision.h"

namespace Physic {
class Collision;
}

bool isNumber(char letter);

int getInt(const char* sCollis, unsigned int& pos);

float getFloat(const char* sCollis, unsigned int& pos);

glm::vec2 readPoint(const char* sCollis, unsigned int& pos);

glm::vec2 readPoint(const char* sCollis, unsigned int& pos);

Physic::Shape readShape(const char* sCollis, unsigned int& pos);

Physic::Collision readCollision(const char* sCollis);

#endif
