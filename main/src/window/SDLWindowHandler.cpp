#include "SDLWindowHandler.hpp"

void SDLWindowHandler::Initialize() {
    const char* title = "rendalg";

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL cannot be started: % s", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, 0);
    if (window == NULL) {
        SDL_Log("window cannot be created: %s", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("renderer cannot be created: %s", SDL_GetError());
        exit(1);
    }

    SDL_RenderClear(renderer);
    SDL_Init(SDL_INIT_AUDIO);
}

void SDLWindowHandler::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDLWindowHandler::SDLWindowHandler() { 
    IsActive = true;
    Initialize();
}

SDLWindowHandler::~SDLWindowHandler() {
    Destroy();
}

void SDLWindowHandler::DrawRect(const RectData& r, const Color& c) const {
    boxRGBA(renderer, r.posx, r.posy, r.posx + r.width, r.posy + r.height,
        c.red, c.green, c.blue, c.alpha);
}

void SDLWindowHandler::RenderFrame() const {
    SDL_RenderPresent(renderer);
}

void SDLWindowHandler::ClearFrame() const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    SDL_RenderClear(renderer);
}

void SDLWindowHandler::DelayFrame(unsigned int milliseconds) const { SDL_Delay(milliseconds); }

void SDLWindowHandler::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            IsActive = false;
        }
    }
}
