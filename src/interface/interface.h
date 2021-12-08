#ifndef INTERFACE_H
#define INTERFACE_H

//#include "../utitily/list.h"
#include "button.h"

namespace Interface {

class Inteface {

    button *pButtons;

public:

    Interface(button *buttons, int numOfBut);

    ~Interface();

};
}

#endif
