//
// Created by alex on 03.03.22.
//

#ifndef TANO_LINE_H
#define TANO_LINE_H

#include "Shape.h"
#include "utils/Units.h"

namespace shape {

/**
 * A line between two explicitly set end points.
 * The transform component inherited from shape is used as reference point for the line.
 * A.k.a. when the transform moves, the line moves as a whole.
 */
class Line : public Shape {
    Vec2f m_p1, m_p2;

    void updateBB() noexcept;

 public:
    Line(const Vec2f &point1, const Vec2f &point2, SDL_Color color = {255, 255, 255, 0}) noexcept;

    [[nodiscard]] float getArea() const override { return 0; }

    void setP1(const Vec2f &newP1);

    void setP2(const Vec2f &newP2);

    [[nodiscard]] inline Vec2f getP1() const { return m_p1; }

    [[nodiscard]] inline Vec2f getP2() const { return m_p2; }

    void render(const Vec2f &origin) const override;
};

}

#endif //TANO_LINE_H
