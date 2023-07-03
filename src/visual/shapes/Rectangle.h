//
// Created by alex on 02.03.22.
//

#ifndef TANO_RECTANGLE_H
#define TANO_RECTANGLE_H


#include "Shape.h"
#include "utils/Units.h"

namespace shape {

struct Rectangle : public Shape {
    float w, h;
    bool mFill = true;
    // TODO: fill color

 protected:
    void updateBB() const override;

 public:
    Rectangle(const Vec2f &position, float w, float h, const SDL_Color &color = {255, 255, 255});

    Rectangle(float x, float y, float w, float h, const SDL_Color &color = {255, 255, 255});

    Rectangle(const Vec2f &position, const Vec2f &dimensions, const SDL_Color &color = {255, 255, 255});

    float getWidth() const { return w; }

    float getHeight() const { return h; }

    void setWidth(const float &newWidth);

    void setHeight(const float &newHeight);

    void setFill(bool fill) { mFill = fill; }

    bool getFill() const { return mFill; }

    [[nodiscard]] float getArea() const override;

    void render(const Vec2f &origin) const override;
};

}

#endif //TANO_RECTANGLE_H
