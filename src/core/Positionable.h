//
// Created by alex on 05.03.22.
//

#ifndef TANO_POSITIONABLE_H
#define TANO_POSITIONABLE_H

#include "utils/Units.h"

namespace core {

class Positionable {
 protected:
    Vec2f position;

 public:
    Positionable() : Positionable(0, 0) { }

    explicit Positionable(float &&x, float &&y) : Positionable(
            Vec2f(std::forward<float>(x), std::forward<float>(y))) { }

    explicit Positionable(const Vec2f &pos) : position(pos) { }

    virtual void setPos(const float &x, const float &y) { setPos({x, y}); }

    virtual void setPos(const Vec2f &newPos) { position = newPos; }

    [[nodiscard]] float getX() const { return position.x; }

    [[nodiscard]] float getY() const { return position.y; }

    [[nodiscard]] Vec2f getPos() const { return position; }
};

}


#endif //TANO_POSITIONABLE_H
