#include "interface.h"

void GUI::Interface::Init(const GUI::Button *pButtons, int numOfBut)
{
    quantity = numOfBut;
    ppButtons = new GUI::Button*[quantity];
    for(int i = 0; i < quantity; i++) {
        ppButtons[i] = new GUI::Button(pButtons[i]);
        ppButtons[i]->InitShaderData();
    }
}

GUI::Interface::Interface(const FT_Face& face, int width, int height)
                        : screenWidth(width), screenHeight(height)
{
    FT_Set_Pixel_Sizes(face, 0, 48);
  
    for (unsigned int c = 0; c < 256; c++) {

        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            printf("Can't load glyph\n");
            continue;
        }
 
        Graphic::Texture2D texture(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE
                                 , GL_RED, GL_RED);
        texture.Generate(face->glyph->bitmap.width, face->glyph->bitmap.rows
                       , face->glyph->bitmap.buffer);

        pCharacters[c] = Character{
            texture, 
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            face->glyph->advance.x
        };
    }

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

bool GUI::Interface::CheckMouse(const glm::vec2 *pV2Button
                              , glm::vec2 v2Mouse)
{
    v2Mouse.y = screenHeight - v2Mouse.y;
    if(v2Mouse.x < pV2Button[0].x || v2Mouse.x > pV2Button[1].x)
    { return false; }
    if(v2Mouse.y < pV2Button[0].y || v2Mouse.y > pV2Button[1].y)
    { return false; }
    return true;
}

void GUI::Interface::Render(const Camera& camera)
{
    for(int i = 0; i < quantity; i++) {
        ppButtons[i]->Draw(camera, pCharacters, VBO, VAO);
    }
}

void GUI::Interface::ChangeButtonState(GUI::Button* pButton, Data& data
                                     , GUI::State state, const Input& input)
{
    pButton->ChangeState(state, data, input);
}

void GUI::Interface::Click(const Input& input, Data& data)
{
    glm::vec2 pos(input.GetXPos(), input.GetYPos());
    for(int i = 0; i < quantity; i++) {
        if(CheckMouse(ppButtons[i]->GetCoord(), pos)) {
            if(input.MousePress()) {
                ChangeButtonState(ppButtons[i], data, GUI::PRESSED, input);
                continue;
            } else {
                ChangeButtonState(ppButtons[i], data, GUI::HOVERED, input);
                continue;
            }
        } else {
            ChangeButtonState(ppButtons[i], data, GUI::NOT_HOVERED, input);
        }
    } 
}

GUI::Interface::~Interface()
{
    for(int i = 0; i < quantity; i++) {
        delete ppButtons[i];
    }
    delete[] ppButtons;
}
