//
// Created by alex on 03.03.22.
//

#ifndef TANO_LINE_H
#define TANO_LINE_H

#include "Shape.h"
#include "utils/Units.h"

namespace shape {

class Line : public Shape {
    Vec2f p1, p2;

    void updateBB() noexcept;

 public:
    Line(const Vec2f &point1, const Vec2f &point2, SDL_Color color = {255, 255, 255, 0}) noexcept;

    [[nodiscard]] float getArea() const override { return 0; }

    void setP1(const Vec2f &newP1);

    void setP2(const Vec2f &newP2);

    Vec2f getP1() const { return p1; }

    Vec2f getP2() const { return p2; }

    void render(const Vec2f &origin) const override
    {
        SDL_SetRenderDrawColor(mRenderer, UNPACK_COL(m_color));
        SDL_RenderDrawLineF(mRenderer, p1.x - origin.x, p1.y - origin.y,
                            p2.x - origin.x, p2.y - origin.y);
    };
};

}

#endif //TANO_LINE_H
