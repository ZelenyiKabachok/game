#include "collision_in_files.h"

bool isNumber(char letter)
{
    return (letter >= 48 && letter <= 57);
}

int getInt(const char* sCollis, unsigned int& pos)
{
    bool neg = false;
    if(sCollis[pos] == '-') { neg = true; pos++; }
    int digit = 0; 
    for(; isNumber(sCollis[pos]); pos++) {
        digit *= 10;
        digit += sCollis[pos]-48;
    }
    if(neg) { digit *= -1; } 
    return digit;
}

float getFloat(const char* sCollis, unsigned int& pos)
{
    float whole = getInt(sCollis, pos);
    pos++;
    float fractional = getInt(sCollis, pos);
    for(; fractional >= 1; fractional /= 10)
        {}
    float res;
    if(whole < 0) { res = whole-fractional; }
    else { res = whole+fractional; }
    return res;
} 

glm::vec2 readPoint(const char* sCollis, unsigned int& pos)
{
    glm::vec2 v2Point;
    v2Point.x = getFloat(sCollis, pos);
    pos++;
    v2Point.y = getFloat(sCollis, pos);
    return v2Point;
}

Physic::Shape readShape(const char* sCollis, unsigned int& pos)
{
    pos += 7; 
    int numOfPoints = getInt(sCollis, pos);
    pos++;
    glm::vec2 v2Center = readPoint(sCollis, pos);
    glm::vec2 pV2Points[numOfPoints];
    for(int points = 0; points < numOfPoints; points++) {
        pos++;
        pV2Points[points] = readPoint(sCollis, pos);
    }
    return Physic::Shape(pV2Points, v2Center, numOfPoints);
}

void printShape(const Physic::Shape& sh)
{
    printf("Center { %f; %f }\n", sh.v2Center.x, sh.v2Center.y);
    for(unsigned int i = 0; i < sh.num_points; i++) {
        printf("vec { %f; %f }\n", sh.pV2Points[i].x, sh.pV2Points[i].y);
    }
}

Physic::Collision readCollision(const char* sCollis)
{
    unsigned int pos = 9;
    int n_shapes = getInt(sCollis, pos); 
    printf("n_shapes = %d\n", n_shapes);
    Physic::Shape* pShapes[n_shapes];
    for(int num = 0; num < n_shapes; num++) {
        pos++;
        pShapes[num] = new Physic::Shape(readShape(sCollis, pos));
        printShape((*pShapes[num]));
    }
    return Physic::Collision(pShapes, n_shapes);
}
