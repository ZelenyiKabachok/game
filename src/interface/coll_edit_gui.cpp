#include "coll_edit_gui.h"

GUI::CollEditGui::CollEditGui(const Graphic::GraphObject *pObjects, int size
                            , const FT_Face& face, int width, int height)
                            : Interface(face, width, height)
{
    this->quantity = 6;
    this->ppButtons = new GUI::Button*[quantity];
    this->ppButtons[0] = new GUI::LoadButton(Graphic::VisualString(
                            width, height, "RustyBody", glm::vec3(0.0)
                          , glm::vec3(1.0, 1.0, 1.0))
                          , glm::vec3(122.0, 1040.0, 0.0)
                          , width, height);
    this->ppButtons[1] = new GUI::LoadButton(Graphic::VisualString(
                            width, height, "RustyEngine"
                          , glm::vec3(10.0, 946, 0.0)
                          , glm::vec3(1.0, 1.0, 1.0))
                          , glm::vec3(122.0, 960.0, 0.0)
                          , width, height);
    this->ppButtons[2] = new GUI::LoadButton(Graphic::VisualString(
                            width, height, "RustyWings", glm::vec3(0.0)
                          , glm::vec3(1.0, 1.0, 1.0))
                          , glm::vec3(122.0, 880.0, 0.0)
                          , width, height);
    this->ppButtons[3] = new GUI::LoadButton(Graphic::VisualString(
                            width, height, "RustyTail", glm::vec3(0.0)
                          , glm::vec3(1.0, 1.0, 1.0))
                          , glm::vec3(122.0, 800.0, 0.0)
                          , width, height);

    this->ppButtons[4] = new GUI::ColorButton(glm::vec3(1880.0, 1045.0, 0.0)
                                           , width, height);

    this->ppButtons[5] = new GUI::ShowHideBut(pObjects
                                           , glm::vec3(1880.0, 980.0, 0.0)
                                           , width, height);
    this->ppButtons[0]->InitShaderData();
    this->ppButtons[1]->InitShaderData();
    this->ppButtons[2]->InitShaderData();
    this->ppButtons[3]->InitShaderData();
    this->ppButtons[4]->InitShaderData();
    this->ppButtons[5]->InitShaderData();
    
    this->ppButtons[0]->AlignText(height);
    this->ppButtons[2]->AlignText(height);
    this->ppButtons[3]->AlignText(height);
}
