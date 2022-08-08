#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine {
public:
    bool init(const char* title, int x, int y, int width, int height, Uint32 flags);
    void update();
    void clean();

    inline bool isRunning() { return running; }

    static Engine* getInstance() { return instance = (instance != nullptr) ? instance : new Engine(); }
private:
    Engine() {}
    static Engine* instance;

    bool running;

    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Event event;
};