//
// Created by alex on 02.03.22.
//

#include "Rectangle.h"

using namespace shape;

Rectangle::Rectangle(const Vec2f &position, float w, float h, const SDL_Color &color) : Shape(color), w(w), h(h) {
    this->position = position;
}

Rectangle::Rectangle(float x, float y, float w, float h, const SDL_Color &color) : Rectangle({x, y},
                                                                                             w, h,
                                                                                             color) { }

Rectangle::Rectangle(const Vec2f &position, const Vec2f &dimensions, const SDL_Color &color) : Rectangle(position,
                                                                                                         dimensions.x,
                                                                                                         dimensions.y,
                                                                                                         color) { }

void Rectangle::setPos(const Vec2f &pos) {
    Positionable::setPos(pos);
    mBbox.x = pos.x;
    mBbox.y = pos.y;
}

void Rectangle::setWidth(const float &newWidth) {
    w = newWidth;
    mBbox.w = w;
}

void Rectangle::setHeight(const float &newHeight) {
    h = newHeight;
    mBbox.h = h;
}
float Rectangle::getArea() const {
    return w*h;
}

void Rectangle::render(const Vec2f &origin) const {
    SDL_SetRenderDrawColor(mRenderer, UNPACK_COL(m_color));
    SDL_FRect r{position.x - origin.x, position.y - origin.y, w, h};

    if (mFill) {
        SDL_RenderFillRectF(mRenderer, &r);
    }
    else {
        SDL_RenderDrawRectF(mRenderer, &r);
    }
}
