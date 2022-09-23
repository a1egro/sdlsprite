//
// Created by alex on 06.03.22.
//

#include "Line.h"

#include <cmath>

using namespace shape;

Line::Line(const Vec2f &point1, const Vec2f &point2, SDL_Color color) noexcept : Shape(color),
                                                                              p1(point1),
                                                                              p2(point2) {
    updateBB();
}

void Line::updateBB() noexcept {
    mBbox.x = fmin(p1.x, p2.x);
    mBbox.y = fmin(p1.y, p2.y);
    mBbox.w = fabs(p1.x - p2.x);
    mBbox.h = fabs(p1.y - p2.y);

    position = { (p1.x+p2.x)/2.0f, (p1.y+p2.y)/2.0f };
}

void Line::setP1(const Vec2f &newP1) {
    p1 = newP1;
    updateBB();
}

void Line::setP2(const Vec2f &newP2) {
    p2 = newP2;
    updateBB();
}
