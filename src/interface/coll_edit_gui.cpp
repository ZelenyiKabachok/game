#include "coll_edit_gui.h"

GUI::CollEditGui::CollEditGui()
{
   float vertexes[] = {
      -1.0, -1.0, 0.0,     0.0, 0.0,
      -1.0,  1.0, 0.0,     0.0, 1.0,
       1.0,  1.0, 0.0,     1.0, 1.0,
       1.0, -1.0, 0.0,     1.0, 0,0
    };
    unsigned int indices[] {
        0, 1, 2,
        0, 2, 3
    };

    this->quantity = 1;
    this->ppButtons = new GUI::Button*[quantity];
    this->ppButtons[0] = new GUI::LoadButton("RustyBody"
                           , glm::vec3(-0.878, 0.94, 0.0));
    this->ppButtons[0]->initShaderData(vertexes, indices, 20, 6);
}
