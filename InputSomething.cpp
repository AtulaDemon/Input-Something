#include "InputSomething.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

InputSomething::InputSomething()
    :   m_Window(nullptr),
        m_Renderer(nullptr),
        m_Background(nullptr),
        m_Question(nullptr),
        m_Init(false),
        m_NameS("")
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

    m_Init = true;

    SDL_Log("Initialized.");
}

void InputSomething::CreateTexture() {
    SDL_Surface* surface = nullptr;

    surface = IMG_Load("img\\space.jpg");

    if(surface == nullptr) {
        SDL_Log("Could not load surface: %s\n", IMG_GetError());
        return;
    }

    m_Background = SDL_CreateTextureFromSurface(m_Renderer, surface);

    if(m_Background == 0) {
        SDL_Log("Could not create texture: %s\n", SDL_GetError());
        return;
    }

    SDL_FreeSurface(surface);
    surface = nullptr;

    SDL_Log("Background texture created");

    TTF_Font* font = nullptr;
    font = TTF_OpenFont("VeraMoBd.ttf", 30);

    if(font == nullptr) {
        SDL_Log("Could not load OpenFont: %s\n", TTF_GetError());
        return;
    }

    std::string question = "What is your name?";

    SDL_Color font_color = {250, 250, 250};

    surface = TTF_RenderText_Solid(font, question.c_str(), font_color);

    m_Question = SDL_CreateTextureFromSurface(m_Renderer, surface);

    SDL_FreeSurface(surface);

    TTF_SizeText(font, question.c_str(), &m_QsRect.w, &m_QsRect.h);
    m_QsRect.x = 200;
    m_QsRect.y = 200;

    SDL_Log("Question texture created");

    surface = TTF_RenderText_Solid(font, m_NameS.c_str(), font_color);

    m_Name = SDL_CreateTextureFromSurface(m_Renderer, surface);

    m_Hello = SDL_CreateTextureFromSurface(m_Renderer, surface);

    SDL_FreeSurface(surface);

    TTF_SizeText(font, m_NameS.c_str(), &m_NameRect.w, &m_NameRect.h);
    m_NameRect.x = 200;
    m_NameRect.y = 300;

    TTF_SizeText(font, m_NameS.c_str(), &m_HelloRect.w, &m_HelloRect.h);
    m_HelloRect.x = 200;
    m_HelloRect.y = 400;

    SDL_Log("Name and Hello texture created");
}

void InputSomething::UpdateNameTexture() {
    TTF_Font* font = nullptr;
    font = TTF_OpenFont("VeraMoBd.ttf", 30);
    if(font == nullptr) {
        SDL_Log("Could not load OpenFont: %s\n", TTF_GetError());
        return;
    }

    SDL_Color font_color = {250, 250, 250};

    SDL_Surface* surface = nullptr;
    surface = TTF_RenderText_Solid(font, m_NameS.c_str(), font_color);

    m_Name = SDL_CreateTextureFromSurface(m_Renderer, surface);

    SDL_FreeSurface(surface);

    TTF_SizeText(font, m_NameS.c_str(), &m_NameRect.w, &m_NameRect.h);
    m_NameRect.x = 200;
    m_NameRect.y = 300;
}

void InputSomething::UpdateHelloTexture() {
    TTF_Font* font = nullptr;
    font = TTF_OpenFont("VeraMoBd.ttf", 30);
    if(font == nullptr) {
        SDL_Log("Could not load OpenFont: %s\n", TTF_GetError());
        return;
    }

    std::string hello = "Hello, " + m_NameS;

    SDL_Color font_color = {250, 250, 250};

    SDL_Surface* surface = nullptr;
    surface = TTF_RenderText_Solid(font, hello.c_str(), font_color);

    m_Hello = SDL_CreateTextureFromSurface(m_Renderer, surface);

    SDL_FreeSurface(surface);

    TTF_SizeText(font, hello.c_str(), &m_HelloRect.w, &m_HelloRect.h);
    m_HelloRect.x = 200;
    m_HelloRect.y = 400;
}

void InputSomething::DrawTexture() {
        SDL_RenderCopy(m_Renderer, m_Background, nullptr, nullptr);
        SDL_RenderCopy(m_Renderer, m_Question, nullptr, &m_QsRect);
        SDL_RenderCopy(m_Renderer, m_Name, nullptr, &m_NameRect);
        SDL_RenderCopy(m_Renderer, m_Hello, nullptr, &m_HelloRect);
        SDL_RenderPresent(m_Renderer);
        SDL_RenderClear(m_Renderer);
}

void InputSomething::Run() {
    if(m_Init == false) {
        Init();

        if(m_Init = false) {
            std::cout << "Init_Error";
            return;
        }
    }
    CreateTexture();

    bool isRunning = true;

    while(isRunning == true) {
        DrawTexture();

        while(SDL_PollEvent(&m_Event) != 0) {
            if(m_Event.type == SDL_QUIT) {
                isRunning = false;
                break;
            } else if(m_Event.type == SDL_KEYDOWN) {
                if(m_Event.key.keysym.sym == SDLK_ESCAPE) {
                    isRunning = false;
                    break;
                } else if(m_Event.key.keysym.sym == SDLK_RETURN)
                    UpdateHelloTexture();
            } else if(m_Event.type == SDL_TEXTINPUT) {
                m_NameS += m_Event.text.text;
                UpdateNameTexture();
                break;
            } else {
                break;
            }
        }
    }

    SDL_Log("Finished run.");
}

void InputSomething::Quit() {
    if(m_Background != nullptr)
        SDL_DestroyTexture(m_Background);

    if(m_Question != nullptr)
        SDL_DestroyTexture(m_Question);

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

