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

void View::addDrawable(const View::sp_drawable &drawable)
{
    assert(drawable != nullptr);
    drawable->setRenderer(m_renderer);
    m_drawables.push_back(drawable);
}

void View::removeDrawable(const View::sp_drawable &drawable)
{
    assert(drawable != nullptr);
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

void View::addClickable(const View::sp_clickable &clickable)
{
    assert(clickable != nullptr);
    m_clickable.push_back(clickable);
}

void View::removeClickable(const View::sp_clickable &clickable)
{
    assert(clickable != nullptr);
    m_clickable.remove(clickable);
}

void View::processClick(const Vec2f &position)
{
    const auto posInView = position + getOrigin();
    for (auto &clickable: m_clickable) {
        auto relPos = posInView - clickable->getTransform().getPosition();

        if (relPos.abs2() < clickable->getMaxClickDistance2() && clickable->isClicked(relPos)) {
            clickable->onClicked(relPos);
        }
    }
}

const SDL_Color &View::getClearColor() const
{
    return m_clearColor;
}

void View::setClearColor(const SDL_Color &clearColor)
{
    View::m_clearColor = clearColor;
}

#undef UNPACK_COL
