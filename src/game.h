#ifndef GAME_H
#define GAME_H

#include "utility/collision_in_files.h"
#include "input.h"
#include "levels.h"
#include "utility/resources.h"
#include "objects.h"
#include "camera.h"
#include "interface/interface.h"

enum Levels { COLLISIONS_EDITOR, FIRST_LEVEL, NOTHING };

extern const int Width;
extern const int Height;

class Game {

    Input input;    
    //GUI::Interface interface;

public:	

    Game() {}

	~Game() {}

	void KeyboardInput(int key, int scancode, int action, int modes);

	void MousePosition(float curX, float curY);

    void MouseButton(int button, int action, int modes);

    void ScrollInput(float yOffset);

	void Init(ILevel& level) const;

	void UpDate(float delta_time, ILevel& level);

    ILevel* ChooseLevel(GLFWwindow *pWindow, int argc, char **argv);

};

#endif
