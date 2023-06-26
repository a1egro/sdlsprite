//
// Created by alex on 02.03.22.
//

#ifndef TANO_SHAPE_H
#define TANO_SHAPE_H

#include <SDL2/SDL_pixels.h>
#include "core/Positionable.h"
#include "core/Drawable.h"
#include "core/Transform.h"
#include "core/GameObject.h"

namespace shape {

class Shape : public core::Drawable, public GameObject {
 public:
    explicit Shape(const SDL_Color &color, bool lock_rot = true) noexcept: m_color(color) { }

    inline auto getColor() const
    {
        return m_color;
    }

    inline void setColor(const SDL_Color &color)
    {
        m_color = color;
    }

    [[nodiscard]] virtual float getArea() const = 0;

    virtual ~Shape() = default;

 private:
    SDL_Color m_color;
};

}

#endif //TANO_SHAPE_H
