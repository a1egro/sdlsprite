//
// Created by alex on 06.03.22.
//

#include "Line.h"

#include <cmath>

using namespace shape;

Line::Line(const Vec2f &point1, const Vec2f &point2, SDL_Color color) noexcept: Shape(color),
                                                                                m_p1(point1),
                                                                                m_p2(point2)
{
    getTransform().registerCallbackPositionChanged([this](auto &p) { updateBB(); });
}

void Line::updateBB() noexcept
{
    auto p1 = getTransform().getPosition() + getP1();
    auto p2 = getTransform().getPosition() + getP2();

    mBbox.x = fmin(p1.x, p2.x);
    mBbox.y = fmin(p1.y, p2.y);
    mBbox.w = fabs(p1.x - p2.x);
    mBbox.h = fabs(p1.y - p2.y);
}

void Line::setP1(const Vec2f &newP1)
{
    m_p1 = newP1;
    updateBB();
}

void Line::setP2(const Vec2f &newP2)
{
    m_p2 = newP2;
    updateBB();
}

void Line::render(const Vec2f &origin) const
{
    auto p1 = getTransform().getPosition() + getP1();
    auto p2 = getTransform().getPosition() + getP2();

    SDL_SetRenderDrawColor(mRenderer, UNPACK_COL(getColor()));
    SDL_RenderDrawLineF(mRenderer, p1.x - origin.x, p1.y - origin.y,
                        p2.x - origin.x, p2.y - origin.y);
}
