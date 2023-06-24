//
// Created by alex on 08.03.22.
//

#include "maths.h"

#include <cmath>

double maths::rotFromAtoB(const Vec2f &a, const Vec2f &b)
{
    return std::atan((a.y - b.y) / (a.x - b.x)) + ((b.x < a.x) ? M_PI : 0);
}
