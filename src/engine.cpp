#include "engine.hpp"

Engine* Engine::instance = nullptr;

bool Engine::init(const char* title, int x, int y, int width, int height, Uint32 flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0 || !IMG_Init(IMG_INIT_PNG)) {
        std::cout << "SDL failed to initialize. Error: " << SDL_GetError() << std::endl;
        return running = false;
    }

    window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (window == nullptr) {
        std::cout << "Window failed to be created. Error: " << SDL_GetError() << std::endl;
        return running = false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << "Renderer failed to be created. Error: " << SDL_GetError() << std::endl;
        return running = false;
    }

    running = true;
}

void Engine::update() {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        running = false;
        break;
    
    default:
        break;
    }

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 204, 39, 184, 255);
    SDL_RenderPresent(renderer);
}

void Engine::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}