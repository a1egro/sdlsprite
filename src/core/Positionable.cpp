//
// Created by alex on 24.06.23.
//

#include "Positionable.h"

void core::Positionable::registerCallbackPositionChanged(const std::function<void(const Vec2f &)>& onPositionChanged)
{
    m_positionChangedCallbacks.push_back(onPositionChanged);
}

void core::Positionable::setPosition(const Vec2f &newPos)
{
    if (m_locked) return;

    m_position = newPos;

    if (!m_positionChangedCallbacks.empty()) {
        for (const auto &cb: m_positionChangedCallbacks) {
            cb(newPos);
        }
    }
}
