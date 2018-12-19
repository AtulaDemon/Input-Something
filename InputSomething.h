#ifndef INPUTSOMETHING_H
#define INPUTSOMETHING_H

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

#include <SDL2/SDL_events.h>

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;

class InputSomething {
private:
    SDL_Window*     m_Window;
    SDL_Renderer*   m_Renderer;
    SDL_Texture*    m_Background;
    SDL_Texture*    m_Question;
    SDL_Event       m_Event;
    SDL_Rect        m_SrcRect;
    SDL_Rect        m_DesRect;
    bool            m_Init;

    void            Init();
    void            CreateTexture();
    void            DrawStartScreen();
    void            DrawQuestion();

public:
                    InputSomething();
                    ~InputSomething();

    void            Run();
    void            Quit();
};

#endif // INPUTSOMETHING_H
