//
// Created by alex on 29.05.22.
//

#include <sstream>
#include <SDL2/SDL_image.h>

#include "Window.h"

#include "WindowManager.h"

const Vec2i WindowManager::DEFAULT_DIMENSION = {640, 480};
const Vec2i WindowManager::DEFAULT_POSITION = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED};

WindowManager::WindowManager()
{
    // initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::stringstream ss;
        ss << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        throw std::runtime_error(ss.str());
    }

    // initialize PNG library
    int imgF = IMG_INIT_PNG;
    if (IMG_Init(imgF) != imgF) {
        std::stringstream ss;
        ss << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        throw std::runtime_error(ss.str());
    }
}

WindowManager::~WindowManager()
{
    // quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
