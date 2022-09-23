//
// Created by alex on 05.03.22.
//

#ifndef TANO_MOVABLE_H
#define TANO_MOVABLE_H

#include "Positionable.h"

namespace core {

class Movable : public Positionable {
    Vec2f velocity;

public:
    static constexpr Vec2f LEFT_1U  {-1,  0};
    static constexpr Vec2f RIGHT_1U { 1,  0};
    static constexpr Vec2f UP_1U    { 0,  1};
    static constexpr Vec2f DOWN_1U  { 0, -1};

    Movable() : velocity(0, 0) { }

    explicit Movable(const Vec2f& pos) : Positionable(pos), velocity(0, 0) { }

    virtual void setVelocity(Vec2f absVel) { velocity = absVel; }

    virtual void addVelocity(const Vec2f& relVel) { velocity += relVel; }

    void stop() { velocity = {0, 0}; }

    [[nodiscard]] Vec2f getVelocity() const { return velocity; }

    void update(float deltaT) { position += (velocity * deltaT); }
};

}

#endif //TANO_MOVABLE_H
