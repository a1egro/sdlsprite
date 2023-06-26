//
// Created by alex on 05.03.22.
//

#ifndef TANO_POSITIONABLE_H
#define TANO_POSITIONABLE_H

#include <functional>
#include "utils/Units.h"

namespace core {

class Positionable {
 public:
    Positionable() : Positionable(0, 0) { }

    explicit Positionable(float &&x, float &&y) : Positionable(
            Vec2f(std::forward<float>(x), std::forward<float>(y))) { }

    explicit Positionable(const Vec2f &pos) : m_position(pos) { }

    virtual void setPosition(const float &x, const float &y) { setPosition({x, y}); }

    virtual void setPosition(const Vec2f &newPos);

    virtual void shift(const float &x, const float &y) { shift({x, y}); }

    virtual void shift(const Vec2f &newPos) { setPosition(m_position + newPos); }

    void registerCallbackPositionChanged(const std::function<void(const Vec2f&)>& onPositionChanged);

    void lockPosition() const { m_locked = true; }

    void unlockPosition() const { m_locked = false; }

    [[nodiscard]] inline float getX() const { return m_position.x; }

    [[nodiscard]] inline float getY() const { return m_position.y; }

    [[nodiscard]] inline Vec2f getPosition() const { return m_position; }

 private:
    Vec2f m_position;
    std::vector<std::function<void(const Vec2f&)>> m_positionChangedCallbacks;
    mutable bool m_locked = false;
};

}


#endif //TANO_POSITIONABLE_H
