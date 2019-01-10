#ifndef INPUTSOMETHING_H
#define INPUTSOMETHING_H

#include <SDL2/SDL_events.h>
#include <string>

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;

class InputSomething {
private:
    SDL_Window*     m_Window;
    SDL_Renderer*   m_Renderer;
    SDL_Texture*    m_Background;
    SDL_Texture*    m_Question;
    SDL_Texture*    m_Name;
    SDL_Texture*    m_Hello;
    SDL_Event       m_Event;
    SDL_Rect        m_QsRect;
    SDL_Rect        m_NameRect;
    SDL_Rect        m_HelloRect;
    bool            m_Init;
    std::string     m_NameS;

    void            Init();
    void            CreateTexture();
    void            UpdateNameTexture();
    void            UpdateHelloTexture();
    void            DrawTexture();

public:
                    InputSomething();
                    ~InputSomething();

    void            Run();
    void            Quit();
};

#endif // INPUTSOMETHING_H
