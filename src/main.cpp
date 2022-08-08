#include "engine.hpp"

int main(int argc, const char* argv[]) {
    Engine::getInstance()->init("Nub Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
    while (Engine::getInstance()->isRunning()) {
        Engine::getInstance()->update();
    }
    Engine::getInstance()->clean();
    return 0;
}