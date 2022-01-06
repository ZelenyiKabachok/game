#ifndef CHARACTER_H
#define CHARACTER_H

#include "texture.h"
#include <glm/glm.hpp>

struct Character {
    Graphic::Texture2D texture; 
    glm::ivec2 v2Size;
    glm::ivec2 v2Bearing;
    long int advance;
};

#endif
