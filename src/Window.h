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
#include <functional>
#include <map>

#include "View.h"
#include "BasicView.h"

class WindowManager;

// Normal View, Isometric View, Relative View
class Window {
 public:
    typedef core::Drawable element;
    typedef std::shared_ptr<element> sPointer;

 private:
    SDL_Window *window = nullptr;
    std::list<sPointer> m_drawables;
    std::map<std::string,View*> m_views;

    explicit Window(const std::string &title, const Vec2i &dim = {640, 480},
                    const Vec2i &pos = {SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED},
                    const SDL_WindowFlags &flags = SDL_WINDOW_SHOWN)
    {
        // create window and surface
        window = SDL_CreateWindow(title.c_str(), pos.y, pos.y, dim.x, dim.y, flags);
    }

    friend class WindowManager;

 public:
    ~Window()
    {
        // destroy window
        SDL_DestroyWindow(window);
    }

    template<typename ViewType = BasicView, class = std::enable_if_t<std::is_base_of_v<View, ViewType>>>
    ViewType &addView(const std::string &name)
    {
        if (m_views.find(name) != m_views.end())
        {
            throw std::runtime_error("View of name " + name + " already registered.");
        }

        auto view = new ViewType();
        view->init(window);
        m_views[name] = view;

        return *view;
    }

    template<typename ViewType, class = std::enable_if_t<std::is_base_of_v<View, ViewType>>>
    auto &getView(const std::string& name) { return *std::reinterpret_pointer_cast<ViewType>(m_views.at(name)); }

    auto &getView(const std::string& name) { return *m_views.at(name); }

    template<typename ViewType, class = std::enable_if_t<std::is_base_of_v<View, ViewType>>>
    const auto &getView(const std::string& name) const { return *std::reinterpret_pointer_cast<ViewType>(m_views.at(name)); }

    const auto &getView(const std::string& name) const { return *m_views.at(name); }

    SDL_Renderer* getRenderer() { return SDL_GetRenderer(window); }

    void redraw()
    {
        // clearing one view should be enough
        // TODO: clear color matters!
        m_views.begin()->second->clear();

        // render view elements
        for (const auto &viewPair: m_views) {
            viewPair.second->render();
        }

        // TODO put this in own window
        // render window elements on top
        const auto origin = Vec2f(0, 0);
        for (const auto &d: m_drawables) {
            if (!d->getHidden()) {
                d->render(origin);
            }
        }
        SDL_RenderPresent(getRenderer());
        // TODO end
    }

    void onResize(const std::function<void(Vec2i)>& callback)
    {
        // TODO
    }

    // independent of view
    void addDrawable(const sPointer& drawable)
    {
        assert(drawable != nullptr);
        drawable->setRenderer(getRenderer());
        m_drawables.push_back(drawable);
    }
};

#endif //TANO_GAME_H
