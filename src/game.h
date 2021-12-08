#ifndef GAME_H
#define GAME_H

#include "input.h"
#include "levels.h"
#include "utility/resources.h"
#include "objects.h"
#include "camera.h"

enum Levels { COLLISIONS_EDITOR, FIRST_LEVEL, NOTHING };

extern const int Width;
extern const int Height;

class Game {

    Input input;    

public:	

    Game() {};

	~Game() {}

	void KeyboardInput(int key, int scancode, int action, int modes);

	void MouseInput(float curX, float curY);

    void ScrollInput(float yOffset);

	void Init(ILevel& level) const;

	void UpDate(float delta_time, ILevel& level);

    ILevel* ChooseLevel(GLFWwindow *pWindow, int argc, char **argv);

};

#endif
