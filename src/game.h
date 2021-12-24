#ifndef GAME_H
#define GAME_H

#include "levels.h"
#include "utility/collision_in_files.h"
#include "utility/resources.h"
#include "objects.h"
#include "camera.h"
#include "interface/interface.h"

enum Levels { COLLISIONS_EDITOR, FIRST_LEVEL, NOTHING };

class Game {

    Input *input;    
    //GUI::Interface interface;

public:	

    Game() {}

	~Game();

	void KeyboardInput(int key, int scancode, int action, int modes);

	void MousePosition(float curX, float curY);

    void MouseButton(int button, int action, int modes);

    void ScrollInput(float yOffset);

	void Init(ILevel& level, int width, int height);

	void UpDate(float delta_time, ILevel& level);

    ILevel* ChooseLevel(GLFWwindow *pWindow, int argc, char **argv);

};

#endif
