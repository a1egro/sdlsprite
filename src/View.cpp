//
// Created by alex on 6/4/22.
//

#include <iostream>
#include "View.h"

#define UNPACK_COL(col) col.r, col.g, col.b, col.a

void View::init(SDL_Window *window)
{
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    updateOrigin();

    m_renderer = SDL_GetRenderer(window);

    if (!m_renderer) {
        m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    assert(m_renderer != nullptr);
}

void View::addDrawable(const View::sPointer &drawable)
{
    assert(drawable != nullptr);
    drawable->setRenderer(m_renderer);
    m_drawables.push_back(drawable);
}

void View::removeDrawable(const View::sPointer &drawable)
{
    m_drawables.remove(drawable);
}

View::~View()
{
    // deallocate renderer
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
}

void View::resize(const int &width, const int &height)
{
    screenWidth = width;
    screenHeight = height;
    updateOrigin();
}

void View::setCenter(const Vec2f &newCenter)
{
    center = newCenter;
    updateOrigin();
}

#undef UNPACK_COL
