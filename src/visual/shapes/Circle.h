//
// Created by alex on 03.03.22.
//

#ifndef TANO_CIRCLE_H
#define TANO_CIRCLE_H


#include "Shape.h"
#include "utils/Units.h"

namespace shape {

struct Circle : public Shape {
    float r;

    Circle(float x, float y, float r, const SDL_Color &color = {255, 255, 255, 0});

    Circle(const Vec2f &position, float r, const SDL_Color &color = {255, 255, 255, 0});

    [[nodiscard]] float getArea() const override;

    void render(const Vec2f &origin) const override;
};

}

#endif //TANO_CIRCLE_H
