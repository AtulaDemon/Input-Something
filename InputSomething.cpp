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
       SDL_Log("SDL_TTF init problem: %s]n", TTF_GetError());
       return;
    }

    if(IMG_Init(IMG_INIT_JPG) == 0) {
        SDL_Log("SDL_Image init problem: %s\n", IMG_GetError());
        return;
    }

    m_Window = SDL_CreateWindow ("Input Something", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_Window == 0) {
        SDL_Log("Could not create SDL Window: %s\n", SDL_GetError());
        return;
    }

    m_Renderer = SDL_CreateRenderer(m_Window,-1,SDL_RENDERER_ACCELERATED);

    if(m_Renderer == 0) {
        SDL_Log("Could not create renderer: %s\n", SDL_GetError());
        return;
    }

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);

    SDL_Surface* surface = nullptr;

    surface = IMG_Load("img\\space.jpg");

    if(surface == 0) {
        SDL_Log("Could not load surface: %s\n", IMG_GetError());
        return;
    }

    m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surface);

    if(m_Texture == 0) {
        SDL_Log("Could not create texture: %s\n", SDL_GetError());
        return;
    }

    SDL_FreeSurface(surface);

    m_Init = true;

    SDL_Log("Initialized.");
}

void InputSomething::DrawStartScreen() {
    bool isRunning = true;
    while(isRunning == true) {
        while(SDL_PollEvent(&m_Event) != 0) {
            if(m_Event.type == SDL_QUIT) {
                isRunning = false;
                break;
            } else if(m_Event.type == SDL_KEYDOWN) {
                isRunning = false;
                break;
            } else {
                break;
            }
        }

        SDL_RenderCopy(m_Renderer, m_Texture, nullptr, nullptr);
        SDL_RenderPresent(m_Renderer);
        SDL_RenderClear(m_Renderer);
    }
}

void InputSomething::Run() {
    if(m_Init == false) {
        Init();

        if(m_Init = false) {
            std::cout << "Init_Error";
            return;
        }
    }

    DrawStartScreen();

    SDL_Delay(10000);

    SDL_Log("Finished run.");
}

void InputSomething::Quit() {
    if(m_Texture != nullptr)
        SDL_DestroyTexture(m_Texture);

    if(m_Renderer != nullptr)
        SDL_RenderClear(m_Renderer);

    if(m_Renderer != nullptr)
        SDL_DestroyRenderer(m_Renderer);

    if(m_Window != nullptr)
        SDL_DestroyWindow(m_Window);

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

InputSomething::~InputSomething() {

}

