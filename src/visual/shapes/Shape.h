//
// Created by alex on 02.03.22.
//

#ifndef TANO_SHAPE_H
#define TANO_SHAPE_H

#include <SDL2/SDL_pixels.h>
#include "core/Positionable.h"
#include "core/Drawable.h"

namespace shape {

struct Shape : public core::Drawable, public core::Positionable {
    SDL_Color m_color;

    explicit Shape(const SDL_Color &color) noexcept : m_color(color) {}

    auto getColor() const { return m_color; }

    void setColor(const SDL_Color& color) { m_color = color; }

    [[nodiscard]] virtual float getArea() const = 0;

    virtual ~Shape() = default;
};

}

#endif //TANO_SHAPE_H
