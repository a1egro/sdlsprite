//
// Created by alex on 03.03.22.
//

#include "Circle.h"

#include <cmath>

using namespace shape;

Circle::Circle(float x, float y, float r, const SDL_Color &color) : Circle({x, y}, r, color)
{

}

Circle::Circle(const Vec2f &position, float r, const SDL_Color &color) : Shape({2*r, 2*r}, color), m_r(r)
{
    getTransform().setPosition(position);
}

float Circle::getArea() const
{
    return m_r * m_r * static_cast<float>(M_PI);
}

/// applies the midpoint algorithm as described in https://stackoverflow.com/a/48291620
void Circle::render(const Vec2f &origin) const
{
    const auto realPos = getTransform().getPosition() - origin;
    const auto diameter = m_r * 2;

    float dx = m_r - 1;
    float dy = 0;
    float tx = 1;
    float ty = 1;
    float error = tx - diameter;

    SDL_SetRenderDrawColor(mRenderer, UNPACK_COL(getColor()));

    while (dx >= dy) {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPointF(mRenderer, realPos.x + dx, realPos.y - dy);
        SDL_RenderDrawPointF(mRenderer, realPos.x + dx, realPos.y + dy);
        SDL_RenderDrawPointF(mRenderer, realPos.x - dx, realPos.y - dy);
        SDL_RenderDrawPointF(mRenderer, realPos.x - dx, realPos.y + dy);
        SDL_RenderDrawPointF(mRenderer, realPos.x + dy, realPos.y - dx);
        SDL_RenderDrawPointF(mRenderer, realPos.x + dy, realPos.y + dx);
        SDL_RenderDrawPointF(mRenderer, realPos.x - dy, realPos.y - dx);
        SDL_RenderDrawPointF(mRenderer, realPos.x - dy, realPos.y + dx);

        if (error <= 0) {
            ++dy;
            error += ty;
            ty += 2;
        } else {
            --dx;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Circle::updateBB() const
{
    mBbox.x = getTransform().getX() - m_r;
    mBbox.y = getTransform().getY() - m_r;
    mBbox.w = 2 * m_r;
    mBbox.h = 2 * m_r;
}

float Circle::getRadius() const
{
    return m_r;
}

void Circle::setRadius(float r)
{
    Circle::m_r = r;
}
