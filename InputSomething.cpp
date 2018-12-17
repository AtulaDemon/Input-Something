#include "InputSomething.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

InputSomething::InputSomething()
    :   m_Window(nullptr),
        m_Renderer(nullptr),
        m_Texture(nullptr),
        m_Init(false)
{

}

void InputSomething::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "could not init SDL\n" << SDL_GetError();
        return;
    }

    if(TTF_Init() < 0) {
       SDL_Log("%s", TTF_GetError);
       return;
    }

    if(IMG_Init(IMG_INIT_JPG) == 0) {
        std::cout << "Could not init SDL_Image\n" << IMG_GetError();
        return;
    }

    m_Window = SDL_CreateWindow ("Input Something", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_Window == 0) {
        std::cout << "Could not create SDL Window\n";
        return;
    }

    m_Init = true;

    std::cout << "initialized";
}

void InputSomething::Run() {
    if(m_Init == false) {
        std::cout << "1" << std::endl;
        Init();

        if(m_Init = false) {
            std::cout << "Init_Error";
            return;
        }
    }

    std::cout << "HEllo" << std::endl;

    SDL_Delay(400);
}

void InputSomething::Quit() {
    if(m_Window != 0)
        SDL_DestroyWindow(m_Window);

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

InputSomething::~InputSomething() {

}

