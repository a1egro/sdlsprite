//
// Created by alex on 6/4/22.
//

#include <iostream>
#include "View.h"

#define UNPACK_COL(col) col.r, col.g, col.b, col.a

void View::init(SDL_Window* window) {
    SDL_GetWindowSize(window, &screenWidth, &screenHeight);
    updateOrigin();

    mRenderer = SDL_GetRenderer(window);

    if (!mRenderer) {
        mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    assert(mRenderer != nullptr);
}

void View::addDrawable(const View::sPointer &drawable) {
    assert(drawable != nullptr);
    drawable->setRenderer(mRenderer);
    drawables.push_back(drawable);
}

void View::removeDrawable(const View::sPointer &drawable) {
    drawables.remove(drawable);
}

View::~View() {
    // deallocate mRenderer
    SDL_DestroyRenderer(mRenderer);
    mRenderer = nullptr;
}

void View::resize(const int &width, const int &height) {
    screenWidth = width;
    screenHeight = height;
    updateOrigin();
}

void View::setCenter(const Vec2f &newCenter) {
    center = newCenter;
    updateOrigin();
}

#undef UNPACK_COL
