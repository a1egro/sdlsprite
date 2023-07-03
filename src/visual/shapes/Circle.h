//
// Created by alex on 03.03.22.
//

#ifndef TANO_CIRCLE_H
#define TANO_CIRCLE_H


#include "Shape.h"
#include "utils/Units.h"

namespace shape {

class Circle : public Shape {
    float m_r;

 protected:
    void updateBB() const override;

 public:
    Circle(float x, float y, float r, const SDL_Color &color = {255, 255, 255, 0});

    Circle(const Vec2f &position, float r, const SDL_Color &color = {255, 255, 255, 0});

    [[nodiscard]] float getArea() const override;

    void render(const Vec2f &origin) const override;

    float getRadius() const;

    void setRadius(float r);
};

}

#endif //TANO_CIRCLE_H
