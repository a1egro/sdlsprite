//
// Created by alex on 02.03.22.
//

#include <iostream>
#include "Rectangle.h"

using namespace shape;

Rectangle::Rectangle(const Vec2f &position, float w, float h, const SDL_Color &color) : Shape(Vec2f(w, h), color),
                                                                                        w(w), h(h)
{
    getTransform().setPosition(position);
}

Rectangle::Rectangle(float x, float y, float w, float h, const SDL_Color &color) : Rectangle({x, y}, w, h, color) { }

Rectangle::Rectangle(const Vec2f &position, const Vec2f &dimensions, const SDL_Color &color) : Rectangle(position,
                                                                                                         dimensions.x,
                                                                                                         dimensions.y,
                                                                                                         color) { }

void Rectangle::updateBB() const
{
    mBbox.x = getTransform().getX();
    mBbox.y = getTransform().getY();
    mBbox.w = w;
    mBbox.h = h;
}

void Rectangle::setWidth(const float &newWidth)
{
    w = newWidth;
}

void Rectangle::setHeight(const float &newHeight)
{
    h = newHeight;
}

float Rectangle::getArea() const
{
    return w * h;
}

void Rectangle::render(const Vec2f &origin) const
{
    SDL_SetRenderDrawColor(mRenderer, UNPACK_COL(getColor()));
    SDL_FRect r{getTransform().getX() - origin.x, getTransform().getY() - origin.y, w, h};

    if (mFill) {
        SDL_RenderFillRectF(mRenderer, &r);
    } else {
        SDL_RenderDrawRectF(mRenderer, &r);
    }
}
