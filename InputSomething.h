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
    SDL_Texture*    m_Texture;
    SDL_Event       m_Event;
    bool            m_Init;

    void            Init();
    void            DrawStartScreen();

public:
                    InputSomething();
                    ~InputSomething();

    void            Run();
    void            Quit();
};

#endif // INPUTSOMETHING_H
