//
// Created by alex on 29.05.22.
//

#ifndef SDLSPRITE_WINDOWMANAGER_H
#define SDLSPRITE_WINDOWMANAGER_H

#include "Window.h"

class WindowManager {

    WindowManager();

 public:
    static auto &instance()
    {
        static WindowManager _instance;
        return _instance;
    }

    static const Vec2i DEFAULT_DIMENSION;
    static const Vec2i DEFAULT_POSITION;

    ~WindowManager();

    [[nodiscard]] std::shared_ptr<Window> makeWindow(const std::string &title,
                                                 const Vec2i &dim = DEFAULT_DIMENSION,
                                                 const Vec2i &pos = DEFAULT_POSITION,
                                                 const SDL_WindowFlags &flags = SDL_WINDOW_SHOWN) const
    {
        // not nice, but Window constructor should be private
        return std::shared_ptr<Window>(new Window(title, dim, pos, flags));
    }
};


#endif //SDLSPRITE_WINDOWMANAGER_H
