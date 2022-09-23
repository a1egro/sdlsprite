//
// Created by alex on 25.01.22.
//

#ifndef TANO_GAME_H
#define TANO_GAME_H

#include <atomic>
#include <chrono>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "View.h"

class WindowManager;

// Normal View, Isometric View, Relative View
template<typename ViewType, class = std::enable_if_t<std::is_base_of_v<View, ViewType>>>
class Window {
    SDL_Window *window = nullptr;
    ViewType view;

    explicit Window(const std::string &title, const Vec2i &dim = {640, 480},
                    const Vec2i &pos = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED},
                    const SDL_WindowFlags &flags = SDL_WINDOW_SHOWN) {
        // create window and surface
        window = SDL_CreateWindow(title.c_str(), pos.y, pos.y, dim.x, dim.y, flags);
        view.init(window);
    }

    friend class WindowManager;

public:
    ~Window() {
        // destroy window
        SDL_DestroyWindow(window);
    }

    auto& getView() { return view; }

    void redraw() {
        view.clear();
        view.render();
    }
};

#endif //TANO_GAME_H
