#ifndef INPUTSOMETHING_H
#define INPUTSOMETHING_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;

class InputSomething {
private:
    SDL_Window*     m_Window;
    SDL_Renderer*   m_Renderer;
    SDL_Texture*    m_Texture;
    bool            m_Init;

    void            Init();

public:
                    InputSomething();
                    ~InputSomething();

    void            Run();
    void            Quit();
};

#endif // INPUTSOMETHING_H
